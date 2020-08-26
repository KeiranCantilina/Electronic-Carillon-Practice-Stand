#include <ADS1118.h>
#include <SPI.h>


/*
  Prototype code to read velocity from a large array of
  linear Hall effect sensors read by an array of ADS1118 adcs. 
  
  Each ADS1118 consumes a max of 300uA; each SS49E sensor
  consumes max 10mA. For 50 sensors, this is a little over 500mA at 5V.
  
  This code was developed for a MIDI carillon practice stand 
  project as a way to detect baton strikes.

  TO DO: Add calibration method in this script (for setting trigger values)
*/

#define N 1 // Number of notes
#define M 1 // Number of ADS1118 boards
#define TOP 1 // Top note (in MIDI notation) of keyboard chunk
#define BOTTOM 50 // Bottom note
#define LOOP_TIME 10 // Loop delay time in ms
#define SCALING -0.3 // Scaling factor for velocity
#define DEBOUNCE_DELAY 50

// Global array of arrays
unsigned int global_array[N][3];
int pin_array[M] = {4};
int MIDI_array[N] = {0};
unsigned int trigger_values[N] = {344}; // Measured value at bottom of key travel
unsigned int max_value[N] = {958};
unsigned long last_debounce_time_array[N] = {0};
unsigned long debounceDelay = DEBOUNCE_DELAY; // or possibly loop time multiplied by some value

// Pointer to array of ADS1118 objects
ADS1118 *ads_array[M];

// Array of ADS1118 inputs (corresponding to AIN_0, AIN_1, AIN_2, AIN_3)
const uint8_t ads_inputs[] = {0b100, 0b101, 0b110, 0b111};

void setup() {
  // init global buffer 2D array
  for (int i = 0; i<3; i++){
    for (int j = 0; j<N; j++){
      global_array[j][i] = 965;
    }
  }
  
  // init midi array
  for (int i = 0; i<N; i++){
    MIDI_array[N] = BOTTOM+i;
  }
  
  // init chip select pins and set to HIGH (inactive)
  for (int i = 0; i < M; i++){
    pinMode(pin_array[i], OUTPUT);
    digitalWrite(pin_array[i],HIGH);
  }

  // Start serial stuff
  Serial.begin(57600);

  // ADS1118 Stuff (beware: dirty pointer magic below)
  
  // Loop through array for setup
  for (int i = 0; i < M; i++){
    
    // Instantiate ADS1118 objects and shove into array
    ads_array[i] = new ADS1118(pin_array[i]);

    // Initialize ADS1118 objects
    ads_array[i]->begin();

    // Set sampling rate (Available values: RATE_8SPS, RATE_16SPS, RATE_32SPS, RATE_64SPS, RATE_128SPS, RATE_250SPS, RATE_475SPS, RATE_860SPS)
    ads_array[i]->setSamplingRate(ads_array[i]->RATE_128SPS);

    // Set reference voltage full-scale range
    ads_array[i]->setFullScaleRange(ads_array[i]->FSR_4096);
    
    // Set continuous mode
    ads_array[i]->setContinuousMode();

    // Disable internal pullups
    ads_array[i]->disablePullup();

    // Example
    //ads_array[i]->getADCValue(ads_inputs[0]);
  }
}

void loop() {
  
  // init vars
  unsigned int data = 65535;
  long velocity = 0;
  double delta = 0;
  int index = 0; // For keeping track of what note we're on

  // Loop through buffers
  for (int i = 0; i<3; i++){
    index = 0;
    // Loop through reading each ADC board
    for (int j = 0; j<M; j++){
      
      // Loop through each input on each board
      for (int k = 0; k<4; k++){

        // Read value only if haven't passed the last note
        if(index < N){
          data = ads_array[j]->getADCValue(ads_inputs[k]);
          global_array[index][i] = data;
        }
        else{
          data = 65535;
        }
      
        // If a sensor value is under the threshold...
        if(data <= trigger_values[index]){

          // Calculate delta using averaged buffer values
          if (i == 2){
            delta = ((global_array[index][2]-global_array[index][1])+(global_array[index][1]-global_array[index][0]))/2;
          }
          else if (i == 1){
            delta = ((global_array[index][1]-global_array[index][0])+(global_array[index][0]-global_array[index][2]))/2;
          }
          else if (i == 0){
            delta = ((global_array[index][0]-global_array[index][2])+(global_array[index][2]-global_array[index][1]))/2;
          }

          // If the delta is greater than minimum delta (default 0), map delta to velocity
          if ((delta<-1) && ((millis()-last_debounce_time_array[index])>debounceDelay)){
            // Get current time for debouncing
            last_debounce_time_array[index]= millis();
            velocity = delta*SCALING;
            if(velocity>127){velocity = 127;}
            //Serial.println(String(velocity)+","+String(global_array[index][0])+","+String(global_array[index][1])+","+String(global_array[index][2]));

            // Then play the triggered note with the measured velocity
            playNote(/*MIDI_array[index]*/0x32, velocity);
          }
        }

        // Increment index (so we know what note we're on)
        index++;
      }
    }

    // Wait before moving on to the next buffer (to allow time for baton to move)
    delay(LOOP_TIME);
  }
}

// Function for playing a carillon MIDI note (on then immediately off)
void playNote(int note, int volume){
  noteOn(0x90, note, volume);
  noteOn(0x90, note, 0x00);
}

// Function for building and sending MIDI messages over the serial interface 
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

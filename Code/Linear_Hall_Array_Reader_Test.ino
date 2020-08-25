//#include <ardumidi.h>

/*
  Prototype code to read velocity from a large array of
  linear Hall effect sensors. This code was developed for
  a MIDI carillon practice stand project as a way to detect
  baton strikes.

  TO DO: Add calibration method in this script (for setting trigger values)
*/

#define N 1 // Keyboard chunk size (ie. number of notes)
#define TOP 1 // Top note (in MIDI notation) of keyboard chunk
#define BOTTOM 50 // Bottom note
#define LOOP_TIME 10 // Loop delay time in ms
#define SCALING -0.3 // Scaling factor for velocity
#define CHANNEL 0x90 // MIDI channel
#define DEBOUNCE_DELAY 50

// Global array of arrays
int global_array[N][3];
int pin_array[N] = {24};
int MIDI_array[N] = {0};
int trigger_values[N] = {344};
int max_value[N] = {958};
unsigned long last_debounce_time_array[N] = {0};
unsigned long debounceDelay = DEBOUNCE_DELAY; // or possibly loop time multiplied by some value

void setup() {
  // init global array
  for (int i = 0; i<3; i++){
    for (int j = 0; j<N; j++){
      global_array[j][i] = 965;
    }
  }
  
  // init midi array
  for (int i = 0; i<N; i++){
    MIDI_array[N] = BOTTOM+i;
  }

  // Init Vref
  analogReference(INTERNAL2V56);
  
  // init pins
  for (int i = 0; i < N; i++){
    pinMode(pin_array[i], INPUT);
    // Dunno if pullups are needed (no)
  }

  // Start serial stuff
  Serial.begin(57600);
}

void loop() {
  
  // init vars
  int data = 1024;
  int velocity = 0;
  double delta = 0;

  // Loop through buffers
  for (int i = 0; i<3; i++){
    
    // Loop through reading each sensor
    for (int j = 0; j<N; j++){
      data = analogRead(j);
      global_array[j][i] = data;
      
      // If a sensor value is under the threshold...
      if(data <= trigger_values[j]){

        // Calculate delta using averaged buffer values
        if (i == 2){
          delta = ((global_array[j][2]-global_array[j][1])+(global_array[j][1]-global_array[j][0]))/2;
        }
        else if (i == 1){
          delta = ((global_array[j][1]-global_array[j][0])+(global_array[j][0]-global_array[j][2]))/2;
        }
        else if (i == 0){
          delta = ((global_array[j][0]-global_array[j][2])+(global_array[j][2]-global_array[j][1]))/2;
        }

        // If the delta is greater than minimum delta (default 0), map delta to velocity
        if ((delta<-1) && ((millis()-last_debounce_time_array[j])>debounceDelay)){
          // Get current time for debouncing
          last_debounce_time_array[j]= millis();
          velocity = delta*SCALING;
          if(velocity>127){velocity = 127;}
          //Serial.println(String(velocity)+","+String(global_array[0][0])+","+String(global_array[0][1])+","+String(global_array[0][2]));

          // Then play the triggered note with the measured velocity
          playNote(/*MIDI_array[j]*/0x32, velocity);
        }
      }
    }

    // Wait before moving on to the next buffer (to allow time for baton to move)
    delay(LOOP_TIME/N);
    //Serial.println(String(analogRead(24)));
  }
}

// Function for playing a carillon MIDI note (on then immediately off)
void playNote(int note, int volume){
  noteOn(CHANNEL, note, volume);
  noteOn(CHANNEL, note, 0x00);
}

// Function for building and sending MIDI messages over the serial interface 
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

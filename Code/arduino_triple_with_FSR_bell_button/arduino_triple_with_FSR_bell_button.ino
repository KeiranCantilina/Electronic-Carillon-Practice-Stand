int button1Input = 5;
int button2Input = 4;
int button3Input = A3;
int button1State = 0;
int button2State = 0;
int button3State = 0;
int button3Pressure = analogRead(A3);
int fsrValue = 4;
int i = 0;
int j = 0;
int k = 0;
void setup() {
  //  Set MIDI baud rate:
  pinMode(button1Input, INPUT);
  digitalWrite(button1Input, HIGH);
  pinMode(button2Input, INPUT);
  digitalWrite(button2Input, HIGH);
  pinMode(button3Input, INPUT);
  
  Serial.begin(57600);
}

void loop() {
  button1State = digitalRead(button1Input);
  button2State = digitalRead(button2Input);
  button3Pressure = analogRead(button3Input);
  button3State = digitalRead(button3Input);
  fsrValue = map(button3Pressure, 1023, 200, 1, 127);
  if (fsrValue>127){
    fsrValue = 127;
  }
  
    //Button 1
    if(button1State != HIGH&i==0){
    noteOn(0x90, 0x32, 0x45); // Midi 50 (D3)
    noteOn(0x90, 0x32, 0x00); // Off
    i = 1;
    }

    //Button 2
    if(button2State != HIGH&j==0){
    noteOn(0x90, 0x42, 0x45); // Midi 66 (F#3)
    noteOn(0x90, 0x42, 0x00); // Off
    j = 1;
    }

    //Button 3
    if(button3State != HIGH&k==0){
    noteOn(0x90, 0x32, fsrValue); // Midi 69 (G#3)
    noteOn(0x90, 0x32, 0x00); // Off
    k = 1;
    }

    
    //Oneshot
    if(button1State == HIGH){
      i = 0;
    }
    if(button2State == HIGH){
      j = 0;
    }
    if(button3State == HIGH){
      k = 0;
    }
    //Bounce-reject to prevent redundant midi signals  

    delay(20);
}



//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

int buttonInput = 5;
int buttonState = 0;
int i = 0;
void setup() {
  //  Set MIDI baud rate:
  pinMode(buttonInput, INPUT);
  digitalWrite(buttonInput, HIGH);
  Serial.begin(57600);
}

void loop() {
  buttonState = digitalRead(buttonInput);

    if(buttonState != HIGH&i==0){
    noteOn(0x90, 0x32, 0x45);
    delay(100);
    noteOn(0x90, 0x32, 0x00);
    i = 1;
    }
    if(buttonState == HIGH){
      i = 0;
    }

}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

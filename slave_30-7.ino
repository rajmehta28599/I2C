#include <Wire.h>
int x = 0;
int y = 0,f=0;

void setup() {
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9);
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void loop() {
  Serial.println(x);
  y++;
  if (x == 19)
  {
    Wire.beginTransmission(3);
    Wire.write(y);
    Wire.write(50);
    Wire.endTransmission();
  }


}


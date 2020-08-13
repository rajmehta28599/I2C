#include <Wire.h>

int x = 0;
int y = 0;

void setup() {
  // Start the I2C Bus as Master
  Wire.begin(3);
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  y = Wire.read();
}

void loop() {
  Serial.print("x= ");
  Serial.print(x);
  Serial.print("y= ");
  Serial.println(y);

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(19);              // sends x
  Wire.endTransmission();    // stop transmitting


}


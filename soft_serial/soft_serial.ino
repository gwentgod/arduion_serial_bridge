#include <SoftwareSerial.h>


SoftwareSerial softSerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(115200);
  softSerial.begin(115200);
  while (!Serial) {} // wait for serial port to connect. Needed for Native USB only
}


void loop()
{
  if (softSerial.available())
    Serial.println(softSerial.read(), HEX);
  if (Serial.available())
    softSerial.write(Serial.read());
}

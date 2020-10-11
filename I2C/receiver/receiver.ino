#include <Wire.h>

const int I2C_SLAVE_ADDRESS = 0x04;

void setup() {
  Serial.begin(9600);
  Wire.begin(I2C_SLAVE_ADDRESS);
  Wire.onReceive(onRecv);
  Serial.print("STARTUP --- OUT\n");
}

void loop() {
}

static char gBuf[255];

void onRecv(int inNumOfRecvBytes) {
  sprintf(gBuf, "NumOfBytes=%d : ", inNumOfRecvBytes);
  Serial.print(gBuf);

  while(Wire.available() > 0) {
    unsigned char c = Wire.read();
    sprintf(gBuf, "%02x ", c) ;
    Serial.print(gBuf);
  }
  Serial.print("\n");
}

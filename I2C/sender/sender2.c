// gcc sender2.c -lwiringPi
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>

int main(int argc, char *argv[]) {
  if (wiringPiSetup() < 0) {
    fprintf(stderr, "Error: can not init wiringPi.\n");
    return -1;
  }

  if (argc < 5) {
    fprintf(stderr, "Usage: sender address data1 data2 ... dataN\n");
    fprintf(stderr, "ex) sender 04 CA FE DE AD BE EF\n");
    return -1;
  }

  int i2cAddr;
  sscanf(argv[1], "%02x", &i2cAddr);
  printf("address=0x%02X[=%d]\n", i2cAddr, i2cAddr);

  const int numOfBuf = argc - 2;
  char buf[numOfBuf];
  printf("data to be sent: ");
  for (int i = 2, j = 0; i < argc; i++, j++) {
    int t;
    sscanf(argv[i], "%02x", &t);
    buf[j] = (unsigned char)t;
    printf("%02X", t);
  }
  printf("\n");

  int handle = wiringPiI2CSetup(i2cAddr);
  if (handle < 0) {
    fprintf(stderr, "Error: Can not open I2C device(0x%02X).\n", i2cAddr);
    return -1;
  }

  int result = write(handle, buf, numOfBuf);
  if (result != numOfBuf) {
    fprintf(stderr, "Error: can not send data.\n");
    fprintf(stderr, "result=%d\n", result);
    if (result < 0) {
      fprintf(stderr, "%s\n", strerror(errno));
    }
    return -1;
  }

  if (close(handle)) {
    fprintf(stderr, "Error: can not close I2C.\n");
    fprintf(stderr, "%s\n", strerror(errno));
    return -1;
  }
  return 0;
}

// gcc sender3.c -lpigpio -lpthread
#include <stdio.h>
#include <pigpio.h>

int main(int argc, char *argv[]) {
  if (gpioInitialise() < 0) {
    fprintf(stderr, "Error: can not initialize pigpio.\n");
    return -1;
  }
  if (argc < 5) {
    fprintf(stderr, "Usage: sender i2cBus address reg data1 data2 ... dataN\n");
    fprintf(stderr, "ex) sender 1 04 12 CA FE DE AD BE EF\n");
    return -1;
  }
  int device;
  sscanf(argv[1], "%d", &device);
  printf("device=/dev/i2c-%d\n", device);

  int i2cAddr;
  sscanf(argv[2], "%02x", &i2cAddr);
  printf("address=0x%02X[=%d]\n", i2cAddr, i2cAddr);

  int reg;
  sscanf(argv[3], "%02x", &reg);
  printf("register=0x%02X[=%d]\n", reg, reg);

  const int numOfBuf = argc - 4;
  char buf[numOfBuf];
  printf("data to be sent: ");
  for (int i = 4, j = 0; i < argc; i++, j++) {
    int t;
    sscanf(argv[i], "%02x", &t);
    buf[j] = (unsigned char)t;
    printf("%02X", t);
  }
  printf("\n");

  int handle = i2cOpen(device, i2cAddr, 0);
  if (handle < 0) {
    fprintf(stderr, "Error: Can not open I2C.\n");
    return -1;
  }

  int result = i2cWriteI2CBlockData(handle, reg, buf, numOfBuf);
  if (result) {
    fprintf(stderr, "Error: can not send data.\n");
    fprintf(stderr, "result=%d\n", result);
    switch (result) {
    case PI_BAD_HANDLE:
      fprintf(stderr, "BAD HANDLE\n");
      break;
    case PI_BAD_PARAM:
      fprintf(stderr, "BAD PARAM\n");
      break;
    case PI_I2C_WRITE_FAILED:
      fprintf(stderr, "WRITE FAILED\n");
      break;
    default:
      fprintf(stderr, "UNKNOWN\n");
    }
    return -1;
  }

  if (i2cClose(handle)) {
    fprintf(stderr, "Error: can not close I2C.\n");
    return -1;
  }
  return 0;
}

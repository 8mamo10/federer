// gcc sender.c -lwiringPi
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>
#include <wiringPiI2C.h>

int main() {
  if (wiringPiSetup() < 0) {
    fprintf(stderr, "Error: can not init wiringPi.\n");
    fprintf(stderr, "errno=%d", errno);
    fprintf(stderr, "%s=n", strerror(errno));
    return -1;
  }

  int addr;
  printf("input target addr: ");
  scanf("%02x", &addr);
  printf("TARGET Addr=0x%02X[=%d]\n", addr, addr);

  int fd = wiringPiI2CSetup(addr);
  if (fd < 0) {
    fprintf(stderr, "Error: Can not start to communicate I2C device %0x02X.\n", addr);
    return -1;
  }

  int reg;
  printf("input target reg: ");
  scanf("%02x", &reg);
  printf("TARGET Reg=0x%02X[=%d]\n", reg, reg);

  int data;
  printf("input send data (16bit): ");
  scanf("%04x", &data);
  printf("SEND Data=0x%04X[=%d]\n", data, data);
  data = (data&0xFF)*0x100 + ((data>>8) & 0xFF);

  int result = wiringPiI2CWriteReg16(fd, reg, data);
  if (result < 0) {
    fprintf(stderr, "Error: can not write to the target.\n");
    fprintf(stderr, "errno=%d", errno);
    fprintf(stderr, "%s=n", strerror(errno));
    return -1;
  }

  return 0;
}

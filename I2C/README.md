# I2C

## Cabling
- Connect each of them
  - SDA
  - SCL
  - GND

## Arduino UNO R3
- https://content.arduino.cc/assets/Pinout-UNOrev3_latest.pdf

## Raspberry Pi Zero WH
- https://www.raspberrypi.org/documentation/usage/gpio/README.md

```
$ sudo raspi-config
```

- 5 Interfacing Options
- P5 I2C
- Would you like the ARM I2C interface to be enabled?
- Yes

```
$ sudo reboot
```

```
$ ls /dev/i2c*
/dev/i2c-1
$ i2cdetect -y 1
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- 04 -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --
```

```
$ i2cset -y 1 0x04 0xDE 0xAD 0xBE 0xEF 0x12 0x34 i
```

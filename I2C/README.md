# I2C

## Cabling
- Connect each of them
  - SDA
  - SCL
  - GND

## Arduino UNO R3

## Raspberry Pi Zero WH
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
$ i2cdetect -y 1
```




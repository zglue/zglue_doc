[TOC]

## Summary

zDK Y-modem Receiver is based on Y-modem protocol and over UART or USB-Serial. Now the feature included:

1. receiving file over UART or USB-Serial;
2. save file into RAM or external flash;

This feature can be used as image upgrade . The receiver image can be stored into /dev/mtdblock4 as

the new image . If you want to use as image upgrade , please co-use it with bootloader.



## Y-modem Receiver Image Build

1. Build Y-modem Receiver

```
$ cd configs/nrf52840_dk
$ make distclean; make ymodem_receiver 
# Finally, this will generate nuttx, nuttx.bin,nuttx.hex.
$ nrfjprog -e; nrfjprog --program nuttx.hex 
# this will program ymodem image into internal flash
```

1. Comment:

   1. the default it over usb-serial port, the USB-Serial only work on DEV board of Zglue. The UART-1 can

      work from PCA10056 board.

   2. if you want to use UART , please CONFIG_YMODEM_RECEIVER_SOURCE_DEVICE="/dev/ttyS1"

      and make sure the second UART has been enabled



## Y-modem Receiver Usage

After flashing image into Dev board

1. enable USB-Serial by command sercon

```sh
nsh>sercon
sercon: Registering CDC/ACM serial driver
nrf52_usbd_monitor: psercon: Successfully registered the CDC/ACM serial driver
```

2. enable ymodem_receiver

```shell
nsh>ymodem_receiver
ymodem_receiver>start	
```

​		

​      Comment: the default file path is /dev/mtdblock4,  you can change it by  "start  file_path"

3. start transfer file by SecureCRT. The default baudrate  is 115200bps, 8N1

```
SecureCRT  menu  --->Transfer --->Send Ymodem
```


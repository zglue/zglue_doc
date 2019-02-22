[TOC]

# OTA Demo

image layerout:

| Name                     | Address              | Comment         |
| ------------------------ | -------------------- | --------------- |
| bootloader               | 0 ---- 0xFFFF        | size is 0x10000 |
| application image        | 0x10000 ---- 0x43FFF | size is 0x34000 |
| second application image | 0x44000 ---- 0x77FFF | size is 0x34000 |
| other data or app data   | 0x78000 ---- 0x79FFF | size is 8*1024  |

If you change the image layer , please make it  matched between bootloader and application



## Step 1 build bootloader 

```sh
$ make distclean
$./tools/configure.sh -a ../apps zglue_zeus2_chicago/boot
$make
#Finally, it will generate bootloader image , 
#you should save it (nuttx, nuttx.bin, nuttx.hex)
# flash image into DevKit
$nrfjprog -e
$nrfjprog --program nuttx.hex
$nrfjprog -r
```



## Step 2 build First application image

```sh
$ make distclean
$./tools/configure.sh -a ../apps zglue_zeus2_chicago/app_nimble
$make _BUILD_VERSION_=1234
#Finally, it will generate bootloader image , 
#you should save it (nuttx, nuttx.bin, nuttx.hex)

# do image signature by script, it will generate signed image (nuttx.sign.bin, nuttx.sign.hex)
$IMG_VERSION=1.0.0 ./sign_img.sh 

# flash signed application image into DevKit
$nrfjprog -erasepage 0x10000-0x34000
$nrfjprog --program nuttx.sign.hex
$nrfjprog -r
```

After system reboot , you will get ble application running and FIRMWARE VERSION output information.

(firmware version should be "1234")

## Step 3 build Second appliation image for OTA

```sh
$ make distclean
$./tools/configure.sh -a ../apps zglue_zeus2_chicago/app_nimble
$make _BUILD_VERSION_=5678
#Finally, it will generate bootloader image , 
#you should save it (nuttx, nuttx.bin, nuttx.hex)

# do image signature by script, it will generate signed image (nuttx.sign.bin, nuttx.sign.hex)
$IMG_VERSION=2.0.0  IMG_START=0x44000 ./sign_img.sh 

# flash signed application image into DevKit
$nrfjprog -erasepage 0x44000-0x78000
$nrfjprog --program nuttx.sign.hex
$nrfjprog -r
```

After system reboot , you will get ble application running and FIRMWARE VERSION output information.

(firmware version should be "5678")
# zDK Bootloader Guide

[TOC]

## Summary

zDK bootloader is based on [mcuboot](http://mcuboot.com/) & [mbedtls](https://tls.mbed.org/) library. Now the feature includs:
1. boot an application from internal flash;
2. support RSA, ECDSA signature;
3. Image upgrade between master image with secondary image;
4. The second image can stay in internal flash or external SPI/QSPI flash.

  When The second image is located in external SPI flash, please make sure the external flash sector  

  size is equal to internal flash erase sector size.



## Bootloader Image Build

1. Build bootloader

```sh
$ cd configs/nrf52840_dk
$ make distclean; make boot 
# Finally, this will generate nuttx, nuttx.bin,nuttx.hex.
$ nrfjprog -e; nrfjprog --program nuttx.hex 
# this will program bootloader into internal flash
```

2. Comment:
   1. the *CONFIG_MCUBOOT_APP_IMAGE_OFFSET* of bootloader config should be equal with   

       *CONFIG_FLASH_ORIGIN* of app_nsh config;

   2. the *CONFIG_MCUBOOT_APP_IMAGE_MAX_SIZE* of bootloader config should be equal with   

      *CONFIG_FLASH_LENGTH* of app_nsh config;

   3. the *MCUBOOT_SECOND_IMAGE_INTERNAL* or *MCUBOOT_SECOND_IMAGE_QSPI* will   

      select the
      second image location;


## Application Image Build

build application

```sh
$ cd configs/nrf52840_dk
$ make distclean; make app_nsh
```



## Application Image Signature

1. **Default**: the IMG_START of offset from flash and IMG_LEN of total image length is reading   

   from
   .config (*CONFIG_FLASH_ORIGIN* , *CONFIG_FLASH_LENGTH*)

```sh
$./sign_img.sh  
# default it  will read nuttx.bin and generate nuttx.sign.hex, nuttx.sign.bin
# nuttx.sign.bin is the signed image
$ nrfjprog  --program nuttx.sign.hex
```

2. sign the second image , if the second image is located in flash *0x00060000*

```sh
$ IMG_START=0x60000 ./sign_img.sh
$ nrfjprog  --program nuttx.sign.hex
```

3. sign the second image which is located in external qspi flash

```sh
$ IMG_START=0x12000000 ./sign_img.sh
```

This is because the QSPI XIP base address is *0x12000000* for NRF52840

```sh
$ nrfjprog --program nuttx.sign.hex  --qspichiperase
# this command will program application into external qspi flash
```

sign_img.sh Usage:  

　　export IMG_VERSION=x.x.x+xxx  
　　version is major.minus.rev+build  
　　option:  
　　　　export IMG_START=xxxxx  
　　　　　　　this is the location of image in flash  
　　　　export IMG_LEN=xxxx  
　　　　　　this is the total length of signed image  

　　./sign_img.sh [ private_key.pem ]



## Application Upgrade Process

1. build two image with different version, one is located in *0x20000*, another is programed on *0x60000* ,   

   assume the max of image length is *0x40000* . 

2. use nrfjprog command to program first images into internal flash

3. boot up board

4. nrfjprog --erasepage *0x60000*-*0xa0000*

5. nrfjprog --program  second.sign.hex

6. reboot board,  you will get second image boot information



## Creating Customizing signing keys
First you need a keypair to use for signing. You can create
one with openssl command line tool.

```sh
$ openssl genrsa -out image_sign.pem 2048
```

This created a file which contains both the private and public key,
and will be used when signing images.

Then you need to extract the public key from this to include it
in the bootloader. Bootloader need to keep key parsing minimal,
so it expects simple key format.

```sh
$ openssl rsa -in image_sign.pem -pubout -out image_sign_pub.der -outform DER -RSAPublicKey_out
```

Now the public key is in file called image_sign_pub.der.

For ECDSA224 these commands are similar.

```shell
$ openssl ecparam -name secp224r1 -genkey -noout -out image_sign.pem
$ openssl ec -in image_sign.pem -pubout -outform DER -out image_sign_pub.der
```

And then the ECDSA256.

```shell
$ openssl ecparam -name prime256v1 -genkey -noout -out image_sign.pem
$ openssl ec -in image_sign.pem -pubout -outform DER -out image_sign_pub.der
```



## Creating a key package

```shell
$ xxd -i image_sign_pub.der image_sign_pub.c.import
```

Then, you can replace the key context in  external/mcuboot/nuttx/src/nuttx_key.c



## Booting Diagram

```flow
st=>start: Bootup
cond_img_hdr=>condition: Check Imager Header
cond_swap=>condition: New Image
op_swap=>operation: Swaping Image
cond_img_valid=>condition: Image Signature?
e_sucess=>end: Sucess Booting
e_fail=>end: Fail

st->cond_img_hdr
cond_img_hdr(yes)->cond_swap
cond_img_hdr(no)->e_fail
cond_swap(yes)->op_swap
cond_swap(no)->cond_img_valid
op_swap->cond_img_valid
cond_img_valid(yes)->e_sucess
cond_img_valid(no)->e_fail

```








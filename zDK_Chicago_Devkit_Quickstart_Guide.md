# zDK Chicago Dev kit quick start guide

## Hardware requirements

1) Chicago dev kit connected to PC through USB
2) Segger JTAG connected to 20 pin JTAG header and PC

## Software requirements

1) firmware repository (zCAD link)
2) Nordic firmware download tools
http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.tools%2Fdita%2Ftools%2Fnrf5x_command_line_tools%2Fnrf5x_installation.html
3) firmware environment setup.Please follow steps in the zDK Linux Environment Setup guide before continue
4) Serial terminal program 
download Tera Term From https://osdn.net/projects/ttssh2/ (Windows only)

## Firmware Download procedure

Follow the installation and setup from step 2 in software requirements. Following are commands to download firmware

```shell
$ nrfjprog -e
$ nrfjprog -f NRF52 FW_File_name.hex
$ nrfjprog -r
```

## Terminal settings
![tera_term_setting](https://github.com/zglue/zglue_doc/blob/master/zmodem_option/tera_term_setting.png)


## Building examples

Please be in the top directory of the firmware folder.Compiled firmware
outputs nuttx.hex and nuttx.bin are located in the /nuttx folder

## Example 1 : Blinky

Description : This example blinks the LED2 of the zglue smartfabric

```shell
$cd nuttx/configs/zglue_zeus2_chicago
$make blinky
$cd ..
$cd ..
```

## Example 2 : hello world

Description : This example prints "Hello world" on the UART terminal

```shell
$cd nuttx/configs/zglue_zeus2_chicago
$make hello
$cd ..
$cd ..
```

## Example 3 : nsh with nimble(ble peripheral example).

Description : This example runs Nuttx shell(nsh) from which you can 
launch other applications. Application include
1) BLE peripheral example
2) zGlue smartfabric configuration
3) BQ25120a PMIC
4) MC3672 mcube accelerometer
5) BMM150 Bosch magnetometer
6) TMP108 TI temperature sensor

```shell
$cd nuttx/configs/zglue_zeus2_chicago
$make dev_kit
$cd ..
$cd ..
```




# zDK Chicago Dev kit quick start guide

## Hardware requirements

1) Chicago dev kit connect to PC through USB
2) Segger JTAG connected to 20 pin JTAG header

## Software requirements

1) FW repository downloaded
2) Nordic fw download tools
http://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.tools%2Fdita%2Ftools%2Fnrf5x_command_line_tools%2Fnrf5x_installation.html
3) FW environment setup.Please follow steps in the zDK Linux Environment Setup guide before continue


## FW download

Follow the installation and setup from step 2 in software requirements. Following are commands to download FW

```shell
$ nrfjprog -e
$ nrfjprog -f NRF52 FW_File_name.hex
$ nrfjprog -r
```


## Building examples

Please be in the top directory of the FW folder.

## Example 1 : Blinky

```shell
$cd nuttx/configs/zglue_zeus2_chicago
$make blinky
$cd ..
$cd ..
```

Current folder nuttx.hex and nuttx.bin.

## Example 2 : hello

```shell
$cd nuttx/configs/zglue_zeus2_chicago
$make hello
$cd ..
$cd ..
```

Current folder contains nuttx.hex and nuttx.bin.

## Example 3 : nsh with nimble(ble example). Nuttx runs a terminal shell through which you can
launch other applications

```shell
$cd nuttx/configs/zglue_zeus2_chicago
$make dev_kit
$cd ..
$cd ..
```

For UART settings, use the same settings in the document Z-modem-Transfer-File-between-dev-board-and-PC

Current nuttx contains nuttx.hex and nuttx.bin.




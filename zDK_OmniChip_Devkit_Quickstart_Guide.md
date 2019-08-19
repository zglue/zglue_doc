# zDK OmniChip Dev kit quick start guide

## Hardware requirements

1) OmniChip dev kit connected to PC through USB
2) Segger JTAG connected to 20 pin JTAG header and PC
3) FTDI breakout board (https://www.sparkfun.com/products/9873)

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
$ nrfjprog -f NRF52 --program FW_File_name.hex
$ nrfjprog -r
```

## Terminal setup and settings

1) Connect pin UART_RX from the devkit to TXD pin of the FTDI breakout board
2) Connect ping UART_TX from the devkit to the RXD pin of the FTDI breakout board

Set up the terminal program with the following settings

![tera_term_setting](https://github.com/zglue/zglue_doc/blob/master/zmodem_option/tera_term_setting.png)


## Building examples

Please be in the top directory of the firmware folder.Compiled firmware
outputs nuttx.hex and nuttx.bin are located in the /nuttx folder

## Example 1 : Blinky

Description : This example blinks the LED2 of the zglue smartfabric.  
If you are running on Linux:
```shell
$cd nuttx/configs/zglue_zeus2_chicago_MPW_LGA_V2
$make blinky
$cd ..
$cd ..
```
elseif you are running on MacOS
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -m -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/blinky
$make -j 4
```
elseif you are running on windows10
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -u -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/blinky
$make -j 4
```
The example files are in apps/examples/blinky_zglue/  

Burn image on nRF52832 (ZiP) through JTAG programmer.
```shell
$ nrfjprog -e
$ nrfjprog -f NRF52 --program nuttx.hex
$ nrfjprog -r
```

## Example 2 : hello world
For every example below, you will need to connect the UART_TX_QFN and UART_RX_QFN pin to a FTDI break out board RX and TX pin respestively.  Please note the UART_TX_QFN/UART_RX_QFN is 1.8V signal.  You will need to configure your FTDI output to 1.8V.  Otherwise, you will need a level shifter to connect between FTDI and breakout board.

Description : This example prints "Hello world" on the UART terminal.  
If you are running on Linux:
```shell
$cd nuttx/configs/zglue_zeus2_chicago_MPW_LGA_V2/
$make hello
$cd ..
$cd ..
```
elseif you are running on MacOS
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -m -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/hello
$make -j 4
```
elseif you are running on windows10
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -u -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/hello
$make -j 4
```
The example files are in apps/examples/hello/  

Burn image on nRF52832 (ZiP) through JTAG programmer.
```shell
$ nrfjprog -e
$ nrfjprog -f NRF52 --program nuttx.hex
$ nrfjprog -r
```

## Example 3 :nimble(ble uart example)

Description : This example uses the BLE with nimble stack and
shows the ble uart profile. The BLE device name is 'Z_nimble_uart'
Data sent on terminal will be shown in BLE and vice versa.  
If you are running on Linux
```shell
$cd nuttx/configs/zglue_zeus2_chicago_MPW_LGA_V2
$make nimble_uart
$cd ..
$cd ..
```
elseif you are running on MacOS
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -m -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/nimble_uart
$make -j 4
```
elseif you are running on windows10
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -u -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/nimble_uart
$make -j 4
```
The example files are in apps/examples/ble_app_uart/  

Burn image on nRF52832 (ZiP) through JTAG programmer.
```shell
$ nrfjprog -e
$ nrfjprog -f NRF52 --program nuttx.hex
$ nrfjprog -r
```

## Example 4 : nsh with sensor applications

Description : This example runs Nuttx shell(nsh) from which you can 
launch other applications. Application include

1) zGlue smartfabric

2) MC3672 mcube accelerometer

3) MAX86140 maxim optical hr chip

4) BMM150 Bosch magnetometer

5) TMP108 TI temperature sensor
6) BQ25120 TI pmic

if you are running on Linux
```shell
$cd nuttx/configs/zglue_zeus2_chicago_MPW_LGA_V2
$make nsh_chicago++
$cd ..
$cd ..
```
elseif you are running on MacOS
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -m -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/nsh_chicago++
$make
```
elseif you are running on windows10
```shell
$cd nuttx
$make distclean
$./tools/configure.sh -u -a ../apps zglue_zeus2_chicago_MPW_LGA_V2/nsh_chicago++
$make
```
The example files are in apps/examples/nsh/  

Burn image on nRF52832 (ZiP) through JTAG programmer.
```shell
$ nrfjprog -e
$ nrfjprog -f NRF52 --program nuttx.hex
$ nrfjprog -r
```

Open the terminal and hit the return key. The nsh shell is now available

1) nsh help

        nsh>
        nsh> ?
        help usage:  help [-v] [<cmd>]
    
          ?           dirname     help        mkrd        rmdir       umount
          basename    date        hexdump     mh          set         unset
          break       dd          kill        mount       sh          usleep
          cat         echo        ls          mv          sleep       xd
          cd          exec        mb          mw          time
          cp          exit        mkdir       pwd         true
          cmp         false       mkfatfs     rm          uname
    
        Builtin Apps:
          bmm150
          bq25120
          fast
          i2c
          lsm6ds3
          sensor

2) Running the  zGlue smartfabric app

        nsh>
        nsh> fast
        Usage: fast <cmd> [arguments]
        Where <cmd> is one of:
    
          help: Help for nsh fast commands
          debug: Enable/Disable debug features.
          init: Initialize the fast api
          config: Erase/Update the zglue FW config file
          system: Return system/chiplets information
          connect: Connect chips/peripherals to FAST
          disconnect: Disconnect chips/peripherals from FAST
          power: Set/get power state
          id: Return the FAST chip id
          program: Program registers/peripherals
          realign: Run realignment
          pmic: Control PMIC
          gpio: Control GPIO expander
          led: Control LED sinks
          interface: Control the FAST interface settings for SPI/I2C/JTAG
          close: Close the fast api
        nsh>

3) Running the BQ25120 TI pmic app

        nsh> bq25120
        Battery status : FAULT
        Battery health : UNDERVOLTAGE
        Current BQ vout setting : 1800mV

4) Running the MC3672 mcube accelerometer app

        nsh> sensor
        Type 'sensor 1' for mc3672 sensor
        Type 'sensor 2' for max86140 sensor
        nsh> sensor 1
        Starting to Read /dev/accel0 device
        Can't Open Device for Read. Reason:-1
        Starting to Read /dev/accel1 device
                Param: mode:1, range:1, resolution:3, samplerate:6
        
        Starting to Write MC3672 Parameter:
        
                resolution:3, samplerate:6
                Param: mode:1, range:1, resolution:3, samplerate:6
        mc3672 raw data :
        Data index : 0  , X : 1, Y: 0, Z: 122
        Data index : 1  , X : 2, Y: 0, Z: 122
        Data index : 2  , X : 2, Y: -1, Z: 123
        Data index : 3  , X : 2, Y: -1, Z: 124
        Data index : 4  , X : 1, Y: 0, Z: 123
        Data index : 5  , X : 1, Y: -1, Z: 123
        Data index : 6  , X : 2, Y: 0, Z: 124
        Data index : 7  , X : 2, Y: -1, Z: 123
        Data index : 8  , X : 1, Y: 0, Z: 124
        Data index : 9  , X : 2, Y: 0, Z: 123
        Data index : 10  , X : 2, Y: 0, Z: 123
        Data index : 11  , X : 2, Y: 0, Z: 123
        Data index : 12  , X : 2, Y: -1, Z: 124
        Data index : 13  , X : 3, Y: -2, Z: 123
        Data index : 14  , X : 1, Y: -1, Z: 123
        Data index : 15  , X : 3, Y: -1, Z: 123
        
        mc3672 raw data :
        Data index : 0  , X : 2, Y: 0, Z: 124
        Data index : 1  , X : 2, Y: 0, Z: 124
        Data index : 2  , X : 1, Y: 0, Z: 124
        Data index : 3  , X : 2, Y: 0, Z: 123
        Data index : 4  , X : 2, Y: 0, Z: 123
        Data index : 5  , X : 2, Y: 0, Z: 122
        Data index : 6  , X : 3, Y: 0, Z: 123
        Data index : 7  , X : 2, Y: -1, Z: 122
        Data index : 8  , X : 3, Y: 0, Z: 123
        Data index : 9  , X : 3, Y: -1, Z: 123
        Data index : 10  , X : 1, Y: -1, Z: 125
        Data index : 11  , X : 2, Y: 0, Z: 123
        Data index : 12  , X : 2, Y: -1, Z: 122
        Data index : 13  , X : 2, Y: -1, Z: 123
        Data index : 14  , X : 2, Y: 0, Z: 124
        Data index : 15  , X : 1, Y: -1, Z: 123
        End
        nsh>

5) Read the MAX86140 sensor raw data

```shell
nsh> sensor 2
Starting to Read /dev/heartrate0 device
chip id = 24
IRSample:       0x346
Red Sample:     0x4
Green Sample:   0x6
IRSample:       0x33c
Red Sample:     0x0
Green Sample:   0x5
IRSample:       0x339
Red Sample:     0x6
Green Sample:   0x4
IRSample:       0x33c
Red Sample:     0x3d
Green Sample:   0x0
IRSample:       0x33e
Red Sample:     0x9
Green Sample:   0x1
IRSample:       0x33e
Red Sample:     0x7
Green Sample:   0x4
IRSample:       0x33e
Red Sample:     0xf
```


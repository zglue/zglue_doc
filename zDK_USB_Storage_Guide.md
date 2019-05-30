[TOC]

## Summary

zDK usb storage is based on 8MB MX25R QSPI flash( 4kB block size). Now the feature includes:

1. internal zDK FAT filesystem;
2.  filesystem created by Host such as a PC;

Feature 2 can be used as content exchange between Host and devices running on zGlue SDK.



## USB Storage Image Build

1. Build USB MSC image

```shell
$ cd nuttx
$ make distclean
$ ./tools/configure.sh -l -a ../apps nrf52840_dk/nsh_msc
# if you are on macOS, you should use "-m" option instead of "-l"
$ make
# Finally, this will generate nuttx, nuttx.bin,nuttx.hex.
$ nrfjprog -e; nrfjprog --program nuttx.hex 
# this will program usb msc image into internal flash
```

Comment:

1. the usb driver only work with 52840 Rev_C silicon or later (pca10056  does NOT work, , it's Rev_A).

2. Due to a hardware bug, you need to power cycle zGlue DevKit if there is issue to  connect DevKit to host.

3. For the first time use, you should erase MX25R QSPI flash before connecting USB MSC to host(this will make

   sure the QSPI flash is  empty)



## USB Storage Usage

After programming image into Dev board

1. connect zGlue DevKit (maue sure you connected USB port Not Serial debug port) to Host using USB cable

```sh
nsh>flash_eraseall /dev/mtdblock3
```

       This command should be run once.  It can make sure the QSPI flash content is empty



2. enable USB MSC connection 

```shell
nsh> msconn
mcsonn_main: Creating block drivers
mcsonn_main: Configuring with NLUNS=1
mcsonn_main: handle=2000cd30
mcsonn_main: Bind LUN=0 to /dev/mtdblock3
usbmsc_exportluns: Starting SCSI worker thread
usbmsc_exportluns: Waiting for the SCSI worker thread
nrf52_usbd_monitor: phystatus 1, pwr_status : 16.
nrf52_usbdu_monitor: phystatus 2, pwr_status : 18.
sbmsc_exportluns: Signalling for the SCSI worker thread
usbmsc_scsi_main: Running	
```

​		

Comment: 

​    1)   If you get "Running" log from console , it indicates that the USB MSC has been recongnized by host and

​           you will get a new disk on Window explorer (Window-10).

​    2)   If this is your first time running, you should format the new disk with block size(4096).



3. Now you can copy a file into this new disk for test

4. mount the MX25R QSPI flash from zDevKit and lookup the new file from zDevKit

   ```sh
   nsh> mount -t vfat /dev/mtdblock3 /mx25r
   nsh> ls -l /mx25r
   /mx25r:
    drw-rw-rw-       0 System Volume Information/
    -rw-rw-rw-  731305 nuttx2122.hex
   ```

   


[TOC]

## Summary

zDK usb storage is based on 8MB MX25R QSPI flash( 4kB block size). Now the feature included:

1. internal FAT filesystem;
2. created filesystem by Host;

This feature can be used as context exchange between Host and zDevKit.



## USB Storage Image Build

1. Build USB MSC image

```shell
$ cd configs/nrf52840_dk
$ make distclean; make nsh_msc 
# Finally, this will generate nuttx, nuttx.bin,nuttx.hex.
$ nrfjprog -e; nrfjprog --program nuttx.hex 
# this will program usb msc image into internal flash
```

Comment:

1. the usb driver is only worked over  52840 Rev_C or later (pca10056  does NOT work, , it's Rev_A).

2. Due to hardware issue,  every time , you should power cycle zDevKit if there is issue for  connecting 

   issue between Host and zDevKit

3. the first time , you should erase MX25R QSPI flash before connecting usb msc to host(this will make

   sure the QSPI flash is  empty)



## USB Storage Usage

After programming image into Dev board

1. connect zDevKit (USB port Not  Serial debug port)with Host by USB cable

```sh
nsh>flash_eraseall /dev/mtdblock3
```

       This command should be run once.  It can make sure the QSPI flash content is empty



2. enable usb msc connection 

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

​    1)   If you get "Running" log from console , it indicates that the usb msc has been recongnized by host and

​           you will get new disk for Window explorer (Window-10).

​    2)   If this is your first time , you should format the new disk with block size(4096).



3. Now you can copy a file into this new disk for test

4. mount the MX25R QSPI flash from zDevKit and lookup the new file from zDevKit

   ```sh
   nsh> mount -t vfat /dev/mtdblock3 /mx25r
   nsh> ls -l /mx25r
   /mx25r:
    drw-rw-rw-       0 System Volume Information/
    -rw-rw-rw-  731305 nuttx2122.hex
   ```

   


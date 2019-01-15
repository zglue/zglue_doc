

[TOC]

## Summary

zGlue SDK v0.1 has following major components:

1. Kernel/RTOS, based on nuttx
2. BLE stack, based on nimBLE
3. zGlue unique API (FAST API)

 

## zGlue SDK

zGlue SDK Kernel is based on nuttx RTOS, in v0.1 release.  The most important part is picked for this release (refer to kernel directory)

For more details, please refer to http://www.nuttx.org/doku.php?id=documentation

 

## BLE Introduction

BLE documents will contain all the APIs that user can use to start and stop normal BLE operations.  A brief throughput report is also included.  If the user wants to understand very low level details of the BLE stack, please refer to http://mynewt.apache.org/v1_4_0/network/docs/index.html

 

## FAST API introduction

zGlue FAST API is a set of APIs to reconfigure your system running on zGlue silicon interposer.  A user can connect/disconnect chips, route/re-reoute chip connection, use builtin functions such as LED driver and GPIO expander, etc.
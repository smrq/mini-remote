# mini-remote

Tiny universal remote PCB and firmware

## PCB

The design for the PCB was done in KiCad. The PCB is designed according to the specifications of manufacturing with [JLCPCB](https://jlcpcb.com/).

### BOM

Microcontroller

* **U1** [STM8L101xx (STMicroelectronics STM8L101F3P3)](https://www.mouser.com/ProductDetail/511-STM8L101F3P3)

LEDs

* **D1** [940nm IR LED (Everlight IR333/H0/L10)](https://www.mouser.com/ProductDetail/638-IR333-H0-L10)
* **D2** [2x3x4 LED, red (Chanzon)](https://www.amazon.com/Rectangle-Diffused-Lighting-Electronics-Components/dp/B01C3ZZT1E)

Resistors

* **R1** 22Ω 0805 resistor
* **R2** 2K7Ω 0805 resistor
* **R3** 1KΩ 0805 resistor
* **R4** 10KΩ 0805 resistor

Capacitors

* **C1-C2** 100nF 0805 capacitor

Transistors

* **Q1** [MMBT3906 PNP transistor](https://www.mouser.com/ProductDetail/863-MMBT3906LT3G)

Etc.

* **SW1-SW22** 20x [E-Switch LL3301NF065QG](https://www.mouser.com/ProductDetail/612-LL3301NF065QG)
	* Note that SW2 and SW9 are omitted from this design
* **BT1** [Linx Technologies BAT-HLD-001 CR2032 battery holder](https://www.mouser.com/ProductDetail/712-BAT-HLD-001)
* **J1** 4-pin 2.54mm header (for programming the microcontroller)
* **J2** 2-pin 2.54mm header (optional, for debugging only)

## Firmware

Building the firmware is done with Docker, but flashing the firmware requires USB hardware access that is beyond my Docker capabilities, if possible at all.

Prerequisites:

* Install Docker
* Install [stm8flash](https://github.com/vdudouyt/stm8flash) and make sure it is in your PATH
* Run `make docker` to build the Docker image

Building and flashing:

* `make` to build the firmware hex file
* `make flash` to flash the firmware

I used [this cheap knockoff ST-Link V2 programmer (HiLetgo V2)](https://www.amazon.com/HiLetgo-Emulator-Downloader-Programmer-STM32F103C8T6/dp/B07SQV6VLZ/ref=sr_1_5?dchild=1&keywords=st-link+v2&qid=1620240018&sr=8-5) with no problems.

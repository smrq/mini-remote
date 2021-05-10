EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R1
U 1 1 6093F542
P 3400 1450
F 0 "R1" H 3470 1496 50  0000 L CNN
F 1 "22" H 3470 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3330 1450 50  0001 C CNN
F 3 "~" H 3400 1450 50  0001 C CNN
	1    3400 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 6093FC7B
P 3850 1100
F 0 "R2" H 3920 1146 50  0000 L CNN
F 1 "2K7" H 3920 1055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3780 1100 50  0001 C CNN
F 3 "~" H 3850 1100 50  0001 C CNN
	1    3850 1100
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 609425ED
P 3400 1750
F 0 "D1" H 3393 1967 50  0000 C CNN
F 1 "IRLED" H 3393 1876 50  0000 C CNN
F 2 "LED_THT:LED_D5.0mm" H 3400 1750 50  0001 C CNN
F 3 "~" H 3400 1750 50  0001 C CNN
	1    3400 1750
	0    1    -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 609430B6
P 6500 2250
F 0 "C1" H 6615 2296 50  0000 L CNN
F 1 "100nF" H 6615 2205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6538 2100 50  0001 C CNN
F 3 "~" H 6500 2250 50  0001 C CNN
	1    6500 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 60920A49
P 5450 3450
F 0 "#PWR0101" H 5450 3200 50  0001 C CNN
F 1 "GND" H 5455 3277 50  0000 C CNN
F 2 "" H 5450 3450 50  0001 C CNN
F 3 "" H 5450 3450 50  0001 C CNN
	1    5450 3450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:MMBT3906 Q1
U 1 1 609326CD
P 3500 1100
F 0 "Q1" H 3691 1054 50  0000 L CNN
F 1 "MMBT3906" H 3691 1145 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3700 1025 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/2N3906-D.PDF" H 3500 1100 50  0001 L CNN
	1    3500 1100
	-1   0    0    1   
$EndComp
$Comp
L power:VCC #PWR0106
U 1 1 6093933B
P 3400 900
F 0 "#PWR0106" H 3400 750 50  0001 C CNN
F 1 "VCC" H 3415 1073 50  0000 C CNN
F 2 "" H 3400 900 50  0001 C CNN
F 3 "" H 3400 900 50  0001 C CNN
	1    3400 900 
	1    0    0    -1  
$EndComp
$Comp
L MCU_ST_STM8:STM8L101F3P U1
U 1 1 60943D6A
P 5450 2550
F 0 "U1" H 5450 2750 50  0000 C CNN
F 1 "STM8L101F3P" H 5600 2250 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 5500 3550 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00220591.pdf" H 5450 2150 50  0001 C CNN
	1    5450 2550
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0107
U 1 1 60920116
P 5450 1650
F 0 "#PWR0107" H 5450 1500 50  0001 C CNN
F 1 "VCC" H 5465 1823 50  0000 C CNN
F 2 "" H 5450 1650 50  0001 C CNN
F 3 "" H 5450 1650 50  0001 C CNN
	1    5450 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 6093E57E
P 3400 2000
F 0 "#PWR0108" H 3400 1750 50  0001 C CNN
F 1 "GND" H 3405 1827 50  0000 C CNN
F 2 "" H 3400 2000 50  0001 C CNN
F 3 "" H 3400 2000 50  0001 C CNN
	1    3400 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2000 3400 1900
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 6099CB40
P 3500 3800
F 0 "J1" H 3580 3792 50  0000 L CNN
F 1 "Conn_01x04" H 3580 3701 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3500 3800 50  0001 C CNN
F 3 "~" H 3500 3800 50  0001 C CNN
	1    3500 3800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0109
U 1 1 609A42FD
P 2850 3700
F 0 "#PWR0109" H 2850 3550 50  0001 C CNN
F 1 "VCC" H 2865 3873 50  0000 C CNN
F 2 "" H 2850 3700 50  0001 C CNN
F 3 "" H 2850 3700 50  0001 C CNN
	1    2850 3700
	1    0    0    -1  
$EndComp
Text Label 3000 4000 0    50   ~ 0
RESET
Wire Wire Line
	3000 3800 3300 3800
Wire Wire Line
	3300 4000 3000 4000
Text Label 3000 3800 0    50   ~ 0
SWIM
$Comp
L power:GND #PWR0110
U 1 1 609B2162
P 2850 3900
F 0 "#PWR0110" H 2850 3650 50  0001 C CNN
F 1 "GND" H 2855 3727 50  0000 C CNN
F 2 "" H 2850 3900 50  0001 C CNN
F 3 "" H 2850 3900 50  0001 C CNN
	1    2850 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3900 3300 3900
Wire Wire Line
	2850 3700 3300 3700
Wire Wire Line
	4700 1100 4700 1950
$Comp
L Switch:SW_SPST SW1
U 1 1 609238C8
P 1000 1050
F 0 "SW1" H 1000 1285 50  0000 C CNN
F 1 "SW_SPST" H 1000 1194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1000 1050 50  0001 C CNN
F 3 "~" H 1000 1050 50  0001 C CNN
	1    1000 1050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW3
U 1 1 60924C0C
P 2000 1050
F 0 "SW3" H 2000 1285 50  0000 C CNN
F 1 "SW_SPST" H 2000 1194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 2000 1050 50  0001 C CNN
F 3 "~" H 2000 1050 50  0001 C CNN
	1    2000 1050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW4
U 1 1 60924F9E
P 1000 1550
F 0 "SW4" H 1000 1785 50  0000 C CNN
F 1 "SW_SPST" H 1000 1694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1000 1550 50  0001 C CNN
F 3 "~" H 1000 1550 50  0001 C CNN
	1    1000 1550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW5
U 1 1 609250C9
P 1500 1550
F 0 "SW5" H 1500 1785 50  0000 C CNN
F 1 "SW_SPST" H 1500 1694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1500 1550 50  0001 C CNN
F 3 "~" H 1500 1550 50  0001 C CNN
	1    1500 1550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW6
U 1 1 60925492
P 2000 1550
F 0 "SW6" H 2000 1785 50  0000 C CNN
F 1 "SW_SPST" H 2000 1694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 2000 1550 50  0001 C CNN
F 3 "~" H 2000 1550 50  0001 C CNN
	1    2000 1550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW7
U 1 1 60925950
P 1000 2050
F 0 "SW7" H 1000 2285 50  0000 C CNN
F 1 "SW_SPST" H 1000 2194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1000 2050 50  0001 C CNN
F 3 "~" H 1000 2050 50  0001 C CNN
	1    1000 2050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW10
U 1 1 60925C15
P 1000 2550
F 0 "SW10" H 1000 2785 50  0000 C CNN
F 1 "SW_SPST" H 1000 2694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1000 2550 50  0001 C CNN
F 3 "~" H 1000 2550 50  0001 C CNN
	1    1000 2550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW13
U 1 1 6092ECCB
P 1000 3050
F 0 "SW13" H 1000 3285 50  0000 C CNN
F 1 "SW_SPST" H 1000 3194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1000 3050 50  0001 C CNN
F 3 "~" H 1000 3050 50  0001 C CNN
	1    1000 3050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW16
U 1 1 6092ECD1
P 1000 3550
F 0 "SW16" H 1000 3785 50  0000 C CNN
F 1 "SW_SPST" H 1000 3694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1000 3550 50  0001 C CNN
F 3 "~" H 1000 3550 50  0001 C CNN
	1    1000 3550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW8
U 1 1 6092ECD7
P 1500 2050
F 0 "SW8" H 1500 2285 50  0000 C CNN
F 1 "SW_SPST" H 1500 2194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1500 2050 50  0001 C CNN
F 3 "~" H 1500 2050 50  0001 C CNN
	1    1500 2050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW11
U 1 1 6092ECDD
P 1500 2550
F 0 "SW11" H 1500 2785 50  0000 C CNN
F 1 "SW_SPST" H 1500 2694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1500 2550 50  0001 C CNN
F 3 "~" H 1500 2550 50  0001 C CNN
	1    1500 2550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW14
U 1 1 6092ECE3
P 1500 3050
F 0 "SW14" H 1500 3285 50  0000 C CNN
F 1 "SW_SPST" H 1500 3194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1500 3050 50  0001 C CNN
F 3 "~" H 1500 3050 50  0001 C CNN
	1    1500 3050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW17
U 1 1 6092ECE9
P 1500 3550
F 0 "SW17" H 1500 3785 50  0000 C CNN
F 1 "SW_SPST" H 1500 3694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1500 3550 50  0001 C CNN
F 3 "~" H 1500 3550 50  0001 C CNN
	1    1500 3550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW12
U 1 1 6092ECF5
P 2000 2550
F 0 "SW12" H 2000 2785 50  0000 C CNN
F 1 "SW_SPST" H 2000 2694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 2000 2550 50  0001 C CNN
F 3 "~" H 2000 2550 50  0001 C CNN
	1    2000 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 60A69C95
P 6000 1150
F 0 "BT1" H 6118 1246 50  0000 L CNN
F 1 "CR2032" H 6118 1155 50  0000 L CNN
F 2 "Local:BATHLD001" V 6000 1210 50  0001 C CNN
F 3 "~" V 6000 1210 50  0001 C CNN
	1    6000 1150
	0    1    1    0   
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 60A6B33D
P 6300 1150
F 0 "#PWR0102" H 6300 1000 50  0001 C CNN
F 1 "VCC" H 6315 1323 50  0000 C CNN
F 2 "" H 6300 1150 50  0001 C CNN
F 3 "" H 6300 1150 50  0001 C CNN
	1    6300 1150
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 60A6B6EE
P 6500 2000
F 0 "#PWR0103" H 6500 1850 50  0001 C CNN
F 1 "VCC" H 6515 2173 50  0000 C CNN
F 2 "" H 6500 2000 50  0001 C CNN
F 3 "" H 6500 2000 50  0001 C CNN
	1    6500 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 60A6BB5A
P 6500 2500
F 0 "#PWR0104" H 6500 2250 50  0001 C CNN
F 1 "GND" H 6505 2327 50  0000 C CNN
F 2 "" H 6500 2500 50  0001 C CNN
F 3 "" H 6500 2500 50  0001 C CNN
	1    6500 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 60A6C152
P 5800 1150
F 0 "#PWR0105" H 5800 900 50  0001 C CNN
F 1 "GND" H 5805 977 50  0000 C CNN
F 2 "" H 5800 1150 50  0001 C CNN
F 3 "" H 5800 1150 50  0001 C CNN
	1    5800 1150
	1    0    0    1   
$EndComp
Wire Wire Line
	5900 1150 5800 1150
Wire Wire Line
	6500 2500 6500 2400
Wire Wire Line
	6500 2000 6500 2100
Wire Wire Line
	6200 1150 6300 1150
$Comp
L Switch:SW_SPST SW15
U 1 1 60A97C5E
P 2000 3050
F 0 "SW15" H 2000 3285 50  0000 C CNN
F 1 "SW_SPST" H 2000 3194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 2000 3050 50  0001 C CNN
F 3 "~" H 2000 3050 50  0001 C CNN
	1    2000 3050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW18
U 1 1 60A98092
P 2000 3550
F 0 "SW18" H 2000 3785 50  0000 C CNN
F 1 "SW_SPST" H 2000 3694 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 2000 3550 50  0001 C CNN
F 3 "~" H 2000 3550 50  0001 C CNN
	1    2000 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 60A9926D
P 6250 3000
F 0 "D2" H 6243 3217 50  0000 C CNN
F 1 "LED" H 6243 3126 50  0000 C CNN
F 2 "LED_THT:LED_Rectangular_W3.0mm_H2.0mm" H 6250 3000 50  0001 C CNN
F 3 "~" H 6250 3000 50  0001 C CNN
	1    6250 3000
	0    1    -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 60A99A93
P 6250 2700
F 0 "R3" H 6320 2746 50  0000 L CNN
F 1 "1k" H 6320 2655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6180 2700 50  0001 C CNN
F 3 "~" H 6250 2700 50  0001 C CNN
	1    6250 2700
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_SPST SW22
U 1 1 60A9B7A8
P 3150 2800
F 0 "SW22" H 3150 3035 50  0000 C CNN
F 1 "SW_SPST" H 3150 2944 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 3150 2800 50  0001 C CNN
F 3 "~" H 3150 2800 50  0001 C CNN
	1    3150 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 60A9BBEB
P 2850 3100
F 0 "#PWR0111" H 2850 2850 50  0001 C CNN
F 1 "GND" H 2855 2927 50  0000 C CNN
F 2 "" H 2850 3100 50  0001 C CNN
F 3 "" H 2850 3100 50  0001 C CNN
	1    2850 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 60A9C08C
P 3150 3000
F 0 "C2" H 3265 3046 50  0000 L CNN
F 1 "100nF" H 3265 2955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3188 2850 50  0001 C CNN
F 3 "~" H 3150 3000 50  0001 C CNN
	1    3150 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 3100 2850 3000
Wire Wire Line
	2850 3000 3000 3000
Wire Wire Line
	2950 2800 2850 2800
Wire Wire Line
	2850 2800 2850 3000
Connection ~ 2850 3000
Wire Wire Line
	3350 2800 3500 2800
Wire Wire Line
	3500 2800 3500 3000
Wire Wire Line
	3500 3000 3300 3000
Text Label 3600 2800 0    50   ~ 0
RESET
Wire Wire Line
	3500 2800 3600 2800
Connection ~ 3500 2800
Wire Wire Line
	800  1050 800  1550
Connection ~ 800  1550
Wire Wire Line
	800  1550 800  2050
Connection ~ 800  2050
Wire Wire Line
	800  2050 800  2550
Connection ~ 800  2550
Wire Wire Line
	800  2550 800  3050
Connection ~ 800  3050
Wire Wire Line
	800  3050 800  3550
Wire Wire Line
	1300 3550 1300 3050
Connection ~ 1300 2050
Wire Wire Line
	1300 2050 1300 1550
Connection ~ 1300 2550
Wire Wire Line
	1300 2550 1300 2050
Connection ~ 1300 3050
Wire Wire Line
	1300 3050 1300 2550
Wire Wire Line
	1800 1050 1800 1550
Connection ~ 1800 1550
Connection ~ 1800 2550
Wire Wire Line
	1800 2550 1800 3050
Connection ~ 1800 3050
Wire Wire Line
	1800 3050 1800 3550
Wire Wire Line
	1200 1050 1200 1200
Wire Wire Line
	2200 1200 2200 1050
Connection ~ 2200 1200
Wire Wire Line
	2200 1200 2300 1200
Wire Wire Line
	1200 1550 1200 1700
Wire Wire Line
	1200 1700 1700 1700
Wire Wire Line
	1700 1550 1700 1700
Connection ~ 1700 1700
Wire Wire Line
	1700 1700 2200 1700
Wire Wire Line
	2200 1700 2200 1550
Connection ~ 2200 1700
Wire Wire Line
	1200 2050 1200 2200
Wire Wire Line
	1200 2200 1700 2200
Wire Wire Line
	1700 2050 1700 2200
Connection ~ 1700 2200
Wire Wire Line
	1200 2550 1200 2700
Wire Wire Line
	1200 2700 1700 2700
Wire Wire Line
	1700 2550 1700 2700
Connection ~ 1700 2700
Wire Wire Line
	1700 2700 2200 2700
Wire Wire Line
	2200 2700 2200 2550
Connection ~ 2200 2700
Wire Wire Line
	1200 3050 1200 3200
Wire Wire Line
	1200 3200 1700 3200
Wire Wire Line
	1700 3050 1700 3200
Connection ~ 1700 3200
Wire Wire Line
	1700 3200 2200 3200
Wire Wire Line
	2200 3200 2200 3050
Connection ~ 2200 3200
Wire Wire Line
	1200 3550 1200 3700
Wire Wire Line
	1200 3700 1700 3700
Wire Wire Line
	1700 3550 1700 3700
Connection ~ 1700 3700
Wire Wire Line
	1700 3700 2200 3700
Wire Wire Line
	2200 3700 2200 3550
Connection ~ 2200 3700
Wire Wire Line
	2200 3700 2300 3700
Wire Wire Line
	2200 3200 2300 3200
Wire Wire Line
	2200 2700 2300 2700
Wire Wire Line
	2200 1700 2300 1700
Wire Wire Line
	4850 2450 4350 2450
Wire Wire Line
	4350 2550 4850 2550
Wire Wire Line
	4350 2650 4850 2650
Wire Wire Line
	4350 2750 4850 2750
Wire Wire Line
	4350 2850 4850 2850
Wire Wire Line
	4850 2950 4350 2950
Wire Wire Line
	6050 2550 6250 2550
Text Label 4350 2450 0    50   ~ 0
ROW0
Text Label 4350 2550 0    50   ~ 0
ROW1
Text Label 4350 2650 0    50   ~ 0
ROW2
Text Label 4350 2750 0    50   ~ 0
ROW3
Text Label 4350 2850 0    50   ~ 0
ROW4
Text Label 4350 2950 0    50   ~ 0
ROW5
Text Label 6050 1950 0    50   ~ 0
COL0
Text Label 6050 2050 0    50   ~ 0
COL1
Text Label 6050 2150 0    50   ~ 0
COL2
Text Label 2300 1200 0    50   ~ 0
ROW0
Text Label 2300 1700 0    50   ~ 0
ROW1
Text Label 2300 2200 0    50   ~ 0
ROW2
Text Label 2300 2700 0    50   ~ 0
ROW3
Text Label 2300 3200 0    50   ~ 0
ROW4
Text Label 2300 3700 0    50   ~ 0
ROW5
Text Label 800  4550 0    50   ~ 0
COL0
Text Label 1300 4550 0    50   ~ 0
COL1
Text Label 1800 4550 0    50   ~ 0
COL2
NoConn ~ 6050 2250
NoConn ~ 6050 2350
NoConn ~ 4850 3150
$Comp
L power:GND #PWR0112
U 1 1 609EDF28
P 6250 3150
F 0 "#PWR0112" H 6250 2900 50  0001 C CNN
F 1 "GND" H 6255 2977 50  0000 C CNN
F 2 "" H 6250 3150 50  0001 C CNN
F 3 "" H 6250 3150 50  0001 C CNN
	1    6250 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 60A38BF5
P 3500 2650
F 0 "R4" H 3570 2696 50  0000 L CNN
F 1 "10K" H 3570 2605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3430 2650 50  0001 C CNN
F 3 "~" H 3500 2650 50  0001 C CNN
	1    3500 2650
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR01
U 1 1 60A39A2D
P 3500 2500
F 0 "#PWR01" H 3500 2350 50  0001 C CNN
F 1 "VCC" H 3515 2673 50  0000 C CNN
F 2 "" H 3500 2500 50  0001 C CNN
F 3 "" H 3500 2500 50  0001 C CNN
	1    3500 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3050 4350 3050
Text Label 4350 3050 0    50   ~ 0
ROW6
$Comp
L Switch:SW_SPST SW19
U 1 1 6099D9C6
P 1000 4050
F 0 "SW19" H 1000 4285 50  0000 C CNN
F 1 "SW_SPST" H 1000 4194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1000 4050 50  0001 C CNN
F 3 "~" H 1000 4050 50  0001 C CNN
	1    1000 4050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW20
U 1 1 6099D9E0
P 1500 4050
F 0 "SW20" H 1500 4285 50  0000 C CNN
F 1 "SW_SPST" H 1500 4194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 1500 4050 50  0001 C CNN
F 3 "~" H 1500 4050 50  0001 C CNN
	1    1500 4050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW21
U 1 1 6099D9EA
P 2000 4050
F 0 "SW21" H 2000 4285 50  0000 C CNN
F 1 "SW_SPST" H 2000 4194 50  0000 C CNN
F 2 "Local:LL3301NF065QG" H 2000 4050 50  0001 C CNN
F 3 "~" H 2000 4050 50  0001 C CNN
	1    2000 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  3550 800  4050
Wire Wire Line
	1300 4050 1300 3550
Wire Wire Line
	1800 3550 1800 4050
Wire Wire Line
	1200 4050 1200 4200
Wire Wire Line
	1200 4200 1700 4200
Wire Wire Line
	1700 4050 1700 4200
Connection ~ 1700 4200
Wire Wire Line
	1700 4200 2200 4200
Wire Wire Line
	2200 4200 2200 4050
Connection ~ 2200 4200
Wire Wire Line
	2200 4200 2300 4200
Text Label 2300 4200 0    50   ~ 0
ROW6
Wire Wire Line
	1800 4050 1800 4550
Connection ~ 1800 4050
Wire Wire Line
	1300 4550 1300 4050
Connection ~ 1300 4050
Wire Wire Line
	800  4550 800  4050
Connection ~ 800  4050
Connection ~ 800  3550
Connection ~ 1300 3550
Connection ~ 1800 3550
Wire Wire Line
	4000 1100 4700 1100
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 609ECF6A
P 3500 4300
F 0 "J2" H 3580 4292 50  0000 L CNN
F 1 "Conn_01x02" H 3580 4201 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3500 4300 50  0001 C CNN
F 3 "~" H 3500 4300 50  0001 C CNN
	1    3500 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 2050 4850 2050
Wire Wire Line
	4350 1950 4700 1950
Wire Wire Line
	4700 1950 4850 1950
Connection ~ 4700 1950
Text Label 4350 2050 0    50   ~ 0
RESET
Text Label 4350 1950 0    50   ~ 0
SWIM
Wire Wire Line
	4350 2150 4850 2150
Wire Wire Line
	4350 2250 4850 2250
Text Label 4350 2150 0    50   ~ 0
A2
Text Label 4350 2250 0    50   ~ 0
A3
Text Label 6050 2550 0    50   ~ 0
LED
Wire Wire Line
	3300 4300 3000 4300
Wire Wire Line
	3000 4400 3300 4400
Wire Wire Line
	1800 1550 1800 2550
Wire Wire Line
	1200 1200 2200 1200
Wire Wire Line
	1700 2200 2300 2200
Text Label 3000 4400 0    50   ~ 0
A3
Text Label 3000 4300 0    50   ~ 0
A2
$EndSCHEMATC

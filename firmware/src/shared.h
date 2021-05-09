#pragma once
#include "stm8l10x.h"

// Pin assignments:
// 	A0:    IR LED
// 	B0-B5: Rows 0-5
// 	C0-C2: Columns 0-2
// 	D0:    LED

#define TIMER_COUNT_38KHz (F_CPU / 38000UL)

// F_CPU (16e6) * 0.0005625 = 9000
#define TIMER_COUNT_562_5uS 9000

#define ROW_COUNT 6
#define ROW_MASK ((1<<(ROW_COUNT+1))-1)

#define COL_COUNT 3
#define COL_MASK ((1<<(COL_COUNT+1))-1)


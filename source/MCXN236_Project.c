/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    MCXN236_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MCXN236.h"
#include "fsl_debug_console.h"

#include "freeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"


/* TODO: insert other include files here. */
#include "loops.h"
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */



void board_init(void);
void Start_Loop(init_proc_t);

int main(void) {

	board_init();

	vTaskStartScheduler();
	LOOP_Start(NULL);
	for(;;);

    return 0 ;
}


void board_init(void){
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
}



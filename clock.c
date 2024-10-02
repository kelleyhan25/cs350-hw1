/*******************************************************************************
* CPU Clock Measurement Using RDTSC
*
* Description:
*     This C file provides functions to compute and measure the CPU clock using
*     the `rdtsc` instruction. The `rdtsc` instruction returns the Time Stamp
*     Counter, which can be used to measure CPU clock cycles.
*
* Author:
*     Renato Mancuso
*
* Affiliation:
*     Boston University
*
* Creation Date:
*     September 10, 2023
*
* Last Update:
*     September 9, 2024
*
* Notes:
*     Ensure that the platform supports the `rdtsc` instruction before using
*     these functions. Depending on the CPU architecture and power-saving
*     modes, the results might vary. Always refer to the CPU's official
*     documentation for accurate interpretations.
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include "timelib.h"

int main (int argc, char ** argv)
{
	/* IMPLEMENT ME! */
	if (argc == 4) { 
		long seconds = atol(argv[1]);
		long nanoseconds = atol(argv[2]);
		char procedure = argv[3][0];

		uint64_t elasped_clock_cycles;
		if (procedure == 's') {
			elasped_clock_cycles = get_elapsed_sleep(seconds, nanoseconds);
			printf("WaitMethod: SLEEP\n");

		} else if (procedure == 'b') {
			elasped_clock_cycles = get_elapsed_busywait(seconds, nanoseconds);
			printf("WaitMethod: BUSYWAIT\n");
		}
		double measured_clock_speed;
		double wait_time = seconds * NANO_IN_SEC + nanoseconds;
		double wait_time_2 = wait_time / NANO_IN_SEC;
		measured_clock_speed = elasped_clock_cycles / wait_time_2 / 1000000; 
		printf("WaitTime: %ld %ld\n", seconds, nanoseconds);
		printf("ClocksElapsed: %lu\n", elasped_clock_cycles);
		printf("ClockSpeed: %lf\n", measured_clock_speed);
	}
	return EXIT_SUCCESS;
}


#include <leopard2a6_c21.h>

void tick () {
	static uint16_t div1hz = 0;
	static uint16_t div10hz = 0;
	static uint16_t div100hz = 0;
	static uint16_t div30hz = 0;
	static uint16_t div60hz = 0;

	if (div1hz < 1000) {
		div1hz ++;
	} else {
		div1hz = 0;
		routine.is_1hz = 1;
	}

	if (div10hz < 100) {
		div10hz ++;
	} else {
		div10hz = 0;
		routine.is_10hz = 1;
	}

	if (div100hz < 10) {
		div100hz ++;
	} else {
		div100hz = 0;
		routine.is_100hz = 1;
	}

	if (div30hz < 33) {
		div30hz ++;
	} else {
		div30hz = 0;
		routine.is_30hz = 1;
	}

	if (div60hz < 16) {
		div60hz ++;
	} else {
		div60hz = 0;
		routine.is_60hz = 1;
	}

}

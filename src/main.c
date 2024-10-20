#include <leopard2a6_c21.h>
#include <nvm.h>
#include <gpio.h>

Task routine;

int main (void ) {
	init_nvm ();
	init_system_clk_48mhz ();

	init_gpio ();

	SysTick_Config (48000);

	while (1) {
		if (routine.is_1hz) {
			routine.is_1hz = 0;
		}

		if (routine.is_10hz) {
			routine.is_10hz = 0;
		}

		if (routine.is_100hz) {
			routine.is_100hz = 0;
		}

		if (routine.is_30hz) {
			routine.is_30hz = 0;
		}

		if (routine.is_60hz) {
			routine.is_60hz = 0;
		}
	}
}

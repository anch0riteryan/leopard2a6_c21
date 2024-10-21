#include <leopard2a6_c21.h>
#include <nvm.h>
#include <gpio.h>
#include <dmac.h>
#include <mt_pwm.h>
#include <ppm_reader.h>


Task routine;

int main (void ) {
	init_nvm ();
	init_system_clk_48mhz ();

	init_gpio ();

	init_dmac ();
	init_eic ();
	init_evsys ();

	init_mt_pwm ();
	init_ppm_reader ();

	SysTick_Config (48000);

	NVIC_EnableIRQ (TCC0_IRQn); NVIC_EnableIRQ (TCC1_IRQn); NVIC_EnableIRQ (TCC2_IRQn);
	NVIC_EnableIRQ (DMAC_IRQn);
	__enable_irq ();

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

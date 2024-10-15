#include <leopard2a6_c21.h>

int main (void ) {

	init_system_clk_48mhz ();

	SysTick_Config (48000000);

	while (1) {
		//
	}
}

#include <leopard2a6_c21.h>
#include <tick.h>

void NMI_Handler () {}
void HardFault_Handler () {}
void SVC_Handler () {}
void PendSV_Handler () {}
void SysTick_Handler () {
	tick ();
}

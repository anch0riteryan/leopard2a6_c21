#include <leopard2a6_c21.h>

#define GCLK_ID_MAIN 0 // SYSTEM CLOCK MAX 48MHZ
#define GCLK_ID_48MHZ 0
#define GCLK_ID_96MHZ 1
#define GCLK_ID_32KHZ 2
#define GCLK_ID_8MHZ 8

#define SOFT_DELAY 480

void init_system_clk_48mhz () {
	NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_DUAL_Val;

	GCLK->CTRLA.bit.SWRST = 1;
	while (GCLK->SYNCBUSY.bit.SWRST);

	OSCCTRL->OSC48MCTRL.bit.ONDEMAND = 0;
	OSCCTRL->OSC48MDIV.bit.DIV = 0;
	while (!OSCCTRL->STATUS.bit.OSC48MRDY);

	//start up external 32k crystal
	OSC32KCTRL->XOSC32K = (OSC32KCTRL_XOSC32K_Type) {
		.bit.WRTLOCK = 0,
		.bit.STARTUP = 0x03,
		.bit.ONDEMAND = 0,
		.bit.EN1K = 0,
		.bit.EN32K = 1,
		.bit.XTALEN = 1,
		.bit.ENABLE = 1
	};
	while (!OSC32KCTRL->STATUS.bit.XOSC32KRDY);

	//32.768KHz
	GCLK->GENCTRL[GCLK_ID_32KHZ] = (GCLK_GENCTRL_Type) {
		.bit.DIV = 0,
		.bit.DIVSEL = 0,
		.bit.OE = 0,
		.bit.IDC = 1,
		.bit.GENEN = 1,
		.bit.SRC = GCLK_GENCTRL_SRC_XOSC32K_Val
	};
	while (GCLK->SYNCBUSY.bit.GENCTRL >> GCLK_ID_32KHZ & 0x01);

	GCLK->PCHCTRL[OSCCTRL_GCLK_ID_FDPLL32K] = (GCLK_PCHCTRL_Type) {
		.bit.WRTLOCK = 0,
		.bit.CHEN = 1,
		.bit.GEN = GCLK_ID_32KHZ
	};

	GCLK->PCHCTRL[OSCCTRL_GCLK_ID_FDPLL] = (GCLK_PCHCTRL_Type) {
		.bit.WRTLOCK = 0,
		.bit.CHEN = 1,
		.bit.GEN = GCLK_ID_32KHZ
	};

	//
	//Fin = 32.768KHz Fout=96MHz
	//Fout = Fin x (LDR + 1 + (LDRFRAC / 16)) x (1 / 2^PRESC)
	//96MHz / 32.768KHz = 2929.6875
	//LDRFRAC = 0.6875 x 16 = 11
	//LDR = 2929 - 1 = 2928
	//
	OSCCTRL->DPLLRATIO = (OSCCTRL_DPLLRATIO_Type) {
		//.bit.LDR = 1464, //48MHz
		//.bit.LDR = 1954, // 64MHz
		.bit.LDR = 2928, //96MHz
		.bit.LDRFRAC = 11
	};
	while (OSCCTRL->DPLLSYNCBUSY.bit.DPLLRATIO);

	OSCCTRL->DPLLCTRLB = (OSCCTRL_DPLLCTRLB_Type) {
		.bit.REFCLK = 0, //XOSC32K
		.bit.WUF = 0,
		.bit.LPEN = 0,
		.bit.FILTER = 1,
		.bit.LBYPASS = 0,
		.bit.LTIME = 0,
		.bit.DIV = 0
	};

	OSCCTRL->DPLLCTRLA = (OSCCTRL_DPLLCTRLA_Type) {
		.bit.ONDEMAND = 0,
		.bit.ENABLE = 1
	};
	while (OSCCTRL->DPLLSYNCBUSY.bit.ENABLE);

	while (!OSCCTRL->DPLLSTATUS.bit.CLKRDY && !OSCCTRL->DPLLSTATUS.bit.LOCK);

	//8MHZ
	GCLK->GENCTRL[GCLK_ID_8MHZ].bit.DIV = 12;
	GCLK->GENCTRL[GCLK_ID_8MHZ].bit.IDC = 1;
	GCLK->GENCTRL[GCLK_ID_8MHZ].bit.SRC = GCLK_GENCTRL_SRC_DPLL96M_Val;
	GCLK->GENCTRL[GCLK_ID_8MHZ].bit.GENEN = 1;
	for (uint32_t delay = 0; delay < SOFT_DELAY; delay++);
	while (GCLK->SYNCBUSY.bit.GENCTRL);

	//96MHz
	GCLK->GENCTRL[GCLK_ID_96MHZ].bit.DIV = 1;
	GCLK->GENCTRL[GCLK_ID_96MHZ].bit.IDC = 1;
	GCLK->GENCTRL[GCLK_ID_96MHZ].bit.SRC = GCLK_GENCTRL_SRC_DPLL96M_Val;
	GCLK->GENCTRL[GCLK_ID_96MHZ].bit.GENEN = 1;
	for (uint32_t delay = 0; delay < SOFT_DELAY; delay++);
	while (GCLK->SYNCBUSY.bit.GENCTRL);
	
	//48MHZ MAIN
	GCLK->GENCTRL[GCLK_ID_MAIN].bit.DIV = 2;
	GCLK->GENCTRL[GCLK_ID_MAIN].bit.IDC = 1;
	GCLK->GENCTRL[GCLK_ID_MAIN].bit.SRC = GCLK_GENCTRL_SRC_DPLL96M_Val;
	for (uint32_t delay = 0; delay < SOFT_DELAY; delay++);
	while (GCLK->SYNCBUSY.bit.GENCTRL);
}

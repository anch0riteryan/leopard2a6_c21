#include <leopard2a6_c21.h>

#define GCLK_ID_48MHZ 0 // SYSTEM CLOCK MAX 48MHZ
#define GCLK_ID_96MHZ 1
#define GCLK_ID_32KHZ 2
#define GCLK_ID_8MHZ 8

void init_system_clk_48mhz () {
	NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val;

	//startup XOSC32K
	OSC32KCTRL->XOSC32K = (OSC32KCTRL_XOSC32K_Type) {
		.bit.WRTLOCK = 1,
		.bit.STARTUP = 1,
		.bit.ONDEMAND = 0,
		.bit.EN32K = 1,
		.bit.XTALEN = 1,
		.bit.ENABLE = 1
	};
	while (!OSC32KCTRL->STATUS.bit.XOSC32KRDY);
	
	//32khz clock-fail detector
	//

	//GCLK 32.768KHZ
	GCLK->GENCTRL[GCLK_ID_32KHZ].bit.GENEN = 0;
	while (GCLK->SYNCBUSY.bit.GENCTRL);

	GCLK->GENCTRL[GCLK_ID_32KHZ] = (GCLK_GENCTRL_Type) {
		.bit.DIV = 0,
		.bit.DIVSEL = 0,
		.bit.OE = 0,
		.bit.IDC = 1,
		.bit.GENEN = 1,
		.bit.SRC = GCLK_GENCTRL_SRC_XOSC32K_Val
	};
	while (GCLK->SYNCBUSY.bit.GENCTRL >> GCLK_ID_32KHZ & 0x01);

	//startup FDPLL
	GCLK->PCHCTRL[OSCCTRL_GCLK_ID_FDPLL] = (GCLK_PCHCTRL_Type) {
		.bit.WRTLOCK = 0,
		.bit.CHEN = 1,
		.bit.GEN = GCLK_ID_32KHZ
	};

	GCLK->PCHCTRL[OSCCTRL_GCLK_ID_FDPLL32K] = (GCLK_PCHCTRL_Type) {
		.bit.WRTLOCK = 0,
		.bit.CHEN = 1,
		.bit.GEN = GCLK_ID_32KHZ
	};

	/*
	[FDPLL]
	Fin = 32.768khz ... Fout = 96MHz
	Fout = Fin x (LDR + 1 + (LDRFRAC / 16)) x (1 / 2^PRESC)
	96MHZ / 32.768KHZ = 2929.6875
	LDRFRAC = 0.6875 x 16 = 11
	LDR = 2929 - 1 2928
	*/
	OSCCTRL->DPLLRATIO = (OSCCTRL_DPLLRATIO_Type) {
		.bit.LDR = 2928, //96MHz
		.bit.LDRFRAC = 11
	};
	while (OSCCTRL->DPLLSYNCBUSY.bit.DPLLRATIO);

	OSCCTRL->DPLLCTRLB = (OSCCTRL_DPLLCTRLB_Type) {
		.bit.REFCLK = 0, //0:XOSC32K 2:GCLK FROM OSCCTRL_GCLK_ID_FDPLL
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
	while (!OSCCTRL->DPLLSTATUS.bit.CLKRDY && !OSCCTRL->DPLLSTATUS.bit.LOCK);
	while (OSCCTRL->DPLLSYNCBUSY.bit.ENABLE);

	//8MHZ
	GCLK->GENCTRL[GCLK_ID_8MHZ] = (GCLK_GENCTRL_Type ) {
		.bit.DIV = 12,
		.bit.DIVSEL = 0,
		.bit.OE = 0,
		.bit.IDC = 1,
		.bit.GENEN = 1,
		.bit.SRC = GCLK_GENCTRL_SRC_DPLL96M_Val
	};
	while (GCLK->SYNCBUSY.bit.GENCTRL);

	//96MHZ GCLK
	GCLK->GENCTRL[GCLK_ID_96MHZ] = (GCLK_GENCTRL_Type ) {
		.bit.DIV = 0,
		.bit.DIVSEL = 0,
		.bit.OE = 0,
		.bit.IDC = 1,
		.bit.GENEN = 1,
		.bit.SRC = GCLK_GENCTRL_SRC_DPLL96M_Val
	};
	while (GCLK->SYNCBUSY.bit.GENCTRL);

	//MAIN GCLK
	GCLK->GENCTRL[GCLK_ID_48MHZ] = (GCLK_GENCTRL_Type ) {
		.bit.DIV = 2,
		.bit.DIVSEL = 0,
		.bit.OE = 0,
		.bit.IDC = 1,
		.bit.GENEN = 1,
		.bit.SRC = GCLK_GENCTRL_SRC_DPLL96M_Val
	};
	while (GCLK->SYNCBUSY.bit.GENCTRL);
}

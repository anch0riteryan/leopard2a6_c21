#include <mt_pwm.h>
#include <samc21.h>

void init_mt_pwm_pin (void );
void init_mt540_tc (Tc *);
void init_hs_tc (Tc *);

void init_mt_pwm () {
	init_mt_pwm_pin ();

	MCLK->APBCMASK.bit.TC0_ = 1;
	MCLK->APBCMASK.bit.TC1_ = 1;
	MCLK->APBCMASK.bit.TC2_ = 1;
	MCLK->APBCMASK.bit.TC3_ = 1;

	// GCLK TC0 = TC1
	GCLK->PCHCTRL[TC0_GCLK_ID].bit.GEN = 0;
	GCLK->PCHCTRL[TC0_GCLK_ID].bit.CHEN = 1;
	init_mt540_tc (TC0);
	init_mt540_tc (TC1);

	// GCLK TC2 = TC3
	GCLK->PCHCTRL[TC2_GCLK_ID].bit.GEN = 0;
	GCLK->PCHCTRL[TC2_GCLK_ID].bit.CHEN = 1;
	init_hs_tc (TC2);
	init_hs_tc (TC3);
}

void init_mt_pwm_pin () {
	PORT->Group[1].PMUX[5].bit.PMUXE = 0x04;
	PORT->Group[1].PMUX[5].bit.PMUXO = 0x04;
	PORT->Group[1].PMUX[6].bit.PMUXE = 0x04;
	PORT->Group[1].PMUX[6].bit.PMUXO = 0x04;
	PORT->Group[1].PMUX[8].bit.PMUXE = 0x04;
	PORT->Group[1].PMUX[8].bit.PMUXO = 0x04;
	PORT->Group[1].PINCFG[10].reg = PORT_PINCFG_PMUXEN | PORT_PINCFG_DRVSTR;
	PORT->Group[1].PINCFG[11].reg = PORT_PINCFG_PMUXEN | PORT_PINCFG_DRVSTR;
	PORT->Group[1].PINCFG[12].bit.PMUXEN = 1;
	PORT->Group[1].PINCFG[13].bit.PMUXEN = 1;
	PORT->Group[1].PINCFG[16].bit.PMUXEN = 1;
	PORT->Group[1].PINCFG[17].bit.PMUXEN = 1;

	PORT->Group[0].PMUX[10].bit.PMUXE = 0x04;
	PORT->Group[0].PINCFG[20].bit.PMUXEN = 1;
}

void init_mt540_tc (Tc *t) {
	t->COUNT8.CTRLA.bit.SWRST = 1;
	while (t->COUNT8.CTRLA.bit.SWRST);

	TC_CTRLA_Type TIMER_CONFIG = {
		.bit.COPEN0 = 0,
		.bit.COPEN1 = 0,
		.bit.CAPTEN0 = 0,
		.bit.CAPTEN1 = 0,
		.bit.ALOCK = 0,
		.bit.PRESCALER = TC_CTRLA_PRESCALER_DIV64_Val,
		.bit.ONDEMAND = 0,
		.bit.RUNSTDBY = 1,
		.bit.PRESCSYNC = TC_CTRLA_PRESCSYNC_GCLK_Val,
		.bit.MODE = TC_CTRLA_MODE_COUNT8_Val,
		.bit.ENABLE = 0
	};
	t->COUNT8.CTRLA = TIMER_CONFIG;

	t->COUNT8.CTRLBCLR.bit.DIR = 1;
	t->COUNT8.WAVE.bit.WAVEGEN = TC_WAVE_WAVEGEN_NPWM_Val;
	t->COUNT8.DRVCTRL.bit.INVEN0 = 1;
	t->COUNT8.DRVCTRL.bit.INVEN1 = 1;
	//t->COUNT8.INTENSET.bit.OVF = 1;

	t->COUNT8.PERBUF.bit.PERBUF = TC_MAIN_PWM_PERIOD - 1;
	t->COUNT8.PER.bit.PER = TC_MAIN_PWM_PERIOD - 1;
	t->COUNT8.CC[0].bit.CC = 0;
	t->COUNT8.CC[1].bit.CC = 0;
	t->COUNT8.CTRLA.bit.ENABLE = 1;
}

void init_hs_tc (Tc *t) {
	t->COUNT8.CTRLA.bit.SWRST = 1;
	while (t->COUNT8.CTRLA.bit.SWRST);

	TC_CTRLA_Type TIMER_CONFIG = {
		.bit.COPEN0 = 0,
		.bit.COPEN1 = 0,
		.bit.CAPTEN0 = 0,
		.bit.CAPTEN1 = 0,
		.bit.ALOCK = 0,
		.bit.PRESCALER = TC_CTRLA_PRESCALER_DIV1_Val,
		.bit.ONDEMAND = 0,
		.bit.RUNSTDBY = 1,
		.bit.PRESCSYNC = TC_CTRLA_PRESCSYNC_GCLK_Val,
		.bit.MODE = TC_CTRLA_MODE_COUNT8_Val,
		.bit.ENABLE = 0
	};
	t->COUNT8.CTRLA = TIMER_CONFIG;

	t->COUNT8.CTRLBCLR.bit.DIR = 1;
	t->COUNT8.WAVE.bit.WAVEGEN = TC_WAVE_WAVEGEN_NPWM_Val;
	t->COUNT8.DRVCTRL.bit.INVEN0 = 1;
	//t->COUNT8.DRVCTRL.bit.INVEN1 = 1;
	//t->COUNT8.INTENSET.bit.OVF = 1;

	t->COUNT8.PERBUF.bit.PERBUF = TC_MAIN_PWM_PERIOD - 1;
	t->COUNT8.PER.bit.PER = TC_MAIN_PWM_PERIOD - 1;
	t->COUNT8.CC[0].bit.CC = 0;
	t->COUNT8.CC[1].bit.CC = 0;
	t->COUNT8.CTRLA.bit.ENABLE = 1;
}

#include <gpio.h>
#include <samc21.h>

/*
EN_BYPASS PA27
LED_SYS PA28
LED_ERR PB31
LED_FRONT PB22
LED_REAR PB23
*/

const uint32_t PIN_POWER_BYPASS = 1 << 27;
const uint32_t PIN_LED_SYS = 1 << 28;
const uint32_t PIN_LED_ERR = 1 << 30;
const uint32_t PIN_LED_FRONT = 1 << 22;
const uint32_t PIN_LED_REAR = 1 << 23;

void init_gpio () {
	PORT->Group[0].OUTSET.reg = PIN_POWER_BYPASS| PIN_LED_SYS;
	PORT->Group[0].DIRSET.reg = PIN_POWER_BYPASS| PIN_LED_SYS;
	PORT->Group[1].OUTSET.reg = PIN_LED_ERR | PIN_LED_FRONT | PIN_LED_REAR;
	PORT->Group[1].DIRSET.reg = PIN_LED_ERR | PIN_LED_FRONT | PIN_LED_REAR;
}

void gpio_main_pwr_softstart_bypass_enable () {
	PORT->Group[0].OUTCLR.reg = PIN_POWER_BYPASS;
}

void gpio_main_pwr_softstart_bypass_disable () {
	PORT->Group[0].OUTSET.reg = PIN_POWER_BYPASS;
}

void gpio_led_sys_enable () {
	PORT->Group[0].OUTCLR.reg = PIN_LED_SYS;
}

void gpio_led_sys_disable () {
	PORT->Group[0].OUTSET.reg = PIN_LED_SYS;
}

void gpio_led_err_enable () {
	PORT->Group[1].OUTCLR.reg = PIN_LED_ERR;
}

void gpio_led_err_disable () {
	PORT->Group[1].OUTSET.reg = PIN_LED_ERR;
}

void gpio_led_front_enable () {
	PORT->Group[1].OUTCLR.reg = PIN_LED_FRONT;
}

void gpio_led_front_disable () {
	PORT->Group[1].OUTSET.reg = PIN_LED_FRONT;
}

void gpio_led_rear_enable () {
	PORT->Group[1].OUTCLR.reg = PIN_LED_REAR;
}

void gpio_led_rear_disable () {
	PORT->Group[1].OUTSET.reg = PIN_LED_REAR;
}

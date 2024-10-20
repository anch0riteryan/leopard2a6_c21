#include <stdint.h>

#define TCC_PERIOD_US (16000 * 3) //60hz(t = 16ms) and 3cycle without update

void init_ppm_reader (void );

extern volatile uint32_t ppm_width_raw[8];

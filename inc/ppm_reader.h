#include <stdint.h>

#define TCC_PERIOD_US (16000 * 3) //60hz(t = 16ms) and 3cycle without update

#define PPM_WIDTH_MAX_US 1940
#define PPM_WIDTH_MIN_US 1140

void init_ppm_reader (void );
float ppm_phase_linear (uint32_t );
float ppm_phase_digital (uint32_t );

extern volatile uint32_t ppm_width_raw[8];

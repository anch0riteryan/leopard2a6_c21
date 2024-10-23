#include <stdint.h>

#define TCC_PERIOD_US (16000 * 3) //60hz(t = 16ms) and 3cycle without update

#define PPM_WIDTH_NEUTRO_US 1520
#define PPM_WIDTH_MAX_US 1920
#define PPM_WIDTH_MIN_US 1120
#define PPM_WIDTH_GAP_US 19

void init_ppm_reader (void );
float ppm_phase_linear (uint32_t );
float ppm_phase_joystick (uint32_t );
float ppm_phase_3_state_sw (uint32_t );
float ppm_phase_digital (uint32_t );

extern volatile uint32_t ppm_width_raw[8];

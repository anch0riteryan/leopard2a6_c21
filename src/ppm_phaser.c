#include <ppm_reader.h>

const float PPM_RANGE = (float) (PPM_WIDTH_MAX_US - PPM_WIDTH_MIN_US);

float ppm_phase_linear (uint32_t width) {
	float result = 0.0;

	if (width < PPM_WIDTH_MIN_US) {
		result = 0;
	} else if (width > PPM_WIDTH_MAX_US) {
		result = 1;
	} else {
		result = (width - PPM_WIDTH_MIN_US) / PPM_RANGE;
	}

	return result;
}

float ppm_phase_joystick (uint32_t width) {
	float result = 0.0;

	if (width > PPM_WIDTH_NEUTRO_US) {
	} else if (width < PPM_WIDTH_NEUTRO_US) {
	} else {
	}

	return result;
}

float ppm_phase_digital (uint32_t width) {
	float result = 0.0;

	return result;
}

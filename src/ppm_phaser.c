#include <ppm_reader.h>

const float PPM_RANGE = (float) (PPM_WIDTH_MAX_US - PPM_WIDTH_MIN_US);
const float PPM_RANGE_2 = (PPM_RANGE / 2.0);

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

	if (width > PPM_WIDTH_MAX_US) {
		result = 1.0;
	} else if (width < PPM_WIDTH_MIN_US) {
		result = -1.0;
	} else {
		if (width > (PPM_WIDTH_NEUTRO_US + PPM_WIDTH_GAP_US)) {
			result = ((int32_t) width - PPM_WIDTH_NEUTRO_US) / PPM_RANGE_2;
		} else if (width < (PPM_WIDTH_NEUTRO_US - PPM_WIDTH_GAP_US)) {
			result = ((int32_t) width - PPM_WIDTH_NEUTRO_US) / PPM_RANGE_2;
		} else {
			width = 0.0;
		}
	}

	return result;
}

float ppm_phase_3_state_sw (uint32_t width) {
	float result = 0.0;

	if (width > (PPM_WIDTH_MAX_US - PPM_WIDTH_GAP_US)) {
		result = 1.0;
	} else if (width > (PPM_WIDTH_NEUTRO_US - PPM_WIDTH_GAP_US)) {
		result = 0.0;
	} else {
		result = -1.0;
	}

	return result;
}

float ppm_phase_digital (uint32_t width) {
	float result = 0.0;

	return result;
}

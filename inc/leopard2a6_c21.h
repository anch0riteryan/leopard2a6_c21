#include <samc21.h>

typedef struct _task {
	uint8_t is_1hz : 1;
	uint8_t is_10hz : 1;
	uint8_t is_100hz : 1;
	uint8_t is_30hz : 1;
	uint8_t is_60hz : 1;
} Task;
extern Task routine;

void init_system_clk_48mhz (void );

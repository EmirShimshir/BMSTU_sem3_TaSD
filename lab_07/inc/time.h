#ifndef __TIME_H__
#define __TIME_H__

#include <inttypes.h>

void get_now_time(float *time, float t1, float t2);

uint64_t get_time_ticks(void);

#endif // __TIME_H__
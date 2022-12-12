#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../inc/time.h"
#define TIME (float)rand() / RAND_MAX


void get_now_time(float *time, float t1, float t2)
{
    *time = (t2 - t1) * (float)(TIME) + t1;
}

uint64_t get_time_ticks(void)
{
    uint32_t high, low;
    __asm__ __volatile__(
        "rdtsc\n"
        "movl %%edx, %0\n"
        "movl %%eax, %1\n"
        : "=r"(high), "=r"(low)::"%rax", "%rbx", "%rcx", "%rdx");

    uint64_t ticks = ((uint64_t)high << 32) | low;

    return ticks;
}
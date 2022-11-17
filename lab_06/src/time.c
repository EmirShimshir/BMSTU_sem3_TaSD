#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#include "../inc/time.h"

unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return val.tv_sec * 1000ULL * 1000ULL + val.tv_usec;
}
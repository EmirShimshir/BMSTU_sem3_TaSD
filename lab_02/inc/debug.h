#ifndef __DEBUG_H__

#define __DEBUG_H__

#include <stdio.h>

char *get_err_name(int err);

#define NORMAL "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[36m"
#define MAGENTA "\x1B[35m"

#ifdef DEBUG
#define LOG_INFO(...) printf("%sINFO%s | %-20s | %s\n" , MAGENTA, NORMAL, __func__, __VA_ARGS__)
#define LOG_DEBUG(FORMAT, ...) printf("%sDEBUG%s | %-20s | " FORMAT "\n" , BLUE, NORMAL, __func__, __VA_ARGS__)
#define LOG_ERROR(...) printf("%sERROR%s | %-20s | %s\n" , RED, NORMAL, __func__, get_err_name(__VA_ARGS__))
#else
#define LOG_INFO(...)
#define LOG_DEBUG(FORMAT, ...)
#define LOG_ERROR(...)
#endif

#endif // __DEBUG_H__

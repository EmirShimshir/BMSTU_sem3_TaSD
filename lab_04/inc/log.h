#ifndef __LOG_H__

#define __LOG_H__

#include <stdio.h>

#define COLOR_WHITE "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[36m"
#define COLOR_MAGENTA "\x1B[35m"

char *get_err_name(int err);

#ifdef DEBUG
#define LOG_INFO(...) printf("%sINFO%s  | %-25s | %s\n" , COLOR_MAGENTA, COLOR_WHITE, __func__, __VA_ARGS__)
#define LOG_DEBUG(FORMAT, ...) printf("%sDEBUG%s | %-25s | " FORMAT "\n" , COLOR_BLUE, COLOR_WHITE, __func__, __VA_ARGS__)
#define LOG_ERROR(...) printf("%sERROR%s | %-25s | %s\n" , COLOR_RED, COLOR_WHITE, __func__, get_err_name(__VA_ARGS__))
#else
#define LOG_INFO(...)
#define LOG_DEBUG(FORMAT, ...)
#define LOG_ERROR(...)
#endif

#endif // __LOG_H__

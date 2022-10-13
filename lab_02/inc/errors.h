#ifndef __ERRORS_H__

#define __ERRORS_H__

#include <stdio.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[36m"

#ifdef DEBUG
#define LOG_INFO(...) printf("%sINFO%s | %-20s | %s\n" , RED, RESET, __func__, __VA_ARGS__)
#define LOG_DEBUG(FORMAT, ...) printf("%sDEBUG%s | %-20s | " FORMAT "\n" , BLUE, RESET, __func__, __VA_ARGS__)
#define LOG_ERROR(...) printf("%sERROR%s | %-20s | %s\n" , RED, RESET, __func__, __VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOG_DEBUG(FORMAT, ...)
#define LOG_ERROR(...)
#endif

#endif // __ERRORS_H__

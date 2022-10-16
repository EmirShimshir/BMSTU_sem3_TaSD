#ifndef __DEBUG_H__

#define __DEBUG_H__

#include <stdio.h>

char *get_err_name(int err);

#define NORMALD "\033[0m"
#define REDD "\033[31m"
#define GREEND "\033[32m"
#define BLUED "\033[36m"
#define MAGENTAD "\x1B[35m"

#ifdef DEBUG
#define LOG_INFO(...) printf("%sINFO%s  | %-20s | %s\n" , MAGENTAD, NORMALD, __func__, __VA_ARGS__)
#define LOG_DEBUG(FORMAT, ...) printf("%sDEBUG%s | %-20s | " FORMAT "\n" , BLUED, NORMALD, __func__, __VA_ARGS__)
#define LOG_ERROR(...) printf("%sERROR%s | %-20s | %s\n" , REDD, NORMALD, __func__, get_err_name(__VA_ARGS__))
#else
#define LOG_INFO(...)
#define LOG_DEBUG(FORMAT, ...)
#define LOG_ERROR(...)
#endif

#endif // __DEBUG_H__

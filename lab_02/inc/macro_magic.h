#ifndef UNIVERSAL_MENU_MACRO_MAGIC_H
#define UNIVERSAL_MENU_MACRO_MAGIC_H

#include "stdlib.h"

#define M5(X1, X2, ...) X1 X2;
#define M4(X1, X2, ...) X1 X2; __VA_OPT__(M5(__VA_ARGS__))
#define M3(X1, X2, ...) X1 X2; __VA_OPT__(M4(__VA_ARGS__))
#define M2(X1, X2, ...) X1 X2; __VA_OPT__(M3(__VA_ARGS__))
#define M1(X1, X2, ...) X1 X2; __VA_OPT__(M2(__VA_ARGS__))

#define P5(X1, X2, ...) tmp->X2 = X2;
#define P4(X1, X2, ...) tmp->X2 = X2; __VA_OPT__(P5(__VA_ARGS__))
#define P3(X1, X2, ...) tmp->X2 = X2; __VA_OPT__(P4(__VA_ARGS__))
#define P2(X1, X2, ...) tmp->X2 = X2; __VA_OPT__(P3(__VA_ARGS__))
#define P1(X1, X2, ...) tmp->X2 = X2; __VA_OPT__(P2(__VA_ARGS__))

#define A5(X1, X2, ...) X1 X2
#define A4(X1, X2, ...) X1 X2 __VA_OPT__(,) __VA_OPT__(A5(__VA_ARGS__))
#define A3(X1, X2, ...) X1 X2 __VA_OPT__(,) __VA_OPT__(A4(__VA_ARGS__))
#define A2(X1, X2, ...) X1 X2 __VA_OPT__(,) __VA_OPT__(A3(__VA_ARGS__))
#define A1(X1, X2, ...) X1 X2 __VA_OPT__(,) __VA_OPT__(A2(__VA_ARGS__))

#define PACK_STRUCT(FUNC_NAME, ...) \
struct FUNC_NAME##_args * FUNC_NAME##_pack(A1(__VA_ARGS__))                   \
{                                                                             \
    struct FUNC_NAME##_args* tmp = malloc(sizeof(struct FUNC_NAME##_args));   \
    P1(__VA_ARGS__) \
    return tmp;     \
}                   \

#define UNPACK_ARGS(FUNC, STRUCT_NAME) \
          struct FUNC##_args* args = (struct FUNC##_args*)STRUCT_NAME


#define ARG_PACKER(FUNC_NAME, ...) struct FUNC_NAME##_args {M1(__VA_ARGS__)}; \
PACK_STRUCT(FUNC_NAME, __VA_ARGS__)                                           \


#endif //UNIVERSAL_MENU_MACRO_MAGIC_H

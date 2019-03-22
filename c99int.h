#indef C99INT_H
#define C99INT_H
#include <stdint.h>

typedef char int8_t new_char;
typedef unsigned char uint8_t new_unsigned_char;

typedef short int16_t new_short;
typedef unsigned short uint16_t new_unsigned_short;

typedef int8_t new_int_8;
typedef int16_t new_int_16;
typedef int32_t new_int_32;
typedef int64_t new_int_64;

typedef unsigned uint8_t new_unsigned_int_8;
typedef unsigned uint16_t new_unsigned_int_16;
typedef unsigned uint32_t new_unsigned_int_32;
typedef unsigned uint64_t new_unsigned_int_64;

typedef long int32_t new_long_32;
typedef long int64_t new_long_64;

typedef unsigned long uint32_t new_unsigned_long_32;
typedef unsigned long uint64_t new_unsigned_long_64;

typedef long long int64_t new_long_long;

typedef unsigned long uint64_t new_unsigned_long_long;

#endif

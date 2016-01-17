# 1 ".././format.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 ".././format.c"
# 1 ".././format.h" 1

# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/pgmspace.h" 1 3
# 86 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/pgmspace.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 1 3
# 37 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/include/stdint.h" 1 3 4


# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 1 3 4
# 121 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));

typedef int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
# 142 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 159 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int8_t int_least8_t;




typedef uint8_t uint_least8_t;




typedef int16_t int_least16_t;




typedef uint16_t uint_least16_t;




typedef int32_t int_least32_t;




typedef uint32_t uint_least32_t;







typedef int64_t int_least64_t;






typedef uint64_t uint_least64_t;
# 213 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int8_t int_fast8_t;




typedef uint8_t uint_fast8_t;




typedef int16_t int_fast16_t;




typedef uint16_t uint_fast16_t;




typedef int32_t int_fast32_t;




typedef uint32_t uint_fast32_t;







typedef int64_t int_fast64_t;






typedef uint64_t uint_fast64_t;
# 273 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/stdint.h" 3 4
typedef int64_t intmax_t;




typedef uint64_t uintmax_t;
# 4 "/usr/lib/gcc/avr/4.5.3/include/stdint.h" 2 3 4
# 38 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 2 3
# 77 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/inttypes.h" 3
typedef int32_t int_farptr_t;



typedef uint32_t uint_farptr_t;
# 87 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/pgmspace.h" 2 3
# 1 "/usr/lib/gcc/avr/4.5.3/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/avr/4.5.3/include/stddef.h" 3 4
typedef unsigned int size_t;
# 88 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/pgmspace.h" 2 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 1 3
# 99 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/sfr_defs.h" 1 3
# 100 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3
# 222 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/iom328p.h" 1 3
# 223 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3
# 432 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 3
# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/portpins.h" 1 3
# 433 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3

# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/common.h" 1 3
# 435 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3

# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/version.h" 1 3
# 437 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3


# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/fuse.h" 1 3
# 239 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/fuse.h" 3
typedef struct
{
    unsigned char low;
    unsigned char high;
    unsigned char extended;
} __fuse_t;
# 440 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3


# 1 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/lock.h" 1 3
# 443 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/io.h" 2 3
# 89 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/pgmspace.h" 2 3
# 217 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/pgmspace.h" 3
typedef void prog_void __attribute__((__progmem__));
typedef char prog_char __attribute__((__progmem__));
typedef unsigned char prog_uchar __attribute__((__progmem__));

typedef int8_t prog_int8_t __attribute__((__progmem__));
typedef uint8_t prog_uint8_t __attribute__((__progmem__));
typedef int16_t prog_int16_t __attribute__((__progmem__));
typedef uint16_t prog_uint16_t __attribute__((__progmem__));
typedef int32_t prog_int32_t __attribute__((__progmem__));
typedef uint32_t prog_uint32_t __attribute__((__progmem__));

typedef int64_t prog_int64_t __attribute__((__progmem__));
typedef uint64_t prog_uint64_t __attribute__((__progmem__));
# 907 "/usr/lib/gcc/avr/4.5.3/../../../avr/include/avr/pgmspace.h" 3
extern const prog_void * memchr_P(const prog_void *, int __val, size_t __len) __attribute__((__const__));
extern int memcmp_P(const void *, const prog_void *, size_t) __attribute__((__pure__));
extern void *memccpy_P(void *, const prog_void *, int __val, size_t);
extern void *memcpy_P(void *, const prog_void *, size_t);
extern void *memmem_P(const void *, size_t, const prog_void *, size_t) __attribute__((__pure__));
extern const prog_void * memrchr_P(const prog_void *, int __val, size_t __len) __attribute__((__const__));
extern char *strcat_P(char *, const prog_char *);
extern const prog_char * strchr_P(const prog_char *, int __val) __attribute__((__const__));
extern const prog_char * strchrnul_P(const prog_char *, int __val) __attribute__((__const__));
extern int strcmp_P(const char *, const prog_char *) __attribute__((__pure__));
extern char *strcpy_P(char *, const prog_char *);
extern int strcasecmp_P(const char *, const prog_char *) __attribute__((__pure__));
extern char *strcasestr_P(const char *, const prog_char *) __attribute__((__pure__));
extern size_t strcspn_P(const char *__s, const prog_char * __reject) __attribute__((__pure__));
extern size_t strlcat_P (char *, const prog_char *, size_t );
extern size_t strlcpy_P (char *, const prog_char *, size_t );
extern size_t strlen_P(const prog_char *) __attribute__((__const__));
extern size_t strnlen_P(const prog_char *, size_t) __attribute__((__const__));
extern int strncmp_P(const char *, const prog_char *, size_t) __attribute__((__pure__));
extern int strncasecmp_P(const char *, const prog_char *, size_t) __attribute__((__pure__));
extern char *strncat_P(char *, const prog_char *, size_t);
extern char *strncpy_P(char *, const prog_char *, size_t);
extern char *strpbrk_P(const char *__s, const prog_char * __accept) __attribute__((__pure__));
extern const prog_char * strrchr_P(const prog_char *, int __val) __attribute__((__const__));
extern char *strsep_P(char **__sp, const prog_char * __delim);
extern size_t strspn_P(const char *__s, const prog_char * __accept) __attribute__((__pure__));
extern char *strstr_P(const char *, const prog_char *) __attribute__((__pure__));
extern char *strtok_P(char *__s, const prog_char * __delim);
extern char *strtok_rP(char *__s, const prog_char * __delim, char **__last);

extern size_t strlen_PF (uint_farptr_t src) __attribute__((__const__));
extern size_t strnlen_PF (uint_farptr_t src, size_t len) __attribute__((__const__));
extern void *memcpy_PF (void *dest, uint_farptr_t src, size_t len);
extern char *strcpy_PF (char *dest, uint_farptr_t src);
extern char *strncpy_PF (char *dest, uint_farptr_t src, size_t len);
extern char *strcat_PF (char *dest, uint_farptr_t src);
extern size_t strlcat_PF (char *dst, uint_farptr_t src, size_t siz);
extern char *strncat_PF (char *dest, uint_farptr_t src, size_t len);
extern int strcmp_PF (const char *s1, uint_farptr_t s2) __attribute__((__pure__));
extern int strncmp_PF (const char *s1, uint_farptr_t s2, size_t n) __attribute__((__pure__));
extern int strcasecmp_PF (const char *s1, uint_farptr_t s2) __attribute__((__pure__));
extern int strncasecmp_PF (const char *s1, uint_farptr_t s2, size_t n) __attribute__((__pure__));
extern char *strstr_PF (const char *s1, uint_farptr_t s2);
extern size_t strlcpy_PF (char *dst, uint_farptr_t src, size_t siz);
extern int memcmp_PF(const void *, uint_farptr_t, size_t) __attribute__((__pure__));
# 3 ".././format.h" 2

typedef unsigned char u8;
typedef char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef long s32;


extern const u16 periodTable[(12*3)];
# 25 ".././format.h"
struct sections_s
{
    u8 numinsts;
    u16 offsetinsts;
    u8 numorders;
    u16 offsetorders;
    u8 numpatterns;
    u16 offsetpatterns;
    u8 numsamples;
    u16 offsetsamples;
    u8 numnames;
    u16 offsetnames;
};
# 2 ".././format.c" 2

const u16 periodTable[(12*3)] =
{
    856,808,762,720,678,640,604,570,538,508,480,453,
    428,404,381,360,339,320,302,285,269,254,240,226,
    214,202,190,180,170,160,151,143,135,127,120,113
};

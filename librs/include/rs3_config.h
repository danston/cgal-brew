#ifndef _rs3_config_h
#define _rs3_config_h

#if (defined(__STDC__) || defined(WIN32) || defined(WIN64))
#include <stdarg.h>
#else
#include <varargs.h>
#endif

#ifdef RS3_USE_THREADS
#include <pthread.h>
#endif

/* ******************************************* *
   MACHINE INTEGERS
   ******************************************* */
#ifdef RS_SPEC_UI32
#include <unistd.h>
#include <sys/utsname.h>
typedef int16_t RS3_I16;
typedef uint16_t RS3_UI16;
typedef int32_t RS3_I32;
typedef uint32_t RS3_UI32;
typedef uint64_t RS3_UI64;
typedef int64_t RS3_I64;
#else

#if (defined(WIN32)) || (defined(WIN64))
typedef __int16  RS3_I16;
typedef unsigned __int16  RS3_UI16;
typedef __int32  RS3_I32;
typedef unsigned __int32  RS3_UI32;
typedef __int64  RS3_I64;
typedef unsigned __int64  RS3_UI64;
#else
#include <stdint.h>
typedef __int16_t  RS3_I16;
typedef __uint16_t RS3_UI16;
typedef __int32_t  RS3_I32;
typedef __uint32_t RS3_UI32;
typedef __uint64_t RS3_UI64;
typedef __int64_t RS3_I64;
#endif

#endif

/* ******************************************* *
   prime numbers
   ******************************************* */

/*#ifdef RS3_64BIT*/

#if 0
#include <limits.h>

#if ULONG_MAX == 18446744073709551615U
typedef __uint64_t RS3_ZP;
typedef __uint128_t RS3_DZP;


#define RS3_MIN_PRIME 9223372036854340679
#define RS3_MAX_PRIME 9223372036854775783
#define RS3_NB_PRIMES 100000
#define RS3_PRIMES_SIZE_IN_BITS 64
#define RS3_ZPHALFMAXINT 1

#else
typedef RS3_UI32 RS3_ZP;
typedef RS3_UI64 RS3_DZP;

#define RS3_MIN_PRIME 2145338339
#define RS3_MAX_PRIME 2147483647
#define RS3_NB_PRIMES 100000
#define RS3_PRIMES_SIZE_IN_BITS 32
#define RS3_ZPHALFMAXINT 1
#endif

#else

typedef RS3_UI32 RS3_ZP;

typedef RS3_UI64 RS3_DZP;

#define RS3_MIN_PRIME 2145338339
#define RS3_MAX_PRIME 2147483647
#define RS3_NB_PRIMES 100000
#define RS3_PRIMES_SIZE_IN_BITS 32

#endif

/* ******************************************* *
   various
   ******************************************* */

typedef RS3_I32 RS3_INT;
typedef RS3_I32 RS3_LOOP;

#endif

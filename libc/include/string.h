#ifndef _STRING_H
#define _STRING_H

#include "sys/cdefs.h"

#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

int memcmp(const void *aptr, const void *bptr, size_t size);
void* memcpy(void *dstptr, const void *srcptr, size_t size);
void* memmove(void *dstptr, const void *srcptr, size_t size);
void* memset(void *bufptr, int value, size_t size);

long unsigned int strlen(const char *str);
int strcmp(const char *str1, const char *str2);

#ifdef __cplusplus
}
#endif

#endif

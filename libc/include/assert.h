#ifndef _ASSERT_H
#define _ASSERT_H

#ifdef NDEBUG
	#define assert()
#else
	#define assert(expr) (void)((expr) || (__assert(__FILE__, __LINE__, __func__, #expr), 0))
#endif

#ifdef __cplusplus
extern "C" {
#endif

void __assert(const char *file, int line, const char* func, const char* expr);

#ifdef __cplusplus
}
#endif

#endif


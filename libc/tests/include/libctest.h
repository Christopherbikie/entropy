#ifndef _LIBCTEST_H
#define _LIBCTEST_H

#define test(expr, msg) (void)((expr) || (__test_fail(__FILE__, __LINE__, __func__, #msg), 0))

void __test_fail(const char *file, int line, const char *func, const char *msg);

#endif // _LIBCTEST.H


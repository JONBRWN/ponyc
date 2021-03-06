#ifndef PLATFORM_PONYASSERT_H
#define PLATFORM_PONYASSERT_H

#include "platform.h"
#include <assert.h>

PONY_EXTERN_C_BEGIN

#if defined(PONY_NO_ASSERT)
#  define pony_assert(expr) assert(expr)
#else
#  define pony_assert(expr) \
    ((expr) ? (void)0 : \
      ponyint_assert_fail(#expr, __FILE__, __LINE__, __func__))
#endif

void ponyint_assert_fail(const char* expr, const char* file, size_t line,
  const char* func);

PONY_EXTERN_C_END

#endif

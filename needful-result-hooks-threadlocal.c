/*
**  file: %needful-result-hooks-threadlocal.c
**  summary: "Ready-made Result(T) hooks over a per-thread failure slot"
**  homepage: https://needful.metaeducation.com/threading
**
******************************************************************************
**
** Copyright 2015-2026 metaeducation.com
**
** Licensed under the MIT License
**
** https://en.wikipedia.org/wiki/MIT_License
**
******************************************************************************
**
** See %needful-result-hooks-threadlocal.h.  Compile this file into
** your program exactly once.
**
** 1. This needs only thread-local *storage*, not a threading library: the
**    `_Thread_local` keyword in C11, or `thread_local` if this file is built
**    as C++.  (`<threads.h>` isn't required, and isn't available to C++.)
**    Older GCC/Clang and MSVC get their compiler-specific spellings.
*/

#include <stdio.h>   /* fprintf, fflush, stderr */
#include <stdlib.h>  /* exit */

#include "needful-result-hooks-threadlocal.h"

#if defined(__cplusplus)  /* [1] */
    #define NEEDFUL_THREAD_LOCAL  thread_local
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    #define NEEDFUL_THREAD_LOCAL  _Thread_local
#elif defined(_MSC_VER)
    #define NEEDFUL_THREAD_LOCAL  __declspec(thread)
#elif defined(__GNUC__) || defined(__clang__)
    #define NEEDFUL_THREAD_LOCAL  __thread
#else
    #error "No thread-local storage; see needful-result-hooks-singlethreaded.h"
#endif

static NEEDFUL_THREAD_LOCAL const char* t_needful_failure = NEEDFUL_NULLPTR;

const char* Needful_Get_Failure(void) {
    return t_needful_failure;
}

void Needful_Set_Failure(const char* error) {
    t_needful_failure = error;
}

const char* Needful_Test_And_Clear_Failure(void) {
    const char* error = t_needful_failure;
    t_needful_failure = NEEDFUL_NULLPTR;
    return error;
}

NEEDFUL_NORETURN void Needful_Panic_Abruptly(const char* error) {
    fprintf(stderr, "Panic: %s\n", error);
    fflush(stderr);
    exit(1);
}

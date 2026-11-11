/*
**  file: %needful-result-hooks-threadlocal.h
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
** Like %needful-result-hooks-singlethreaded.h, but each thread gets its own
** pending failure, so threads can't see or clear each other's errors.
**
** Include this header wherever Result(T) is used, and compile
** %needful-result-hooks-threadlocal.c into your program once.
**
** 1. All four hooks are real functions, and the thread-local slot itself is
**    private to the .c file.  Sharing a thread-local *variable* across the C
**    and C++ boundary doesn't link everywhere: C++ reaches an `extern`
**    thread_local through a generated wrapper function that a variable
**    defined in C never gets (macOS's linker refuses; Linux's tolerates it).
*/

#ifndef NEEDFUL_RESULT_HOOKS_THREADLOCAL_H
#define NEEDFUL_RESULT_HOOKS_THREADLOCAL_H

#include "needful.h"

#ifdef __cplusplus
extern "C" {
#endif

const char* Needful_Get_Failure(void);  /* functions, not macros [1] */

void Needful_Set_Failure(const char* error);

const char* Needful_Test_And_Clear_Failure(void);

NEEDFUL_NORETURN void Needful_Panic_Abruptly(const char* error);

#ifdef __cplusplus
}
#endif

#endif  /* NEEDFUL_RESULT_HOOKS_THREADLOCAL_H */

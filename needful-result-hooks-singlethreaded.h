/*
**  file: %needful-result-hooks-singlethreaded.h
**  summary: "Ready-made Result(T) hooks over one global failure slot"
**  homepage: https://needful.metaeducation.com/result#setup-result-hooks
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
** Result(T) needs four hooks to store its pending failure.  These implement
** them over a single global `const char*`, which is all a single-threaded
** program needs.  (For threads, use %needful-result-hooks-threadlocal.h.)
**
** Include this header wherever Result(T) is used, and compile
** %needful-result-hooks-singlethreaded.c into your program once.
*/

#ifndef NEEDFUL_RESULT_HOOKS_SINGLETHREADED_H
#define NEEDFUL_RESULT_HOOKS_SINGLETHREADED_H

#include "needful.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* g_needful_failure;

const char* Needful_Test_And_Clear_Failure(void);

NEEDFUL_NORETURN void Needful_Panic_Abruptly(const char* error);

#ifdef __cplusplus
}
#endif

#define Needful_Get_Failure()  g_needful_failure

#define Needful_Set_Failure(error)  (g_needful_failure = (error))

#endif  /* NEEDFUL_RESULT_HOOKS_SINGLETHREADED_H */

/*
**  file: %needful-result-hooks-singlethreaded.c
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
** See %needful-result-hooks-singlethreaded.h.  Compile this file into
** your program exactly once.
*/

#include <stdio.h>   /* fprintf, fflush, stderr */
#include <stdlib.h>  /* exit */

#include "needful-result-hooks-singlethreaded.h"

const char* g_needful_failure = NEEDFUL_NULLPTR;

const char* Needful_Test_And_Clear_Failure(void) {
    const char* error = g_needful_failure;
    g_needful_failure = NEEDFUL_NULLPTR;
    return error;
}

NEEDFUL_NORETURN void Needful_Panic_Abruptly(const char* error) {
    fprintf(stderr, "Panic: %s\n", error);
    fflush(stderr);
    exit(1);
}

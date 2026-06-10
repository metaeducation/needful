# [`needful.h`](https://raw.githubusercontent.com/metaeducation/ren-c/refs/heads/master/src/include/needful.h)

This is the repository holding the single-C-header file for building codebases
that get extra checking from C++ files in in the needful-enhanced repository.

The file is somewhat self-documenting in terms of its purpose:

  https://raw.githubusercontent.com/metaeducation/needful/refs/heads/main/src/include/needful.h

But for detailed usage documentation, see the website:

  https://needful.metaeducation.com

Projects using Needful should typically add a snapshot of a version of `needful.h` 
file to their git, so the project can be cloned and built as C without needing
any special submodules or other administrative headaches.  Then individual
developers (or CI builds) can add the C++ files from needful-enhanced on their
systems in order to get extra checking that `#define NEEDFUL_CPP_ENHANCED 1`
would provide.

The C++ enhanced files live here, for when you want to build with checks enabled:

  https://github.com/metaeducation/needful-enhanced/



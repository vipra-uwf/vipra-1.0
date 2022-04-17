AC_INIT([VIPRA], [0.1])
AM_INIT_AUTOMAKE([no-define])
AC_LANG([C++])
AC_PROG_CXX
AC_CONFIG_SRCDIR([generated_main.cpp])
CXXFLAGS="-I/usr/include/antlr4-runtime"
AC_CHECK_HEADERS([antlr4-runtime.h], [], [AC_MSG_ERROR([MISSING ANTLR4: The Antlr4 Runtime is required to compile VIPRA])])
CXXFLAGS=""
AC_CONFIG_FILES([Makefile])
AC_OUTPUT()
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([MicroOnlineGo], [1.0], [wang691234@gmail.com])
AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE(MicroOnlineGo,1.0)
# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_PROG_RANLIB
# Checks for header files.
AC_CHECK_HEADERS([netinet/in.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UID_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([atexit bzero memchr strrchr])

AC_CONFIG_FILES([Makefile
                 lib/redbud/parser/Makefile
                 lib/muduo/Makefile
                 lib/muduo/base/Makefile
                 lib/muduo/net/Makefile
                 src/Makefile])
AC_OUTPUT

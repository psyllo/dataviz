#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])

AC_INIT([dataviz], [0.1], [psyllo@gmail.com])
AC_CONFIG_SRCDIR([tutorial1/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([GLFW], [glfw3 >= 3.0.4])
#AC_SEARCH_LIBS([glfwInit], [glfw])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])
#AC_CHECK_HEADERS([GLFW/glfw3.h])


# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 tutorial1/Makefile])
AC_OUTPUT

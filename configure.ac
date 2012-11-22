AC_PREREQ(2.60)
AC_INIT([abc],
        [4],
        [abc-devel@example.com],
        [abc],
        [http://www.example.com/abc/])
AC_CONFIG_SRCDIR([src/libabc.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_LIBOBJ_DIR([portable])
AM_INIT_AUTOMAKE([check-news foreign 1.11 -Wall -Werror -Wno-portability silent-rules tar-pax no-dist-gzip dist-xz subdir-objects])
AM_MAINTAINER_MODE
AC_PROG_CC_STDC
AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE
AC_CONFIG_MACRO_DIR([m4])
AM_SILENT_RULES([yes])
LT_INIT([disable-static pic-only])
AC_PREFIX_DEFAULT([/usr])

AC_PROG_SED
AC_PROG_MKDIR_P

AC_ARG_ENABLE([logging],
        AS_HELP_STRING([--disable-logging], [disable system logging @<:@default=enabled@:>@]),
        [], enable_logging=yes)
AS_IF([test "x$enable_logging" = "xyes"], [
        AC_DEFINE(ENABLE_LOGGING, [1], [System logging.])
])

AC_ARG_ENABLE([debug],
        AS_HELP_STRING([--enable-debug], [enable debug messages @<:@default=disabled@:>@]),
        [], [enable_debug=no])
AS_IF([test "x$enable_debug" = "xyes"], [
        AC_DEFINE(ENABLE_DEBUG, [1], [Debug messages.])
])

my_CFLAGS="-pedantic -Wall -Wextra \
-Wmissing-declarations -Wmissing-prototypes \
-Wnested-externs -Wsign-compare \
-Wstrict-prototypes -Wshadow \
-Wformat-security"
AC_SUBST([my_CFLAGS])

AC_CONFIG_HEADERS(config.h)
AC_CONFIG_FILES([
        Makefile
])

AC_OUTPUT
AC_MSG_RESULT([
        $PACKAGE $VERSION
        =====

        prefix:                 ${prefix}
        sysconfdir:             ${sysconfdir}
        libdir:                 ${libdir}
        includedir:             ${includedir}

        compiler:               ${CC}
        cflags:                 ${CFLAGS}
        ldflags:                ${LDFLAGS}

        logging:                ${enable_logging}
        debug:                  ${enable_debug}
])

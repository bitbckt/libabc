ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
EXTRA_DIST =
CLEANFILES =
MAINTAINERCLEANFILES = Makefile.in aclocal.m4 build-aux/compile \
            build-aux/config.guess build-aux/config.sub build-aux/depcomp \
            build-aux/install-sh build-aux/ltmain.sh build-aux/missing \
            config.h.in config.h.in~ configure m4/libtool.m4 m4/ltoptions.m4 \
            m4/ltsugar.m4 m4/ltversion.m4 m4/lt~obsolete.m4
AM_MAKEFLAGS = --no-print-directory

AM_CPPFLAGS = \
	-include $(top_builddir)/config.h \
	-DSYSCONFDIR=\""$(sysconfdir)"\" \
	-DLIBEXECDIR=\""$(libexecdir)"\" \
	-I${top_srcdir}/include \
	-I${top_srcdir}/src

AM_CFLAGS = ${my_CFLAGS} \
	-fvisibility=hidden \
	-ffunction-sections \
	-fdata-sections

AM_LDFLAGS = \
	-Wl,--gc-sections \
	-Wl,--as-needed

SED_PROCESS = \
	$(AM_V_GEN)$(MKDIR_P) $(dir $@) && $(SED) \
	-e 's,@VERSION\@,$(VERSION),g' \
	-e 's,@prefix\@,$(prefix),g' \
	-e 's,@exec_prefix\@,$(exec_prefix),g' \
	-e 's,@libdir\@,$(libdir),g' \
	-e 's,@includedir\@,$(includedir),g' \
	< $< > $@ || rm $@

%.pc: %.pc.in Makefile
	$(SED_PROCESS)

LIBABC_CURRENT=2
LIBABC_REVISION=0
LIBABC_AGE=2

pkginclude_HEADERS = include/abc/libabc.h
lib_LTLIBRARIES = src/libabc.la

src_libabc_la_SOURCES =\
	src/libabc-private.h \
	src/libabc.c

EXTRA_DIST += src/libabc.sym

src_libabc_la_LDFLAGS = $(AM_LDFLAGS) \
	-version-info $(LIBABC_CURRENT):$(LIBABC_REVISION):$(LIBABC_AGE) \
	-Wl,--version-script=$(top_srcdir)/src/libabc.sym
src_libabc_la_DEPENDENCIES = ${top_srcdir}/src/libabc.sym

pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = src/libabc.pc
EXTRA_DIST += src/libabc.pc.in
CLEANFILES += src/libabc.pc

TESTS = src/test-libabc

check_PROGRAMS = src/test-libabc
src_test_libabc_SOURCES = src/test-libabc.c
src_test_libabc_LDADD = src/libabc.la

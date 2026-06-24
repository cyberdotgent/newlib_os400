multilibtool_LIBRARIES += %D%/libos400mi.a
%C%_libos400mi_a_SOURCES = \
	%D%/syscalls.c

AM_CPPFLAGS += -I$(srcroot)/newlib-obj/targ-include -I$(srcroot)/newlib/libc/include

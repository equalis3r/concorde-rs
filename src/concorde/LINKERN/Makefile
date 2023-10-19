# Generated automatically from Makefile.in by configure.
#
#   This file is part of CONCORDE
#
#   (c) Copyright 1995--1999 by David Applegate, Robert Bixby,
#   Vasek Chvatal, and William Cook
#
#   Permission is granted for academic research use.  For other uses,
#   contact the authors for licensing options.
#
#   Use at your own risk.  We make no guarantees about the
#   correctness or usefulness of this code.
#


SHELL = /usr/bin/sh
SRCROOT = ..
BLDROOT = ..
CCINCDIR=$(SRCROOT)/INCLUDE

srcdir = .

CC = gcc
CFLAGS = -g -O2  -I$(BLDROOT)/INCLUDE -I$(CCINCDIR)
LDFLAGS = -g -O2 
LIBFLAGS = -liberty -lbfd -lm 
RANLIB = ranlib

OBJ_SUFFIX = o
o = $(OBJ_SUFFIX)

THISLIB=linkern.a
LIBSRCS=linkern.c flip_two.c lk.c

LIBS=$(BLDROOT)/EDGEGEN/edgegen.a

all: $(THISLIB)

everything: all

clean:
	-rm -f *.$o $(THISLIB) linkern

OBJS=$(LIBSRCS:.c=.o)

$(THISLIB): $(OBJS)
#	$(AR) $(ARFLAGS) $(THISLIB) $(OBJS)
#	$(RANLIB) $(THISLIB)

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(CCINCDIR)
I2=$(BLDROOT)/INCLUDE

flip_two.$o: flip_two.c $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     \
        $(I)/linkern.h  
linkern.$o:  linkern.c  $(I)/machdefs.h $(I2)/config.h  $(I)/linkern.h  \
        $(I)/util.h     $(I)/macrorus.h 
lk.$o:  lk.c  $(I)/machdefs.h $(I2)/config.h  $(I)/linkern.h  \
        $(I)/util.h     $(I)/edgegen.h  $(I)/macrorus.h 

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

THISLIB=util.a
LIBSRCS=allocrus.c util.c  dheaps_i.c edgelen.c edgeutil.c \
        sortrus.c  urandom.c  \

ALLSRCS=$(LIBSRCS)

all: $(THISLIB)

everything: all

clean:
	-rm -f *.$o $(THISLIB)

OBJS=$(LIBSRCS:.c=.o)

$(THISLIB): $(OBJS)
#	$(AR) $(ARFLAGS) $(THISLIB) $(OBJS)
#	$(RANLIB) $(THISLIB)

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(CCINCDIR)
I2=$(BLDROOT)/INCLUDE

allocrus.$o: allocrus.c $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     
dheaps_i.$o: dheaps_i.c $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     
edgelen.$o:  edgelen.c  $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     \
        				$(I)/macrorus.h 
edgeutil.$o: edgeutil.c $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     
sortrus.$o:  sortrus.c  $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     \
        				$(I)/macrorus.h 
urandom.$o:  urandom.c  $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     
util.$o:     util.c     $(I)/machdefs.h $(I2)/config.h  $(I)/macrorus.h \
        				$(I)/util.h     
zeit.$o:     zeit.c     $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     

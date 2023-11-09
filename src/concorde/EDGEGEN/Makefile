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
CFLAGS = -g -O2 -I$(BLDROOT)/INCLUDE -I$(CCINCDIR)
LDFLAGS = -g -O2 
LIBFLAGS = -liberty -lbfd -lm 
RANLIB = ranlib

OBJ_SUFFIX = o
o = $(OBJ_SUFFIX)

THISLIB=edgegen.a
LIBSRCS=xnear.c

LIBS=$(BLDROOT)/LINKERN/linkern.a $(BLDROOT)/UTIL/util.a

all: $(THISLIB)

everything: all

#edgegen: eg_main.$o $(THISLIB) $(LIBS)
#	$(CC) $(LDFLAGS) -o $@ eg_main.$o $(THISLIB) $(LIBS) $(LIBFLAGS)

clean:
	-rm -f *.$o $(THISLIB) edgegen

OBJS=$(LIBSRCS:.c=.o)

$(THISLIB): $(OBJS)
#$(THISLIB): $(OBJS)
#	$(AR) $(ARFLAGS) $(THISLIB) $(OBJS)
#	$(RANLIB) $(THISLIB)

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(CCINCDIR)
I2=$(BLDROOT)/INCLUDE

#edgegen.$o:  edgegen.c  $(I)/machdefs.h $(I2)/config.h  $(I)/util.h     \
#        $(I)/edgegen.h  $(I)/kdtree.h   $(I)/linkern.h  $(I)/macrorus.h
xnear.$o:    xnear.c    $(I)/machdefs.h $(I2)/config.h  $(I)/edgegen.h  \
        $(I)/util.h     $(I)/macrorus.h 

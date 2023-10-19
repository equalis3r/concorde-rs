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
SRCROOT = .
BLDROOT = .
CCINCDIR=$(SRCROOT)/INCLUDE
BLDINCDIR=$(BLDROOT)/INCLUDE

srcdir = .

CC = gcc
CFLAGS = -g -O2  -I$(BLDROOT)/INCLUDE -I$(CCINCDIR)
LDFLAGS = -g -O2 
LIBFLAGS = -liberty -lbfd -lm 
RANLIB = ranlib

OBJ_SUFFIX = o
o = $(OBJ_SUFFIX)

THISLIB=libconcorde.a

DIRS=UTIL HELDKARP LINKERN EDGEGEN

LIBS=$(BLDROOT)/EDGEGEN/edgegen.a     $(BLDROOT)/LINKERN/linkern.a \
     $(BLDROOT)/HELDKARP/heldkarp.a   $(BLDROOT)/UTIL/util.a

all: build_all $(THISLIB) libconcorde.h clean

build_all:
	@$(foreach dir, $(DIRS), $(MAKE) -C $(dir);)

$(THISLIB): 
	$(AR) rcs $(OUT_DIR)/$(THISLIB) $(foreach dir, $(DIRS), $(wildcard $(dir)/*.o))


INC_LIST=$(BLDINCDIR)/config.h  $(CCINCDIR)/machdefs.h $(CCINCDIR)/util.h     \
         $(CCINCDIR)/heldkarp.h $(CCINCDIR)/linkern.h  $(CCINCDIR)/macrorus.h \
         $(CCINCDIR)/edgegen.h  \

libconcorde.h: $(INC_LIST) Makefile
	cat $(INC_LIST) | grep -v '#include "' > $@

.PHONY: all clean

clean:
	-rm -f *.$o $(THISLIB)
	for i in $(DIRS); do ( cd $$i; $(MAKE) clean ); done

# Generated automatically from Makefile.in by configure.
###################################################
# Sample Makefile for mail archive maintenance.
#
#  Define variables and Macros
#
###################################################

prefix=/usr/local
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
SUFFIX=

#WNOERROR=-Werror
#WARNINGS=$(WNOERROR) -ansi -pedantic -Wall -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Waggregate-return -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Winline -Dlint

CC=x86_64-nacl-gcc $(WARNINGS)
CFLAGS=-g -O2
INSTALL_PROG=../install-sh

###################################################
#
#  Build the executable images
#
###################################################
#
# PLEASE read the README in this directory before continuing.

PROGS = msg2archive$(SUFFIX) rdmsg$(SUFFIX)

all: $(PROGS) 

msg2archive$(SUFFIX): msg2archive.c lists.h
	$(CC) $(CFLAGS) -o $@ msg2archive.c

rdmsg$(SUFFIX): mbox2hypermail.c lists.h
	$(CC) $(CFLAGS) -o $@ mbox2hypermail.c

########################################
#
#       Commands
#
########################################

lint:
	lint $(LINT_FLAGS) $(SOURCE) | tee Lint.out

clean: 
	rm -f $(OBJS) Lint.out
	rm -f $(PROGS)

clobber:  clean

distclean:  clean

install: $(bindir)/msg2archive$(SUFFIX) $(bindir)/rdmsg$(SUFFIX)

$(bindir)/msg2archive$(SUFFIX):  msg2archive$(SUFFIX)
	@if [ ! -d $(bindir) ]; then mkdir -p $(bindir); fi
	$(INSTALL_PROG) -c msg2archive$(SUFFIX) $@

$(bindir)/rdmsg$(SUFFIX):  rdmsg$(SUFFIX)
	@if [ ! -d $(bindir) ]; then mkdir -p $(bindir); fi
	$(INSTALL_PROG) -c rdmsg$(SUFFIX) $@

uninstall:
	rm -f $(bindir)/msg2archive$(SUFFIX)
	rm -f $(bindir)/rdmsg$(SUFFIX)

###################################################
#
#    Object file include dependencies.
#    The object file include dependencies are required.
#
###################################################

depend:
	makedepend -- $(CFLAGS) -- $(SOURCE)

# DO NOT DELETE THIS LINE -- make depend depends on it.

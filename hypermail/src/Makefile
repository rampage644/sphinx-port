# Generated automatically from Makefile.in by configure.
#
# Makefile for Hypermail
#


prefix=/usr/local
exec_prefix=${prefix}
 
# This is where you want hypermail to be installed
bindir=${exec_prefix}/bin
 
# This is where the man page goes
mandir=${prefix}/man

# This is where your CGI programs live
cgidir=/usr/local/apache/cgi-bin

# Executable program suffix (.exe for windows, null for Unix systems)
SUFFIX=

# Compiler to use
CC=x86_64-nacl-gcc
AR = ar
ARFLAGS = cru

# Installation program to use
INSTALL_PROG=../install-sh 

SPLINTFLAGS=-Ipcre 
 
#WNOERROR=-Werror
#WARNINGS=$(WNOERROR) -ansi -pedantic -Wall -Wtraditional -Wshadow -Wpointer-arith -Wcast-qual -Wcast-align -Waggregate-return -Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Winline -Dlint

CFLAGS=-g -O0  -Ipcre -DTRIO_MINIMAL $(WARNINGS)
YACC=bison -y
NETLIBS= -lnsl
LDFLAGS= -Lpcre/.libs
MISC_LIBS= -lm -lpcre -liconv
OPT_LIBS=

INCS=		domains.h hypermail.h lang.h proto.h \
		../config.h ../patchlevel.h dsprintf.h threadprint.h \
		getdate.h getname.h finelink.h txt2html.h search.h \
		strio.h trio.h triodef.h trionan.h triop.h

SRCS=		base64.c date.c domains.c file.c hypermail.c lang.c lock.c \
		mem.c parse.c print.c printfile.c string.c struct.c uudecode.c\
		dmatch.c setup.c threadprint.c getdate.c getname.c\
		finelink.c txt2html.c search.c quotes.c trio.c triostr.c \
		trionan.c hypermail_.c

OBJS=		base64.o date.o domains.o file.o hypermail.o lang.o lock.o \
		mem.o parse.o print.o printfile.o string.o struct.o uudecode.o\
		dmatch.o setup.o threadprint.o getdate.o getname.o\
		finelink.o txt2html.o search.o quotes.o trio.o triostr.o \
		trionan.o hypermail_.o

MAILOBJS=	mail.o ../libcgi/libcgi.a

.c.o:
	$(CC) -c $(CFLAGS) $<
#pcre/.libs/libpcre.a  hypermail$(SUFFIX) #mail$(SUFFIX) lang$(SUFFIX) 
all:    hypermail.a

pcre/.libs/libpcre.a:
	@cd pcre; $(MAKE) CC="$(CC)" CFLAGS="$(CFLAGS)" ; rm -f .libs/lib*.so*

fnv/libfnv.a:
	@cd fnv; $(MAKE) libfnv.a CC="$(CC)" CFLAGS="$(CFLAGS)"

hypermail$(SUFFIX): $(OBJS) 
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(OBJS) $(OPT_LIBS) $(MISC_LIBS)
	chmod 0755 $@

hypermail.a: $(OBJS) 
	rm -rf hypermail.a 
	$(AR) $(ARFLAGS) hypermail.a $(OBJS) 
#	$(CC) -o $@ -c $(CFLAGS) $(LDFLAGS) $(OBJS) $(OPT_LIBS) $(MISC_LIBS) 

mail$(SUFFIX):	$(MAILOBJS)
	$(CC) -o $@ $(CFLAGS) $(MAILOBJS) $(NETLIBS) -lm
	chmod 0755 $@

lang$(SUFFIX): trio.o trionan.o triostr.o lang.c lang.h
	$(CC) -DLANG_PROG $(CFLAGS) -o $@ trio.o trionan.o triostr.o lang.c $(LDFLAGS) $(MISC_LIBS)

../libcgi/libcgi.a:
	@cd ../libcgi; $(MAKE) all CC="$(CC)" CFLAGS="$(CFLAGS)"

getdate.c: getdate.y getdate.h
	@echo "Expect 13 shift/reduce conflicts."
	$(YACC) getdate.y
	@mv -f y.tab.c getdate.c

install: all
	@if [ ! -d $(bindir) ]; then mkdir -p $(bindir); fi
	$(INSTALL_PROG) -s -c -m 0755 hypermail$(SUFFIX) $(bindir)

mail.install:
	@if [ ! -d $(cgidir) ]; then mkdir -p $(cgidir); fi
	$(INSTALL_PROG) -s -c -m 0755 mail$(SUFFIX) $(cgidir)

uninstall:
	rm -f $(bindir)/hypermail$(SUFFIX)
	rm -f $(cgidir)/mail$(SUFFIX)

insight:
	$(MAKE) CC="insight" 

pure:
	$(MAKE) CFLAGS="-g" $(OBJS)  
	purify $(CC) -o hypermail -g $(CFLAGS) $(OBJS) 

quant:
	$(MAKE) CFLAGS="-g" $(OBJS)
	quantify $(CC) -o hypermail -g $(CFLAGS) $(OBJS)


splint: 
	splint $(SPLINTFLAGS) $(SRCS) 2>&1 | tee splint.out

lint:	
	lint $(SRCS) 2>&1 | tee lint.out

lint_mail:	
	lint mail.c 2>&1 | tee lint.out
	@(cd ../libcgi; $(MAKE) lint 2>&1 | tee -a ../lint.out)

clean:
	rm -f hypermail$(SUFFIX) mail$(SUFFIX) lang$(SUFFIX)
	rm -f *.o .pure *qx *qv *.ln core
	rm -f .inslog tca.map lint.out splint.out
	rm -f getdate.c
	rm -f hypermail.a
	@cd pcre; $(MAKE) clean
	@(if test "$(FNV_DEP)" != "" ; then cd fnv; $(MAKE) clean; fi)
	@cd ../libcgi; $(MAKE) clean

clobber: clean
	@cd pcre; rm -f *.lock
	@(if test "$(FNV_DEP)" != "" ; then cd fnv; $(MAKE) clobber; fi)
	@cd ../libcgi; $(MAKE) clobber

distclean: clobber
	@cd pcre; $(MAKE) distclean
	@(if test "$(FNV_DEP)" != "" ; then cd fnv; $(MAKE) distclean; fi)
	@cd ../libcgi; $(MAKE) distclean

#
# Regenerate this dependency list with gcc -MM *.c:
#

base64.o: base64.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h base64.h
date.o: date.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h setup.h
dmatch.o: dmatch.c dmatch.h ../config.h
domains.o: domains.c hypermail.h ../config.h ../patchlevel.h trio.h \
  proto.h lang.h domains.h
finelink.o: finelink.c hypermail.h ../config.h ../patchlevel.h trio.h \
  proto.h lang.h finelink.h setup.h print.h struct.h search.h
getdate.o: getdate.c ../config.h setup.h getdate.h
getname.o: getname.c hypermail.h ../config.h ../patchlevel.h trio.h \
  proto.h lang.h getname.h setup.h
hypermail.o: hypermail.c hypermail.h ../config.h ../patchlevel.h trio.h \
  proto.h lang.h defaults.h setup.h parse.h print.h finelink.h search.h \
  struct.h
lang.o: lang.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h
lock.o: lock.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h setup.h
mail.o: mail.c ../libcgi/cgi.h ../config.h
mem.o: mem.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h
printfile.o: printfile.c hypermail.h ../config.h ../patchlevel.h trio.h \
  proto.h lang.h setup.h print.h printfile.h
quotes.o: quotes.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h setup.h
search.o: search.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h setup.h struct.h print.h search.h
setup.o: setup.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h defaults.h setup.h struct.h print.h
string.o: string.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h setup.h parse.h
struct.o: struct.c hypermail.h ../config.h ../patchlevel.h trio.h proto.h \
  lang.h dmatch.h setup.h struct.h parse.h
threadprint.o: threadprint.c hypermail.h ../config.h ../patchlevel.h \
  trio.h proto.h lang.h setup.h struct.h threadprint.h printfile.h
trio.o: trio.c triodef.h trio.h triop.h trionan.h strio.h
trionan.o: trionan.c triodef.h trionan.h
txt2html.o: txt2html.c hypermail.h ../config.h ../patchlevel.h trio.h \
  proto.h lang.h setup.h print.h finelink.h txt2html.h
uudecode.o: uudecode.c hypermail.h ../config.h ../patchlevel.h trio.h \
  proto.h lang.h setup.h uudecode.h

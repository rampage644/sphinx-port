# Generated automatically from Makefile.in by configure.
#
# Hypermail documentation make file
#
# This is where the man page goes

prefix=/usr/local

# Man page base directory
mandir=${prefix}/man

# This is where the HTML documentation goes
htmldir=/usr/local/apache/htdocs/hypermail

# Installation program 
INSTALL_PROG=../install-sh 

all:   install
	
uninstall: 
	rm -f $(mandir)/man1/hypermail.1
	rm -f $(mandir)/man4/hmrc.4
	(if [ -d $(htmldir) ]; then \
		rm -f $(htmldir)/hr.yellow.png; \
		rm -f $(htmldir)/hypermail.png; \
		rm -f $(htmldir)/stars.png; \
		rm -f $(htmldir)/archive_search.html; \
		rm -f $(htmldir)/hypermail.html; \
		rm -f $(htmldir)/hypermail-faq.html; \
		rm -f $(htmldir)/customizing.html; \
		rm -f $(htmldir)/hmrc.html; \
		rmdir $(htmldir); \
	fi)

install: install.man install.html

install.man:
	@(if [ ! -d $(mandir) ]; then mkdir -p $(mandir); fi)
	@(if [ ! -d $(mandir)/man1 ]; then mkdir -p $(mandir)/man1; fi)
	@(if [ ! -d $(mandir)/man4 ]; then mkdir -p $(mandir)/man4; fi)
	$(INSTALL_PROG) -c -m 0644 hypermail.1 $(mandir)/man1
	$(INSTALL_PROG) -c -m 0644 hmrc.4 $(mandir)/man4

install.html:
	@(if [ ! -d $(htmldir) ]; then mkdir -p $(htmldir); fi)
	$(INSTALL_PROG) -c -m 0644 hr.yellow.png $(htmldir)
	$(INSTALL_PROG) -c -m 0644 hypermail.png $(htmldir)
	$(INSTALL_PROG) -c -m 0644 stars.png $(htmldir)
	$(INSTALL_PROG) -c -m 0644 archive_search.html $(htmldir)
	$(INSTALL_PROG) -c -m 0644 hypermail.html $(htmldir)
	$(INSTALL_PROG) -c -m 0644 hypermail-faq.html $(htmldir)
	$(INSTALL_PROG) -c -m 0644 customizing.html $(htmldir)
	$(INSTALL_PROG) -c -m 0644 hmrc.html $(htmldir)

clean:
clobber:
distclean:

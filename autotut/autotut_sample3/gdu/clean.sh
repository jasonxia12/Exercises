# clean build output
test -f "Makefile" && make distclean
test -f "gdu-0.0.1.tar.gz" && rm gdu-0.0.1.tar.gz
# clean aclocal output
test -f "aclocal.m4" && rm aclocal.m4
# clean autoheader output
test -f "config.h.in" && rm config.h.in
# clean autoconf output
test -d "autom4te.cache" && rm -r autom4te.cache
test -f "configure" && rm configure
# clean automake --add-missing --copy output
test -f "install-sh" && rm install-sh missing depcomp AUTHORS ChangeLog COPYING INSTALL NEWS README
# clean automake output
test -f "Makefile.in" && rm Makefile.in


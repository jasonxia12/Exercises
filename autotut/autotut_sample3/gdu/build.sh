aclocal
autoheader
autoconf
automake --add-missing --copy
touch NEWS
touch README
touch AUTHORS
touch ChangeLog
automake 
./configure
make
make dist



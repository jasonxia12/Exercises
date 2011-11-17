/**
 * @file pi.c
 * @brief the test file for autotut
 * @author Asins - asinsimple AT gmail DOT com
 * @version 1.0
 * @date 2011-11-08
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
	double value=0.0,denom=1.0,sig=1.0;
	unsigned long t,prec;

	printf("PI Approximator version %s\n",VERSION);

	prec=10;
	if (argc>1) prec=atol(argv[1]);

	for(t=prec;t;t--) {
		value+=sig/denom;
		sig=-sig;
		denom+=2.0;
	}
	value*=4.0;
	printf("pi ~= %.8f , with %lu iterations\n",value,prec);
	return 0;
}


#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//Definitions. They should be changes according to model to use
#define A	(long double)1.6328
#define	B	(long double)0.07377
#define C	(long double)0.01
#define D 	(long double)0.06852 // Should it be minus or plus????
#define k	(long double)8.6173324e-5 // It is in eV/K

#define a	(long double)78
#define b	(long double)-0.081
#define X	(long double)0.759
#define Y	(long double)-66.8
#define Z	(long double)-8.37e-4

#define betap	(long double)0.3

/* long double Final_MTTF_Approach(block *first, block *end) {

	block *aux;

	return 0;

} */

void Start_Seeder() {

	// Initializes the random number generator with the system time
	srand((unsigned)time(NULL));
	return;
}

long double Calculate_Alpha(long double MTTF, long double beta) {

	// Calculates alpha with a known beta and MTTF
	return(MTTF/exp(lgammal(1+(1/beta))));

}

long double Gen_Weibull_Sample(long double alpha, long double beta) {

	// Generates random samples of according to a Weibull
	// of parameters alpha (scale) and beta (shape) using
	// the inverse CDF method (view paper in README for
	// more details

	return(alpha*pow((-log(1-((long double)rand()/(long double)RAND_MAX))), 1/beta));
}

long double Calculate_NBTI_MTTF(long double temp) {

	long double aux;

	// Since it is a very long function and you
	// can get lost easily, I've broken it down
	// so it's easier to understand and/or
	// modify

	// It will end up increasing computational
	// burden.

	aux = (long double)log(A/(1+2*exp(B/(k*temp))));
	aux -= (long double)log(A/(1+2*exp(B/(k*temp)))-C);
	aux *= (temp/exp((-D)/(k*temp)));
	return((long double)pow(aux, (1/betap)));

}

long double Calculate_TDDB_MTTF(long double temp, long double voltage) {

	long double aux;

	// Since it is a very long function and you
	// can get lost easily, I've broken it down
	// so it's easier to understand and/or
	// modify

	// It will end up increasing computational
	// burden.

	aux = (long double)1/voltage;
	aux = (long double)pow(aux, (a-b*temp));
	aux *= (long double)exp((X+(Y/temp)+(Z*temp))/(k*temp));
	return(aux);

} 

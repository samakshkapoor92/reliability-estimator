#define NAME_BUFFER		50

// Basic structure for the system blocks
typedef struct block {

	char name[NAME_BUFFER];
	long double t;
	long double area;
	long int failures;
	struct block *nextblock;

} block;

void Start_Seeder();

//long double Final_MTTF_Approach(block *first, block *end);

long double Calculate_Alpha(long double MTTF, long double beta);
long double Gen_Weibull_Sample(long double alpha, long double beta);
long double Calculate_NBTI_MTTF(long double temp);
long double Calculate_TDDB_MTTF(long double temp, long double voltage);

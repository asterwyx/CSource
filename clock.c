#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


void compute(void)
{
	int i, j;
	double x; 
	x = 0.0;
	for( i = 1; i <= 100; i++ )
	{
		for( j = 1; j <= 100; j++ )
		{
			x += sqrt((double)i * j);
		}
	}
	printf("%16.7f\n", x);
}

int main(void)
{	
	clock_t start_time, end_time;
	start_time = clock();
	for(int i=0; i < 100; i++)
		compute();
	end_time = clock();
	printf("Execution time was %lf seconds\n", (long)(( end_time - start_time)/CLOCKS_PER_SEC) );
	return (0);
}

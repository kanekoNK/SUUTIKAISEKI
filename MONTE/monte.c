#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i;
	int Cou = 0;
	int Max = 100000;
	double x,y,z,pi;

	srand(time(NULL));

	for(i=0; i<Max; i++){
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x + y*y;
		if(z<1){
			Cou++;
		}
		printf("a=%d(n)/%d(N)\n", Cou, Max);
	}
	
	pi = (double)Cou / Max * 4;
        printf("π=%d/%d×4\n ", Cou, Max);
	printf("π=%f\n", pi);

	return 0;
}



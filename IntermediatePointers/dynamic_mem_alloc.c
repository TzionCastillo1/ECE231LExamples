//stdlib.h is needed to use malloc

#include<stdio.h>
#include<stdlib.h>

struct _stuff {
	double q;
	int a;
	float y;
};

//dont have to write struct _stuff anymore
typedef struct _stuff Stuff;

int main() {
	//Here we are allocating space for 7 doubles
	//malloc returns void * (void pointer)
	//we are handling the memory explicity, and on the heap.
	double* x = (double*) malloc(7 *sizeof(double));
	//Equivalent to above line, but for the stack.
	double y[7];

	int y_size = sizeof(y)/y[0];
	Stuff* z = (Stuff*) malloc( 12 * sizeof(Stuff));	
	
	//Below for loops are equivalent
	int i;
	for (i=0; i<7; i++){
		x[i] = (i+1)*(i*2);
	}
	for (i = 0; i<7; i++){
		printf("x[%d] = %lf\n", i, *(x+i));
	}

	//When using malloc we must free the memory space when we are done with it.
	free(x);

	Stuff* z = (Stuff*) malloc(12 * sizeof(Stuff));
	z[0].q = 6.5;
	z[0].a = 5;
	z[0].y = 7.8f;

	(*(z+1)).q = 12.4;
	// equivalient to z[0].q = 12.4;
	
	free(z);
	//if you dereference after free, you will get a segment fault
	return 0;
}

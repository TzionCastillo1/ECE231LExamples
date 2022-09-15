#include <stdio.h>
#include <stdlib.h>

int main() {
	//int* n = (int*) malloc(6 * sizeof(int));
	int* n = (int*) calloc(6,sizeof(int));
	//Where malloc just reserves memory, and is agnostic of the memories contents
	//calloc allocates memory and zeroes-out the values of that memory
	
	n = (int*) realloc(n,30,*sizeof(int));
	//realloc allows us to change the amount of reserved memory, while preserving the memory where possible
	//i.e. if realloc is smaller than initial allocation, it will truncate excess memory (obviously)
	
	free(n);
	return 0;
}
	

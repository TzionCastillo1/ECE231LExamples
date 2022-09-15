#include<stdio.h>
#include<stdlib.h>

int main() {
	//could also write int y[][3] = {
	//and it would work the same
	int y[2][3] = {
		{2,4,6},
		{1,3,5}
	};

	int x_rows = 2;
	int x_column = 3;

	//if we want we can also allocate memory for single pointer
	int* z = (int*) malloc(x_rows * sizeof(int));
	//Important to note that the argument inside of sizeof() is one
	//pointer level below the datatype of the variable
	free(z);

	int** x = (int**)malloc(x_rows * sizeof(int*));
	int i;
	for (i=0; i<x_rows; i++){
		//*(x+i) == x[i]
		//We are essentially creating an array (pointer to beginning element)
		//which points to other arrays (pointer to beginning element)
		x[i] = (int*) malloc(x_cols * sizeof(int))
	}

	//how to free this matrix
	for(i=0; i<x_rows; i++){
		free(x[i]);
	}
	free(x);

	return 0;
}

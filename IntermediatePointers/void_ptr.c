#include<stdio.h>

struct thing {
	double x;
	float y;
	char z;
};

int main(){
	void* ptr;
	int a = 5;
	float b = 8.2f;
	double c = 74.2071;
	char d = 't';
	struct thing e ={9.372,3.1415f, 'k'};
	//Void pointer can be rewritten to any pointer type, but must be correctly typecasted

	//Here we are typecasting void pointer into an int pointer
	ptr = &a;
	printf("a = %d\n", *((int*)ptr));
	
	//Here we are typcasting void pointer into a float pointer
	ptr = &b;
	printf("b= %f\n", *((float*)ptr));
	
	//void pointer is being cast as a "struct thing" pointer. Easier to use this syntax than ->
	//Because you cannot typecast while using ->
	//main takeaway is that void pointer can be cast as any pointer.
	//void pointer's 'voidness' persists.
	//
	ptr = &e;
	printf("x= %lf, y = %f, z = %c\n",
			(*((struct thing*) ptr)).x,
			(*((struct thing*) ptr)).y,
			(*((struct thing*) ptr)).z
	      );
	return 0;
}

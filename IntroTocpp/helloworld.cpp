#include<iostream>
//do not use "using namespace std;"

//in c++ we can use the address operator in place of the asterik
//These are called References
void swap(double& x, double& y){
	double t = x;
	x = y;
	y = t;


//One useful featuer of c++ is that we can overload functions
//i.e., we can have functions with the same names as long as they have 
//different inputs
void swap(int* x, int* y){
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

void swap(float* x, float* y){
	float t;
	t = *x;
	*x = *y;
	*y = t;
}


int main() {

	//The preffered way of printing instead of printf()
	// << normally represents a left bitwise shift, but its function
	// was overwritten in the std namespace to mean print
	std::cout << "Hello World!\n";
	//could also write:
	std::cout << "Hello World!" << std::endl;
	//std::endl add newline and will flush out the buffer, useful for embedded applications
	
	//below is how we add a variable into the print
	//Here we are also writing the newline '\n' as one character
	int my_age = 21;
	std::cout << "my age is: " << my_age << '\n';
	//We could add as many variables as we want, as long as there are double
	//double angle brackets inbetween
	int two = 2;
	int one = 1;
	std::cout <<"my name is: " << two << one << '\n';
	
	//References always need to refer to something
	int& two_ref = two;

	//In order to call swap using pointers:
	swap(&two, &one);
	//Calling using References:
	swap(two, six);

	return 0;
}

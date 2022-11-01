#include <iostream>
#include <vector>

int main() {
	//Raw pointer, equivalent of malloc
	//double* first = (double*) malloc(1 * sizeof(double));
	double* first = new double;
	*first = 3.1415;
	double second = 5.349;
	double* third = &second;

	//From below we can see that the address of first (the pointer) is very far
	//from the address that it is pointing to
	std::cout<< "first: " << first << '\n';
	std::cout<< "&first: " << &first << '\n';
	std::cout<< "first: " << *first << '\n';
	
	//Below we are printing the references(addresses) of second and third
	std::cout<< "&second: " << &second << '\n';
	std::cout<< "&third: " << &third << '\n';

	//Equivalent of free
	delete first;
	//no equivalent for realloc or alloc

	//equivalent with arrays
	float* fourth = new float[6];
	for(int i = 0; i < 6; i ++){
		fourth[i] = (i+1) * (i + 2);
	}
	for(int i = 0; i < 6; i ++){
		std::cout << *(fourth + i) << ' ';
	}
	std::cout << '\n';
	
	//in order to enlarge array we can do follwoing:
	float* fourth_copy = new float[6];
	for( int i = 0; i < 6; i++){
		fourth_copy[i] = fourth[i];
	}
	delete[] fourth;
	fourth = new float[12];
	for( int i = 0; i < 6;i ++){
		fourth[i] = fourth_copy[i];
	}
	delete[] fourth_copy;
	for(int i = 0; i < 12; i ++){
		std::cout << *(fourth + i) << ' ';
	}
	std::cout << '\n';
	
	delete[] fourth;
	
	//We can dynamically allocate memory for vectors and other data types
	std::vector<float>* fifth = new std::vector<float>;
	delete[] fifth;
	//delete doesnt really work like this
	//I think std::vector etc. handle their own memory allocation

	return 0;
}

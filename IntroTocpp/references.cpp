#include <iostream>
#include <vector>

//By passing a vector reference instead of a vector
//we are able to avoid copying the contents of the vector

//References allow us to save memory by not making copies
//but we have to be careful not to modify what we are referencing 

//This function would modify the original data
void print_vector(std::vector<int>& v){
	for (auto& i :v ){
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

//By using the const modifier, we are able to ensure that we dont modify 
//what we are referencing.
void print_vector_goal(const std::vector<int>& v){
	for (const auto& i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

//Below is an example where we want to modify the original
//vector from the reference
void square_vector(std::vector<int>& v){
	for (auto& i : v) {
		i *= i;
	}
}

int main() {
	std::vector<int> x = { 1,2,3 };
	print_vector(x);
	print_vector_goal(x);
	square_vector(x);
	print_vector_goal(x);
	//Same reference phenomenon as described above
	//y is a reference to x, any change to y will change x
	std::vector<int>& y = x;

	//By doing a const reference, we prevent changes in z from changing y
	const std::vector<int>& z = x;
	return 0;
}

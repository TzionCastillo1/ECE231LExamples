#include <iostream>
#include <string>
#include <vector>
/*
 * void swap(int& x, int& y){
 * 	int t = x;
 * 	x = y;
 * 	y = t;
 *}
 *
 * void swap(float& x, float& y){
 * 	float t = x;
 * 	x = y;
 *	y = t;
 *}
 *
 * void swap(std::string& x, std::string& y){
 * 	std::string t = x;
 * 	x = y;
 * 	y = t;
 * }
 * 
 */

template <typename T1, typename T2>
struct _pair{
	T1 first;
	T2 second;
};

using IntFloatPair = struct _pair<int, float>;

//templates must be specified before any function that will use it
template <typename T>
void swap(T& x, T& y){
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
void print_vector(const std::vector<T>& v) {
	for (const auto& x: v){
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int main() {
	int a = 6, b = 8;
	std::cout << "a: " << a << " b: " << b << std::endl;
	swap(a,b);
	/*our swap function is a possible implementation of std::swap*/
	std::swap(a,b);
	std::cout << "a: " << a << " b: " << b << std::endl;

	std::vector<double> c = {4.567, 8,3908, 5.6839};
	std::vector<double> d = {2.76563, 654.256, 3547.56};
	
	print_vector(c);
	print_vector(d);
	swap(c,d);
	print_vector(c);
	print_vector(d);
	
	struct _pair<int, float> e = {42, 3.14f};
	/*std::pair is a templated structure, similar to the struct _pair that we created*/
	std::pair<double, char> f = {8.045, 'c'};
	return 0;	
}

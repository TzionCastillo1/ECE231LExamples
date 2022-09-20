#include <iostream>
#include <vector>
#include <array>
int main() {
	//it is discouraged to use arrays in c++
	//we can alternatively use vector, or array found in <array>
	std::array<int, 2> x = {1,9};
	//equivalent of python for-each loop
	//Recommended to use auto for short-lived variables
	for (const auto& i : x){
		std::cout << i << ' ';
	}
	std::cout << '\n';

	std::vector<int> y = {1,9};
	//equivalent of python for-each loop
	for(const auto& i : y){
		std::cout << i << ' ';
	}
	std::cout << '\n';

	y.push_back(12);
	for (const auto& i : y){
		std::cout << i << ' ';
	}
	std::cout << '\n';

	//methods are functions that are attached to variables
	//y.size, y.push_back
	y.push_back(24);
	for (int i = 0; i<y.size(); i +=2) {
		std::cout << y[i] << ' ';
	}
	std::cout << '\n';
	return 0;
}


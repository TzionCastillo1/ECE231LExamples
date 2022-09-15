#include <iostream>
#include <vector>

int main() {
	//it is discouraged to use arrays in c++
	//we can alternatively use vector, or array found in <array>
	std::array<int, 2> x = {1,9};
	std::vector<int> y = {1,9};

	return 0;
}


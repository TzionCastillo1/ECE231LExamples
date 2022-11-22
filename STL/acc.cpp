#include <iostream>
#include <vector>
#include <cassert>

template<typename Iter, typename T>
T acc(Iter begin, Iter end, T val) {
	for (; begin!= end; ++begin){
		val+= *begin;
	}
	return val;
}

int main() {
	std::vector<int> x{1,2,3,4,5};
	std::cout << "tri num of 5: " << acc(x.begin(), x.end(), 0) << '\n';
	assert(x.size() != 0);
	std::cout << "Mean: " << (acc(x.begin(), x.end(), 0) / x.size()) << '\n';
	return 0;
}

#include<iostream>
#include"singlelist.hpp"

// TODO test =operator
int main() {
	SingleList<int> x;
	std::cout << "Will print 1 for empty: " << x.empty() << '\n';
	
	x.push_front(17);
	x.pop_back();
	x.push_front(2);
	x.push_back(32);

	std::cout << "first value of x: " << x.front() << '\n';
	std::cout << "last value of x: " << x.last() << '\n';
	std::cout << "Size of x: " << x.size() << '\n';

	return 0;
}

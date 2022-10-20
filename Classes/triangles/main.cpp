#include<iostream>
#include"pyramid.hpp"

int main() {
	Pyramid x;
	Pyramid y(1,2,3);
	std::cout << "x: " << x.base() << ' ' << x.height() << ' ' << x.depth() << '\n';

	return 0;
}

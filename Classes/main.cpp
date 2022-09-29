#include <iostream>
#include "rectangle.hpp"

int main(){
	//Unparameterized Constructor
	Rectangle x;
	//Parameterized Constructor
	Rectangle y(9,5);
	
	x.set_width(115);
	std::cout << "x: " << x.length() << ' ' << x.width() << '\n';
	std::cout << "y: " << y.length() << ' ' << y.width() << '\n';	

	//:s/x/y replaces first 'x' with 'y'
	//:s/x/y/g replaces every 'x' with 'y' on that line
	
	Rectangle z = x.add_rectangle(y);
	z.print();

	std::cout << "x: "<< x.length() << ' ' << x.width() << '\n';
	std::cout << "y: "<< y.length() << ' ' << y.width() << '\n';
	return 0;
}

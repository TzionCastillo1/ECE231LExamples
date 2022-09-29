#include "rectangle.hpp"
//Below is how we include C style header files
#include <cassert>
#include <utility> 
#include <iostream>

//Namespace designator similar to
//std::vector
Rectangle::Rectangle() : _length{1}, _width{1}{}
//Equivalent to {
//_length = 1;
//_width = 1;}

Rectangle::Rectangle(int length, int width) {
	set_length(length);
	set_width(width);
}

Rectangle::Rectangle(const Rectangle& r) : _length{r._length},
	_width{r._width} {}

Rectangle::Rectangle(Rectangle&& r) :
	_length{std::move(r._length)},
	_width{std::move(r._width)}{}

Rectangle::~Rectangle() {
	std::cout << "Destructor called for ";
	std::cout << length() << ' ' <<  width() << '\n';
}

int Rectangle::length() const {
	return _length;
}

int Rectangle::width() const {
	return _width;
}

void Rectangle::set_width(int new_width){
	assert(new_width > 0);
	_width = new_width;
}

void Rectangle::set_length(int new_length){
	assert(new_length > 0);
	_length = new_length;
}

void Rectangle::print() const {
	std::cout << "length: " << length() << '\n';
	std::cout << "width: " << width() << '\n';
}

int Rectangle::area() const {
	return length() * width();
}

int Rectangle::perimeter() const {
	return (2* length()) + (2 * width());
}

Rectangle Rectangle::add_rectangle(const Rectangle& r){
	Rectangle t;
	t.set_length(length() + r.length());
	t.set_width(width() + r.width());
	//We do not return pointer because this variable will be destroyed at 
	//the end of the scope. This would mean the pointer would point to an 
	//address that now has undefined data
	return t;
}

Rectangle Rectangle::operator+(const Rectangle& r) {
	return add_rectangle(r);
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
	//check if we are trying to set r = to itself
	//this is a pointer to itself 
	//so we take the address of r to compare it with
	if (this == &r) {
		return *this;
	}
	set_length(r.length());
	set_width(r.width());
	return *this;
}

//std::ostream is input and output, allowing us to
//chain multiple std::ostream objects for printing
//i.e. Rectangle x;
//i.e. int y = 2;
//i.e. std::cout << x << y << '\n';
std::ostream& operator<<(std::ostream& out, const Rectangle& r){
	out << r.length() << ' ' r.width();
	return out;
}

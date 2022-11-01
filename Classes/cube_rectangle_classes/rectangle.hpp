#ifndef BASE_RECTANGLE_HPP
#define BASE_RECTANGLE_HPP
#include<iostream>
#include<utility>

class Rectangle{
	//protected mean we cannot access these attributes
	//but a derived class can
	protected:
		//Member variables are called attributes
		//Can prefix with underscore to signify attributes
		int _length;
		int _width;

	public:
		//Example of function overloading
		//Unparameterized constructor
		Rectangle();
		//Parameterized constructor
		Rectangle(int lenth, int width);
		//Copy constructor
		Rectangle(const Rectangle& r);
		//Move constructor
		Rectangle(Rectangle&& r);
		
		//Destructor
		~Rectangle();

		//Getters
		//It is recommended to use const when not modifying attributes
		int length() const;
		int width() const;

		//Setters
		//We use virtual if the methods may change
		virtual void set_length(int new_length);
		virtual void set_width(int new_width);
		
		void print() const;
		int area() const;
		int perimeter() const;
		//const keyword can only be used with methods
		//i.e. void foo() const;
		Rectangle add_rectangle(const Rectangle& r);
		Rectangle add_rectangle(int x);
		Rectangle sub_rectangle(const Rectangle& r);
		
		//can also use operator overload
		Rectangle operator+(const Rectangle& r);
		Rectangle operator+(int x);
		Rectangle operator-(const Rectangle& r);
		//Rectangle operator*(const Rectangle& r);
		Rectangle operator*(int x);
		Rectangle& operator=(const Rectangle& r);

		//<< operator is a function, because it is not apart of this class
		friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
};

#endif //BASE_RECTANGLE_HPP

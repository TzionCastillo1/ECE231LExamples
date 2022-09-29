class Rectangle{
	private:
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
		void set_length(int new_length);
		void set_width(int new_width);
		void print() const;
		int area() const;
		int perimeter() const;
		//const keyword can only be used with methods
		//i.e. void foo() const;
		Rectangle add_rectangle(const Rectangle& r1);
		//can also use operator overload
		Rectangle operator+(const Rectangle& r);
		Rectangle& operator=(const Rectangle& r);

		//<< operator is a function, because it is not apart of this class
		friend std::ostream& operator<<(std::ostream& out, const Rectangle& r);
};


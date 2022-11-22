#include <array>
#include <iostream>
#include <vector>

template <typename Iter, typename Func>
void ForEach(Iter begin, Iter end, Func f){
	for (;begin != end; ++begin){
		f(*begin);
	}
}

void print_sq(int x) {
	std::cout << (x*x) << ' ';
}

int main(){
	std::array<int, 100> stuff;
	std::vector<int> other_stuff(256);

	/*The third argumemt a called a lambda, a nameless function */
	ForEach(stuff.begin(), stuff.end(), [](int& x) {x=69;});
	ForEach(stuff.begin(), stuff.end(), [](const int& x) { std::cout << x << ' ';});
	std::cout << '\n';

	ForEach(other_stuff.begin(), other_stuff.end(), [](int& x) {x = 42;});
	ForEach(other_stuff.begin(), other_stuff.end(), [](const int& x) { std::cout << x << ' ';});
	std::cout << '\n';

	ForEach(other_stuff.begin(), other_stuff.end(), print_sq);
	std::cout << '\n';
	
	return 0;

}

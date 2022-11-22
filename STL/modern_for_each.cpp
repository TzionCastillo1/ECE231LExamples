#include <array>
#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>

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
	std::ranges::ForEach(stuff.begin(), stuff.end(), [](int& x) {x=69;});
	std::ranges::ForEach(stuff.begin(), stuff.end(), [](const int& x) { std::cout << x << ' ';});
	std::cout << '\n';

	std::ranges::ForEach(other_stuff.begin(), other_stuff.end(), [](int& x) {x = 42;});
	std::ranges::ForEach(other_stuff.begin(), other_stuff.end(), [](const int& x) { std::cout << x << ' ';});
	std::cout << '\n';

	std::ranges::ForEach(other_stuff.begin(), other_stuff.end(), print_sq);
	std::cout << '\n';
	
	return 0;

}

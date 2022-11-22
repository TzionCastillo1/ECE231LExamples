#include <iostream>
#include <vector>

template <typename Iiter,typename Oiter>
Oiter copy(Iiter begin, Iiter end, Oiter dst){
	for (;begin !=end; ++begin, ++dst) {
		*dst = *begin;
	}
	return dst;
}

template <typename T>
void print_vector(const std::vector<T>& v){
	for(const auto& x:v){
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::vector<float> x{9.2f,6.2f,3.6f,2.1f};
	std::vector<float> y(4,0.0f);
	
	print_vector(y);
	std::copy(x.begin(), x.end(), y.begin());
	print_vector(y);
	std::copy(x.rbegin() + 2, x.rend(), y.begin());
	print_vector(y);
	return 0;
}

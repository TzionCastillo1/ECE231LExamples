all: pyramid_time

pyramid_time: main.o triangle_impl.o pyramid_impl.o
	g++ $^ -o $@

main.o: main.cpp triangle.hpp
	g++ -c $< -o $@

triangle_impl.o: triangle_impl.cpp triangle.hpp
	g++ -c $< -o $@

pyramid_impl.o: pyramid_impl.cpp pyramid.hpp
	g++ -c $< -o $@


clean: 
	-rm *.o pyramid_time



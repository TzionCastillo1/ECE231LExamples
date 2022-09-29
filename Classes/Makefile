all: rectangle_time

rectangle_time: main.o rectangle_impl.o
	g++ $^ -o $@
	#$^ == main.o rectangle_impl.o
	#$@ == rectangle_time

main.o: main.cpp rectangle.hpp
	g++ -c $< -o $@
	#$< == main.cpp , first prerequisite
	#$@ == main.o

rectangle_impl.o: rectangle_impl.cpp rectangle.hpp
	g++ -c $< -o $@
	#$< == rectangle_impl.o
	#$@ == rectangle_impl.o

clean:
	-rm *.o rectangle_time

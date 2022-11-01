all: cube_time

cube_time: main.o rectangle_impl.o cube_impl.o
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

cubee_impl.o: cubee_impl.cpp cube.hpp
	g++ -c $< -o $@
	#$< == cube_impl.o
	#$@ == cubee_impl.o

clean:
	-rm *.o cube_time

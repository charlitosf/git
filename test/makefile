test: test.cc
	g++ -o test test.cc ../src/Coordinate.o

test.cc : test.h
	cxxtestgen -w wn -o $@ --error-printer $^

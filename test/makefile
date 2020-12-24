test: test.cc ../src/Coordinate.o
	g++ -o test test.cc ../src/Coordinate.o

test.cc : test.h
	cxxtestgen -w Coordinate -o $@ --error-printer $^

clean:
	rm test test.cc

.PHONY: clean
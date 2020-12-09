test: test.cc
	g++ -o test test.cc ../src/Coordinate.o

test.cc : test.h
	cxxtestgen -w wn -o $@ --error-printer $^

clean:
	rm test test.cc

.PHONY: clean
OPTS=-Wall
OBJS=Base.o Ship.o Coordinate.o Util.o Planet.o
CC=g++

evacuationOfHoth: evacuationOfHoth.o $(OBJS)
	$(CC) $(OPTS) $(OBJS) evacuationOfHoth.o -o evacuationOfHoth

evacuationOfHoth.o: evacuationOfHoth.cc Base.h Ship.h Coordinate.h Planet.h Util.h
	$(CC) $(OPTS) -c evacuationOfHoth.cc

Coordinate.o: Coordinate.cc Coordinate.h
	$(CC) $(OPTS) -c Coordinate.cc

Base.o: Base.cc Base.h Coordinate.h Util.h
	$(CC) $(OPTS) -c Base.cc

Ship.o: Ship.cc Ship.h Coordinate.h Base.h Util.h
	$(CC) $(OPTS) -c Ship.cc

Planet.o: Planet.cc Planet.h Coordinate.h Base.h Ship.h Util.h
	$(CC) $(OPTS) -c Planet.cc

Util.o: Util.cc Util.h
	$(CC) $(OPTS) -c Util.cc

clean:
	rm *.o evacuationOfHoth

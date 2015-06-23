main.o: main.cpp
	g++ -O2 -c main.cpp
scheduler: main.o
	g++ -O2 main.o -o scheduler
all: scheduler

clean:
	rm *.o
	rm scheduler

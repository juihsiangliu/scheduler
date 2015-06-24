all: scheduler
main.o: main.cpp
	g++ -O2 -c main.cpp
parser.o: parser.cpp
	g++ -O2 -c parser.cpp
scheduler: main.o parser.o
	g++ -O2 *.o -o scheduler
	cp scheduler ../bin
clean:
	rm *.o
	rm scheduler

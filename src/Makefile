all: scheduler
main.o: parser.h main.cpp
	g++ -O2 -c main.cpp
parser.o: parser.cpp parser.h task.h resource.h
	g++ -O2 -c parser.cpp
task.o: task.cpp task.h
	g++ -O2 -c task.cpp
resource.o: resource.cpp resource.h
	g++ -O2 -c resource.cpp
scheduler: main.o parser.o task.o resource.o
	g++ -O2 *.o -o scheduler
	cp scheduler ../bin
clean:
	rm -f *.o
	rm -f scheduler
	rm -f ../bin/scheduler

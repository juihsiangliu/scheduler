CFLAGS = -Wall -O2


all: scheduler test
main.o: parser.h main.cpp resource.h
	g++ $(CFLAGS) -c main.cpp
parser.o: parser.cpp parser.h task.h resource.h
	g++ $(CFLAGS) -c parser.cpp
task.o: task.cpp task.h resource.h
	g++ $(CFLAGS) -c task.cpp
resource.o: resource.cpp resource.h
	g++ $(CFLAGS) -c resource.cpp
test.o: test.cpp resource.h parser.h
	g++ $(CFLAGS) -c test.cpp
scheduler: main.o parser.o task.o resource.o
	g++ $(CFLAGS) main.o parser.o task.o resource.o -o scheduler
test: scheduler test.o
	g++ $(CFLAGS) test.o resource.o -lgtest -lpthread -o test
clean:
	rm -f *.o
	rm -f scheduler
	rm -f test

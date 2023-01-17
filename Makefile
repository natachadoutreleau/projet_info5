CXXFLAGS = -Wall

objects = String.o string_tests.o main.o bin

bin : main.o string_tests.o String.o
	g++ main.o string_tests.o String.o -o bin

main.o: main.cpp string_tests.h String.h
	g++ -o main.o -c main.cpp

string_tests.o: string_tests.cpp string_tests.h String.h
	g++ -o string_tests.o -c string_tests.cpp


String.o: String.cpp String.h
	g++ -o String.o -c String.cpp

clean:
	rm make_lab $(objects)

CXXFLAGS = -Wall

objects = String.o string_tests.o main.o bin

bin : main.o string_tests.o String.o
	g++ -std=c++11 main.o string_tests.o String.o -o bin

main.o: main.cpp string_tests.h String.h
	g++ -std=c++11 -o main.o -c main.cpp

string_tests.o: string_tests.cpp string_tests.h String.h
	g++ -std=c++11 -o string_tests.o -c string_tests.cpp


String.o: String.cpp String.h
	g++ -std=c++11 -o String.o -c String.cpp

clean:
	rm bin $(objects)

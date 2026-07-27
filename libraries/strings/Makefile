CXX = g++
CXXFLAGS = -g -Wall -std=c++17

main.exe: main.cpp string.cpp
	$(CXX) $(CXXFLAGS) main.cpp string.cpp -o main.exe

.PHONY: clean
clean:
	rm -f main.exe

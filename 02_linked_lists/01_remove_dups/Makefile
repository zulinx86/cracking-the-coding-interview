CXX = g++
CXXFLAGS = -Wall
EXECFILES := $(patsubst %.cpp,%,$(wildcard *.cpp))

%: %.cpp
	$(CXX) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXECFILES)

CXX = g++
CXXFLAGS = -Wall
EXECFILES := $(patsubst %.cpp,%,$(wildcard *.cpp))

.PHONY: all
all:
	make $(EXECFILES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXECFILES)

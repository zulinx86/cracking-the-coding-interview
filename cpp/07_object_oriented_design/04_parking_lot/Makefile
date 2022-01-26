CXX = g++
CXXFLAGS = -Wall
EXECFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

.PHONY: all
all:
	make $(EXECFILES)
	g++ -o a.out $(EXECFILES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXECFILES) a.out

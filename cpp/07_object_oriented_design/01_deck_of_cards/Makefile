CXX = g++
CXXFLAGS = -Wall
EXECFILES := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

.PHONY: all
all:
	make a.out

a.out: $(EXECFILES)
	$(CXX) $(CXXFLAGS) $(EXECFILES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(EXECFILES) a.out

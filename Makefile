progname=genling

CXX=g++
CXXFLAGS=-g -Wall -pedantic \
	-std=c++11
LDLIBS=-lboost_regex -licuuc
sources=$(shell find src -name "*.cpp")
objects=$(patsubst %.cpp,%.o,$(sources))

all: $(progname)

$(progname): $(objects)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o bin/$(progname) $(objects) $(LDLIBS)

clean:
	rm $(objects)

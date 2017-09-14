TARGET=genling

CXX=g++
CXXFLAGS=-g -Wall -Wextra -Werror -pedantic\
	-std=c++11
LDLIBS=-lboost_regex -licuuc
SOURCES=$(wildcard src/genling/*.cpp)\
	src/main.cpp
OBJECTS=$(SOURCES:src/%.cpp=build/%.o)

RM=rm -rf
MKDIR=mkdir -p

bin/$(TARGET): $(OBJECTS)
	$(MKDIR) bin
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

$(OBJECTS):
	$(foreach OBJECT, $@,\
		$(MKDIR) $(dir $(OBJECT));\
		$(CXX) $(CXXFLAGS) $(LDFLAGS)\
			-c -o $(OBJECT) $(OBJECT:build/%.o=src/%.cpp))

depend: .depend

.depend: $(SOURCES)
	$(RM) ./.depend
	$(foreach SOURCE, $(SOURCES),\
		$(CXX) -MM -MT $(SOURCE:src/%.cpp=build/%.o) $(SOURCE) >> .depend;)

clean:
	$(RM) ./build ./.depend

include .depend

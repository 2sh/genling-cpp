#!/bin/bash

mkdir -p bin/
g++ -std=c++11 \
	src/main.cpp \
	src/genling/*.cpp \
	-o bin/genling && chmod +x bin/genling
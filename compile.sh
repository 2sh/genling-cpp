#!/bin/bash

mkdir -p bin/
g++ -o bin/genling \
	src/main.cpp \
	src/genling/*.cpp \
	-std=c++11 \
	-lboost_regex -licuuc \
	&& chmod +x bin/genling

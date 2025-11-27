cxx = g++
cflags =

inc = -Iinclude
src_files = $(wildcard src/*cpp)
target = build/main

.PHONY: build
all: build run

build: 
	$(cxx) $(inc) $(src_files) -o $(target) 

run:
	./$(target)
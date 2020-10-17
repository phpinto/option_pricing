CC = g++
CFLAGS= -std=c++11
INCLUDE:= -Iinclude/
SOURCE:= src/option.cpp
EXE=option
SRC = $(wildcard src/*.cpp)
INC = $(wildcard include/*.h)

all: $(EXE)

$(EXE):
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o $(EXE)

run: 
	./$(EXE)

clean:
	rm $(EXE)

help:
		@echo "src: $(SRC)"
		@echo "include: $(INC)"
		
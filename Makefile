CC=gcc
FLAGS=-Wall -g
FILENAME=01--print-horizontal-histogram-of-length-of-words-using-function-pointers
#FILENAME=02--arrays-of-function-pointers

all: build run

build:
	$(CC) $(FLAGS) $(FILENAME).c -o $(FILENAME).out

run:
	$(FILENAME).out

clean:
	rm -fr $(FILENAME).out $(FILENAME).out.dSYM

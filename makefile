override NUM_THREADS ?= 5
CC=g++ -w

execute:CC+= -DN=$(NUM_THREADS)
execute: 
	$(CC) main.cpp -lGL -lGLU -lglut -pthread
	./a.out

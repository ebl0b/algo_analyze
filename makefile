SRC=start.c algorithm.c ui.c io.c analyze.c generator.c
OBJ=$(patsubst %.c,%.o,$(SRC))
HDR=algorithm.h ui.h io.h analyze.h generator.h
CC=gcc

prog: $(OBJ)
	$(CC) -o prog $(OBJ)
start.o: start.c
	$(CC) -Wall -c $< -o start.o
algorithm.o: algorithm.c algorithm.h
	$(CC) -Wall -c $< -o algorithm.o
ui.o: ui.c $(HDR)
	$(CC) -Wall -c $< -o ui.o
analyze.o: analyze.c algorithm.h generator.h analyze.h
	$(CC) -Wall -c $< -o analyze.o
io.o: io.c io.h analyze.h
	$(CC) -Wall -c $< -o io.o
generator.o: generator.c generator.h 
	$(CC) -Wall -c $< -o generator.o

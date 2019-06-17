# declaring variables:

# The compiler:

CC = gcc

# The flags:

CFlags = -Wall -Werror -Wextra -pedantic -std=c99 

Copt1 = -c

Copt2 = -o

all: sorter

sorter: main.o sort.o array_helpers.o arguments_parser.o
	$(CC) main.o sort.o array_helpers.o arguments_parser.o $(Copt2) sorter

main.o: main.c
	$(CC) $(CFlags) $(Copt1) main.c

sort.o: sort.c
	$(CC) $(CFlags) $(Copt1) sort.c

array_helpers.o: array_helpers.c
	$(CC) $(CFlags) $(Copt1) array_helpers.c

arguments_parser.o: arguments_parser.c
	$(CC) $(CFlags) $(Copt1) arguments_parser.c

clean:
	rm *.o sorter

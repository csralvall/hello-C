# The compiler:

CC = gcc

# The flags:

F = -Wall -Wextra -pedantic -std=c99

Ferr = -Werror

# The options:

Obj = -o

Comp = -c

all: weather

weather: array_helpers.o weather.o main.c
	$(CC) $(F) $(Ferr) $(Comp) $(Obj) array_helpers.o weather.o main.c
	weather

array_helpers.o: array_helpers.c 
	$(CC) $(F) $(Ferr) $(Comp) array_helpers.c

weather.o: weather.c
	$(CC) $(F) $(Ferr) $(Comp) weather.c

clean:
	rm *.o weather

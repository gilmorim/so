CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = execs.c
OBJ = $(SRC:.c=.o)
EXEC = execs

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
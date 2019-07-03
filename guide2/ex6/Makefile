CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = matrix.c
OBJ = $(SRC:.c=.o)
EXEC = matrix

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
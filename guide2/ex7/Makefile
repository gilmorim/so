CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = matrix_v2.c
OBJ = $(SRC:.c=.o)
EXEC = matrix_v2

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = fork.c
OBJ = $(SRC:.c=.o)
EXEC = fork

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = ls.c
OBJ = $(SRC:.c=.o)
EXEC = ls

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
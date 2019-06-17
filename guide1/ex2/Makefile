CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = 10mb.c
OBJ = $(SRC:.c=.o)
EXEC = 10mb

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC) 10mb.dat
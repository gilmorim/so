CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = args.c
OBJ = $(SRC:.c=.o)
EXEC = args

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
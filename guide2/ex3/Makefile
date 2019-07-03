CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = 10proc.c
OBJ = $(SRC:.c=.o)
EXEC = 10proc

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = my_system.c
OBJ = $(SRC:.c=.o)
EXEC = my_system

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
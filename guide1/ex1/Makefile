CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = mycat.c
OBJ = $(SRC:.c=.o)
EXEC = mycat

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
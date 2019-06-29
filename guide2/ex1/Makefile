CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = pid.c
OBJ = $(SRC:.c=.o)
EXEC = pid

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
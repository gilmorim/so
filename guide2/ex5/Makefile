CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRC = 10proc_v3.c
OBJ = $(SRC:.c=.o)
EXEC = 10proc_v3

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)
CC = gcc
CFLAGS = -Wall -Wextra -g 
LDFLAGS =

SRC = readln.c
OBJ = $(SRC:.c=.o)
EXEC = readln

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
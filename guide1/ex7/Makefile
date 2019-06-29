CC = gcc
CFLAGS = -Wall -Wextra -g 
LDFLAGS = 

SRC = nlV2.c
OBJ = $(SRC:.c=.o)
EXEC = nl

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
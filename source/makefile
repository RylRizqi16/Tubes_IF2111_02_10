CC = gcc
CFLAGS = -Wall -Wextra -std=c99

EXEC = PURRMART

SRC = main.c \
	command/load.c \
	command/login_logout.c \
	command/register.c \
	command/work.c \
	command/work_challenge.c \
	command/store.c \
	command/help.c \
	command/save.c \
	command/quit.c \
	ADT/Mesin_Kata/mesinkata.c \
	ADT/ArrayDinBarang/arraydinbarang.c \
	ADT/ArrayStatikUser/arrayuser.c \
	ADT/Barang/barang.c \
	ADT/Mesin_Karakter/mesinkarakter.c \
	ADT/QueueBarang/queue_barang.c \
	ADT/User/user.c  # Removed the backslash here

OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean

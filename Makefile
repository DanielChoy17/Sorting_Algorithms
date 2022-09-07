CC = clang 
CFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -lm

all: sorting



sorting: sorting.o stats.o heap.o shell.o insert.o quick.o
	$(CC) $(CFLAGS) -o sorting sorting.o stats.o heap.o shell.o insert.o quick.o $(LFLAGS)

stat.o: stats.c
	$(CC) $(CFLAGS) -c stats.c

heap.o: heap.c
	$(CC) $(CFLAGS) -c heap.c

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c

insert.o: insert.c
	$(CC) $(CFLAGS) -c insert.c

quick.o: quick.c
	$(CC) $(CFLAGS) -c quick.c


format:
	clang-format -i -style=file *.c *.h

clean:
	rm -f sorting *.o

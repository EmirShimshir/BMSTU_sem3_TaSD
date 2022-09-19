CC := gcc

CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla

OBJS := read.o print.o multiply.o main.c

app.exe : $(OBJS)
	$(CC) -o app.exe $(OBJS)

read.o : read.c read.h
	$(CC) $(CFLAGS) -c read.c

print.o : print.c print.h
	$(CC) $(CFLAGS) -c print.c

multiply.o : multiply.c multiply.h
	$(CC) $(CFLAGS) -c multiply.c

main.o : main.c types.h read.h print.h multiply.h
	$(CC) $(CFLAGS) -c main.c

.PHONY : clean
clean :
	rm -f *.o *.exe *.sh *.gcda *.gcov *.gcno
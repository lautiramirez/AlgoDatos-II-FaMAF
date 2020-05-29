clear: 
	rm -f main.o
	rm -f queue.o
	rm -f test

comp:
	gcc -Wall -Wextra -Werror -pedantic -std=c99 -c queue.c main.c
	gcc -Wall -Wextra -Werror -pedantic -std=c99 -o test queue.o main.o

leak:
	valgrind --show-reachable=yes --leak-check=full ./test

gdb:
	make clear
	gcc -Wall -Wextra -Werror -pedantic -std=c99 -no-pie -g -c queue.c main.c
	gcc -Wall -Wextra -Werror -pedantic -std=c99 -no-pie -g -o test queue.o main.o
	gdb ./test

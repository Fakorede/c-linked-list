run: list_test.c list.c
	gcc -Wall -o list_test list_test.c list.c
	./list_test

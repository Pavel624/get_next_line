all:
	gcc -o get_next_line.o -c get_next_line.c -g 
	gcc -o main.o -c main.c -g
	gcc -o gnl_test main.o get_next_line.o -L libft/ -lft


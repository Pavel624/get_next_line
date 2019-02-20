all:
	make -C libft/ fclean && make -C libft/
	clang -o get_next_line.o -c get_next_line.c -g 
	clang -o main.o -c main.c -g
	clang -o gnl_test main.o get_next_line.o -L libft/ -lft


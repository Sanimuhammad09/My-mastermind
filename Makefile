all: my_mastermind.c
	gcc -Wall -Wextra -Werror  -o  my_mastermind  my_mastermind.c
clean:
	rm -f *.o
fclean: clean
	rm -f *.o my_mastermind
re:
	fclean all 


// Main function to test errors in libft
// Compile with command :
// make re 			(ou "make fclean" puis "make all" ou "make" ou "make libft.a")
// gcc -Wall -Wextra -Werror main.c -L. -lft && ./a.out

// lib for printf() and write()
#include <stdio.h>
#include <unistd.h>

// lib for isalpha() and isdigit()
#include <ctype.h>
#include "ft_isalpha.h"
#include "ft_isdigit.h"

// test function
int		print_errors(int test_index, char *function_name, int ft_function, int c_function)
{
	if (ft_function != c_function)
	{
		printf("%d. ERROR in function \"%s\"\n", test_index, function_name);
		printf("ft_function : %d\nC_function : %d\n\n", ft_function, c_function);
		return(1);
	}
	return (0);
}


int	main(void)
{
	// Makefile test : 
	printf("Makefile okay\n");

	// ft_isalpha
	print_errors(1, "ft_isalpha",		ft_isalpha('c'),	isalpha('c'));
	print_errors(2, "ft_isalpha",		ft_isalpha('?'),	isalpha('?'));
	print_errors(3, "ft_isalpha",		ft_isalpha('Z'),	isalpha('Z'));
	print_errors(4, "ft_isalpha",		ft_isalpha(2),		isalpha(2));
	print_errors(5, "ft_isalpha",		ft_isalpha('9'),	isalpha('9'));
	print_errors(6, "ft_isalpha",		ft_isalpha(99),		isalpha(99));
	print_errors(7, "ft_isalpha",		ft_isalpha(' '),	isalpha(' '));

	// ft_isdigit
	print_errors(1, "ft_isdigit",		ft_isdigit('c'),	isdigit('c'));
	print_errors(2, "ft_isdigit",		ft_isdigit('?'),	isdigit('?'));
	print_errors(3, "ft_isdigit",		ft_isdigit(' '),	isdigit(' '));
	print_errors(4, "ft_isdigit",		ft_isdigit(0),		isdigit(0));
	print_errors(5, "ft_isdigit",		ft_isdigit('0'),	isdigit('0'));
	print_errors(6, "ft_isdigit",		ft_isdigit(2),		isdigit(2));
	print_errors(7, "ft_isdigit",		ft_isdigit('2'),	isdigit('2'));
	print_errors(8, "ft_isdigit",		ft_isdigit(11),		isdigit(11));


	// ft_isalnum

	return (0);
}
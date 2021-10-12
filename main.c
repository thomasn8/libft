/* --------------------- */
// MAIN TO TEST LIBFT.A //
/* ------------------- */

// Compile with command :
// 1.				make re				(ou "make fclean" puis "make all" ou "make" ou "make libft.a")
// 1.5 (optional)	ranlib libft.a 		(créer index dans lib pour aller chercher rapidement les fonctions nécessaires)
// 2.				gcc -Wall -Wextra -Werror main.c -L. -lft && ./a.out
// 2.5 (optional) 	ar -t libft.a 		(display the modules/functions)

// lib for printf() and write()
#include <stdio.h>
#include <unistd.h>

// lib for isalpha() and isdigit()
#include <ctype.h>
#include "ft_isalpha.h"
#include "ft_isdigit.h"
#include "ft_isalnum.h"
#include "ft_isascii.h"
#include "ft_isprint.h"

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
	print_errors(9, "ft_isalpha",		ft_isalpha('\n'),	isalpha('\n'));

	// ft_isdigit
	print_errors(1, "ft_isdigit",		ft_isdigit('c'),	isdigit('c'));
	print_errors(2, "ft_isdigit",		ft_isdigit('?'),	isdigit('?'));
	print_errors(3, "ft_isdigit",		ft_isdigit(' '),	isdigit(' '));
	print_errors(4, "ft_isdigit",		ft_isdigit(0),		isdigit(0));
	print_errors(5, "ft_isdigit",		ft_isdigit('0'),	isdigit('0'));
	print_errors(6, "ft_isdigit",		ft_isdigit(2),		isdigit(2));
	print_errors(7, "ft_isdigit",		ft_isdigit('2'),	isdigit('2'));
	print_errors(8, "ft_isdigit",		ft_isdigit(11),		isdigit(11));
	print_errors(9, "ft_isdigit",		ft_isdigit('\n'),	isdigit('\n'));

	// ft_isalnum
	print_errors(1, "ft_isalnum",		ft_isalnum('c'),	isalnum('c'));
	print_errors(2, "ft_isalnum",		ft_isalnum('?'),	isalnum('?'));
	print_errors(3, "ft_isalnum",		ft_isalnum(' '),	isalnum(' '));
	print_errors(4, "ft_isalnum",		ft_isalnum(0),		isalnum(0));
	print_errors(5, "ft_isalnum",		ft_isalnum(11),		isalnum(11));
	print_errors(6, "ft_isalnum",		ft_isalnum('\n'),	isalnum('\n'));

	// ft_isascii
	print_errors(1, "ft_isascii",		ft_isascii('c'),	isascii('c'));
	print_errors(2, "ft_isascii",		ft_isascii('?'),	isascii('?'));
	print_errors(3, "ft_isascii",		ft_isascii(' '),	isascii(' '));
	print_errors(4, "ft_isascii",		ft_isascii(0),		isascii(0));
	print_errors(5, "ft_isascii",		ft_isascii(11),		isascii(11));
	print_errors(6, "ft_isascii",		ft_isascii('\n'),	isascii('\n'));
	print_errors(7, "ft_isascii",		ft_isascii(0x7c),	isascii(0x7c));
	print_errors(8, "ft_isascii",		ft_isascii(0x80),	isascii(0x80));
	print_errors(9, "ft_isascii",		ft_isascii(0x81),	isascii(0x81));
	// printf("%d\n", ft_isascii(0x7c)); printf("%d\n", isascii(0x7c));
	// printf("%d\n", ft_isascii(0x80)); printf("%d\n", isascii(0x80));
	// printf("%d\n", ft_isascii(0x81)); printf("%d\n", isascii(0x81));

	// ft_isprint
	print_errors(1, "ft_isprint",		ft_isprint('c'),	isprint('c'));
	print_errors(2, "ft_isprint",		ft_isprint('\t'),	isprint('\t'));
	print_errors(3, "ft_isprint",		ft_isprint('Z'),	isprint('Z'));
	print_errors(4, "ft_isprint",		ft_isprint(2),		isprint(2));
	print_errors(5, "ft_isprint",		ft_isprint('9'),	isprint('9'));
	print_errors(6, "ft_isprint",		ft_isprint(99),		isprint(99));
	print_errors(7, "ft_isprint",		ft_isprint(' '),	isprint(' '));
	print_errors(9, "ft_isprint",		ft_isprint('\n'),	isprint('\n'));
	print_errors(10, "ft_isprint",		ft_isprint(0x7c),	isprint(0x7c));
	print_errors(11, "ft_isprint",		ft_isprint(0x80),	isprint(0x80));
	print_errors(12, "ft_isprint",		ft_isprint(0),		isprint(0));
	
	return (0);
}
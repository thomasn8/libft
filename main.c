/* --------------------- */
// MAIN TO TEST LIBFT.A //
/* ------------------- */

// Compile with command :
// 1.				make re				(ou "make fclean" puis "make all" ou "make" ou "make libft.a")
// 1.5 (optional)	ranlib libft.a 		(créer index dans lib pour aller chercher rapidement les fonctions nécessaires)
// 2.				gcc -Wall -Wextra -Werror main.c -L. -lft && ./a.out
// 2.5 (optional) 	ar -t libft.a 		(display the modules/functions)
// OR,	one command :
// make re && gcc -Wall -Wextra -Werror main.c -L. -lft && ./a.out

// libft.h
#include "libft.h"

// lib for printf() and write()
#include <stdio.h>
#include <unistd.h>

// lib for isalpha() and equivalents
#include <ctype.h>

// lib for strlen() and equivalents
#include <string.h>

// test function
static int error_count = 0;		//global variable to get total of errors at the end of the tests
static int test_index = 1;
int		print_errors(char *function_name, int ft_function, int c_function)
{
	test_index++;
	if (ft_function != c_function)
	{
		printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
		printf("ft_function : %d\nC_function : %d\n\n", ft_function, c_function);
		error_count++;
		return(1);
	}
	return (0);
}


int	main(void)
{
	// Makefile test : 
	printf("\nMakefile is okay\n\n");

	// ft_isalpha
	print_errors("ft_isalpha",		ft_isalpha('c'),	isalpha('c'));
	print_errors("ft_isalpha",		ft_isalpha('?'),	isalpha('?'));
	print_errors("ft_isalpha",		ft_isalpha('Z'),	isalpha('Z'));
	print_errors("ft_isalpha",		ft_isalpha(2),		isalpha(2));
	print_errors("ft_isalpha",		ft_isalpha('9'),	isalpha('9'));
	print_errors("ft_isalpha",		ft_isalpha(99),		isalpha(99));
	print_errors("ft_isalpha",		ft_isalpha(' '),	isalpha(' '));
	print_errors("ft_isalpha",		ft_isalpha('\n'),	isalpha('\n'));

	// ft_isdigit
	print_errors("ft_isdigit",		ft_isdigit('c'),	isdigit('c'));
	print_errors("ft_isdigit",		ft_isdigit('?'),	isdigit('?'));
	print_errors("ft_isdigit",		ft_isdigit(' '),	isdigit(' '));
	print_errors("ft_isdigit",		ft_isdigit(0),		isdigit(0));
	print_errors("ft_isdigit",		ft_isdigit('0'),	isdigit('0'));
	print_errors("ft_isdigit",		ft_isdigit(2),		isdigit(2));
	print_errors("ft_isdigit",		ft_isdigit('2'),	isdigit('2'));
	print_errors("ft_isdigit",		ft_isdigit(11),		isdigit(11));
	print_errors("ft_isdigit",		ft_isdigit('\n'),	isdigit('\n'));

	// ft_isalnum
	print_errors("ft_isalnum",		ft_isalnum('c'),	isalnum('c'));
	print_errors("ft_isalnum",		ft_isalnum('?'),	isalnum('?'));
	print_errors("ft_isalnum",		ft_isalnum(' '),	isalnum(' '));
	print_errors("ft_isalnum",		ft_isalnum(0),		isalnum(0));
	print_errors("ft_isalnum",		ft_isalnum(11),		isalnum(11));
	print_errors("ft_isalnum",		ft_isalnum('\n'),	isalnum('\n'));

	// ft_isascii
	print_errors("ft_isascii",		ft_isascii('c'),	isascii('c'));
	print_errors("ft_isascii",		ft_isascii('?'),	isascii('?'));
	print_errors("ft_isascii",		ft_isascii(' '),	isascii(' '));
	print_errors("ft_isascii",		ft_isascii(0),		isascii(0));
	print_errors("ft_isascii",		ft_isascii(11),		isascii(11));
	print_errors("ft_isascii",		ft_isascii('\n'),	isascii('\n'));
	print_errors("ft_isascii",		ft_isascii(0x7c),	isascii(0x7c));
	print_errors("ft_isascii",		ft_isascii(0x80),	isascii(0x80));
	print_errors("ft_isascii",		ft_isascii(0x81),	isascii(0x81));
	// printf("%d\n", ft_isascii(0x7c)); printf("%d\n", isascii(0x7c));
	// printf("%d\n", ft_isascii(0x80)); printf("%d\n", isascii(0x80));
	// printf("%d\n", ft_isascii(0x81)); printf("%d\n", isascii(0x81));

	// ft_isprint
	print_errors("ft_isprint",		ft_isprint('c'),	isprint('c'));
	print_errors("ft_isprint",		ft_isprint('\t'),	isprint('\t'));
	print_errors("ft_isprint",		ft_isprint('Z'),	isprint('Z'));
	print_errors("ft_isprint",		ft_isprint(2),		isprint(2));
	print_errors("ft_isprint",		ft_isprint('9'),	isprint('9'));
	print_errors("ft_isprint",		ft_isprint(99),		isprint(99));
	print_errors("ft_isprint",		ft_isprint(' '),	isprint(' '));
	print_errors("ft_isprint",		ft_isprint('\n'),	isprint('\n'));
	print_errors("ft_isprint",		ft_isprint(0x7c),	isprint(0x7c));
	print_errors("ft_isprint",		ft_isprint(0x80),	isprint(0x80));
	print_errors("ft_isprint",		ft_isprint(0),		isprint(0));

	// ft_strlen
	print_errors("ft_strlen",		ft_strlen("salut"),	ft_strlen("salut"));
	print_errors("ft_strlen",		ft_strlen("salut lausanne"),	ft_strlen("salut lausanne"));
	char *lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n";
	print_errors("ft_strlen",		ft_strlen(lorem),	ft_strlen(lorem));
	// printf("%lu\n", ft_strlen("salut lausanne")); printf("%lu\n", strlen("salut lausanne"));
	// printf("%lu\n", ft_strlen(lorem)); printf("%lu\n", strlen(lorem));

	printf("%d errors in tests.\n", error_count);
	return (0);
}
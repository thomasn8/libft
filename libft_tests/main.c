/* ------------------------------ */
// 			LIBFT TESTS			 //
/* ---------------------------- */
//
// -------------------------------------------------------------------------------
// | make re && gcc -Wall -Wextra -Werror libft_tests/main.c -L. -lft && ./a.out |
// -------------------------------------------------------------------------------
//
// 	a) 	make all	(ou "make fclean" puis "make all" ou "make" ou "make libft.a")
// 				a.a) 	Optional:	ranlib libft.a 	(créer index dans lib pour trouver rapidement les fonctions nécessaires)
// 	b)	gcc -Wall -Wextra -Werror libft_tests/main.c -L. -lft && ./a.out
// 				b.b) 	Optional:	ar -t libft.a 	(display the modules/functions)

// libft.h
#include "../libft.h"

// lib for printf() and write()
#include <stdio.h>
#include <unistd.h>
#include "focus_on_backslash_zero.c"

// lib for isalpha() and equivalents
#include <ctype.h>

// lib for strlen() and equivalents
#include <string.h>

// lib for atoi()
#include <stdlib.h>

// test function
static int error_count = 0;		// global variable to get total of errors at the end of the tests
static int test_index = 1;

void	defaut_color(void)
{
	printf("\033[0m");
} 
void	red_color(void)
{
	printf("\033[0;31m");
}
void	green_color(void)
{
	printf("\033[0;32m");
}

int		print_errors(char *function_name, int ft_function, int c_function)
{
	test_index++;
	if (ft_function != c_function)
	{	
		red_color();
		printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
		defaut_color();
		printf("ft_function : %d\nExpected :  %d\n\n", ft_function, c_function);
		error_count++;
		return(1);
	}
	return (0);
}

int		print_errors_string(char *function_name, char *ft_str, char *c_str)
{
	test_index++;
	if (strcmp(ft_str, c_str) != 0)
	{
		red_color();
		printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
		defaut_color();
		printf("ft_function : %s\nExpected :  %s\n\n", ft_str, c_str);
		error_count++;
		return(1);
	}
	return (0);
}

int		print_errors_pointer(char *function_name, char *ft_str, char *c_str)
{
	test_index++;
	if (ft_str != c_str)
	{
		red_color();
		printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
		defaut_color();
		printf("ft_function : %p\nExpected :  %p\n\n", ft_str, c_str);
		error_count++;
		return(1);
	}
	return (0);
}

int		print_errors_int_calloc(char *function_name, int *ft_str, int *c_str)
{
	test_index++;
	if (*ft_str != *c_str)
	{
		red_color();
		printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
		defaut_color();
		printf("ft_function : %d\nExpected :  %d\n\n", *ft_str, *c_str);
		error_count++;
		return(1);
	}
	return (0);
}

int		print_errors_char_calloc(char *function_name, char *ft_str, char *c_str)
{
	test_index++;
	if (*ft_str != *c_str)
	{
		red_color();
		printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
		defaut_color();
		printf("ft_function : %c\nExpected :  %c\n\n", *ft_str, *c_str);
		error_count++;
		return(1);
	}
	return (0);
}

int		print_errors_size(char *function_name, size_t ft_str, size_t c_str)
{
	test_index++;
	if (ft_str != c_str)
	{
		red_color();
		printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
		defaut_color();
		printf("ft_function : %zu\nExpected :  %zu\n\n", ft_str, c_str);
		error_count++;
		return(1);
	}
	return (0);
}

int		substr_test(char *function_name, char *ft_str, char *str, unsigned int substr_start, size_t substr_len)
{
	size_t substr_index = -1;

	test_index++;
	while(++substr_index < substr_len)
	{
		// printf("Char from ft_function str: %c\nChar from original str :  %c\n\n", ft_str[substr_index], str[substr_start + substr_index]);
		if(ft_str[substr_index] != str[substr_start + substr_index])
		{
			red_color();
			printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
			defaut_color();
			printf("Char from ft_function str: %c\nChar from original str :  %c\n\n", ft_str[substr_index], str[substr_start + substr_index]);
			error_count++;
			return(1);
		}
	}
	return (0);
}

int		strjoin_test(char *function_name, char *str, char *strjoin)
{
	int i = -1;

	test_index++;
	while(str[++i])
	{
		// printf("Char from ft_function str: %c\nChar from original str :  %c\n\n", ft_str[substr_index], str[substr_start + substr_index]);
		if(str[i] != strjoin[i])
		{
			red_color();
			printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
			defaut_color();
			printf("Expected : %s\nStrjoin :  %s\n\n", str, strjoin);
			error_count++;
			return(1);
		}
	}
	if(strjoin[i] != 0 && str[i] != strjoin[i])
		{
			red_color();
			printf("ERROR (test n.%d) in function \"%s\"\n", test_index, function_name);
			defaut_color();
			printf("Expected : %s\nStrjoin :  %s\n\n", str, strjoin);
			error_count++;
			return(1);
		}
	return (0);
}

int	main(void)
{
	// Makefile test :
	green_color(); 
	printf("\nMakefile is okay\n\n");
	defaut_color();
	//////////////////////////////////////////////////////////////////

	// #include <ctype.h> ////////////////////////////////////////////
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

	// ft_toupper
	print_errors("ft_toupper",		ft_toupper('c'),	toupper('c'));
	print_errors("ft_toupper",		ft_toupper('?'),	toupper('?'));
	print_errors("ft_toupper",		ft_toupper('Z'),	toupper('Z'));
	print_errors("ft_toupper",		ft_toupper(2),		toupper(2));
	print_errors("ft_toupper",		ft_toupper('9'),	toupper('9'));
	print_errors("ft_toupper",		ft_toupper(99),		toupper(99));
	print_errors("ft_toupper",		ft_toupper(' '),	toupper(' '));
	print_errors("ft_toupper",		ft_toupper('\n'),	toupper('\n'));
	print_errors("ft_toupper",		ft_toupper(0x81),	toupper(0x81));
	print_errors("ft_toupper",		ft_toupper(0),		toupper(0));

	// ft_tolower
	print_errors("ft_tolower",		ft_tolower('c'),	tolower('c'));
	print_errors("ft_tolower",		ft_tolower('?'),	tolower('?'));
	print_errors("ft_tolower",		ft_tolower('Z'),	tolower('Z'));
	print_errors("ft_tolower",		ft_tolower(2),		tolower(2));
	print_errors("ft_tolower",		ft_tolower('9'),	tolower('9'));
	print_errors("ft_tolower",		ft_tolower(99),		tolower(99));
	print_errors("ft_tolower",		ft_tolower(' '),	tolower(' '));
	print_errors("ft_tolower",		ft_tolower('\n'),	tolower('\n'));
	print_errors("ft_tolower",		ft_tolower(0x81),	tolower(0x81));
	print_errors("ft_tolower",		ft_tolower(0),		tolower(0));

	//////////////////////////////////////////////////////////////////

	// #include <string.h>////////////////////////////////////////////
	// ft_strlen
	print_errors("ft_strlen",		ft_strlen("salut"),	ft_strlen("salut"));
	print_errors("ft_strlen",		ft_strlen("salut lausanne"),	ft_strlen("salut lausanne"));
	char *lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n";
	print_errors("ft_strlen",		ft_strlen(lorem),	ft_strlen(lorem));
	// printf("%lu\n", ft_strlen("salut lausanne")); printf("%lu\n", strlen("salut lausanne"));
	// printf("%lu\n", ft_strlen(lorem)); printf("%lu\n", strlen(lorem));

	// ft_memset
	char ft_str1[15] = "Hi you";
	char str1[15] = "Hi you";
	ft_memset(ft_str1 + 2, '_', 1);	memset(str1 + 2, '_', 1);
	print_errors_string("ft_memset",		ft_str1,		str1);
	//
	char ft_str2[15] = "Salut la Terre";
	char str2[15] = "Salut la Terre";
	ft_memset(ft_str2 + 2, '.', 4);	memset(str2 + 2, '.', 4);
	print_errors_string("ft_memset",		ft_str2,		str2);
	//
	// printf("%s\n", ft_str1); 
	// printf("%s\n", str1);
	// printf("%s\n", ft_str2); 
	// printf("%s\n", str2);

	// ft_bzero
	char ft_bzero1[4] = "abc\0";
	char c_bzero1[4] = "abc\0";
	ft_bzero(ft_bzero1, 1);	bzero(c_bzero1, 1);
	print_errors_string("ft_bzero",		ft_bzero1,		c_bzero1);
	//
	char ft_bzero2[4] = "abc\0";
	char c_bzero2[4] = "abc\0";
	ft_bzero(ft_bzero2, 0);	bzero(c_bzero2, 0);
	print_errors_string("ft_bzero",		ft_bzero2,		c_bzero2);
	//
	char ft_bzero3[4] = "abc\0";
	char c_bzero3[4] = "abc\0";
	ft_bzero(ft_bzero3 + 1, 1);	bzero(c_bzero3 + 1, 1);
	print_errors_string("ft_bzero",		ft_bzero3,		c_bzero3);
	//
	char ft_str3[15] = "Pointerrr";
	char str3[15] = "Pointerrr";
	ft_bzero(ft_str3 + 5, 4);	bzero(str3 + 5, 4);
	print_errors_string("ft_bzero",		ft_str3,		str3);
	//
	char ft_str4[40] = "Hello World ! Je suis ton père";
	char str4[40] = "Hello World ! Je suis ton père";
	ft_bzero(ft_str4 + 14, 18);	bzero(str4 + 14, 18);
	print_errors_string("ft_bzero",		ft_str4,		str4);
	//
	// printf("%s\n", ft_str3); 
	// printf("%s\n", str3);
	// printf("%s\n", ft_str4); 
	// printf("%s\n", str4);

	// ft_memcpy
	char ft_memcpy_src1[15] = "Hello World !!";
	char ft_memcpy_dest1[15] = {0};
	ft_memcpy(ft_memcpy_dest1+5, ft_memcpy_src1, 1);
	char c_memcpy_src1[15] = "Hello World !!";
	char c_memcpy_dest1[15] = {0};
	memcpy(c_memcpy_dest1+5, c_memcpy_src1, 1);
	print_errors_string("ft_memcpy",		ft_memcpy_dest1,		c_memcpy_dest1);
	//
	char ft_memcpy_src2[15] = "Hello W\0orld !!";
	char ft_memcpy_dest2[15] = {0};
	ft_memcpy(ft_memcpy_dest2+0, ft_memcpy_src2, 14);
	char c_memcpy_src2[15] = "Hello W\0orld !!";
	char c_memcpy_dest2[15] = {0};
	memcpy(c_memcpy_dest2+0, c_memcpy_src2, 14);
	print_errors_string("ft_memcpy",		ft_memcpy_dest2,		c_memcpy_dest2);
	//
	char ft_memcpy_src6[15] = "Hello World !!";
	char ft_memcpy_dest6[15] = {0};
	ft_memcpy(ft_memcpy_dest6+0, ft_memcpy_src6, 14);
	char c_memcpy_src6[15] = "Hello World !!";
	char c_memcpy_dest6[15] = {0};
	memcpy(c_memcpy_dest6+0, c_memcpy_src6, 14);
	print_errors_string("ft_memcpy",		ft_memcpy_dest6,		c_memcpy_dest6);
	//
	// printf("ft_memcpy : %s\n", ft_memcpy_dest1);
	// printf("memcpy : %s\n", c_memcpy_dest1);
	// printf("ft_memcpy : %s\n", ft_memcpy_dest2);
	// printf("ft_memcpy char : %c\n", ft_memcpy_dest2[11]);
	// printf("memcpy : %s\n", c_memcpy_dest2);
	// printf("memcpy char : %c\n", c_memcpy_dest2[11]);
	// printf("ft_memcpy : %s\n", ft_memcpy_dest6);
	// printf("memcpy : %s\n", c_memcpy_dest6);

	// ft_memmove
	char ft_memmove_src1[15] = "Hello World !!";
	char ft_memmove_dest1[15] = {0};
	ft_memmove(ft_memmove_dest1+5, ft_memmove_src1, 1);
	char c_memmove_src1[15] = "Hello World !!";
	char c_memmove_dest1[15] = {0};
	memmove(c_memmove_dest1+5, c_memmove_src1, 1);
	print_errors_string("ft_memmove",		ft_memmove_dest1,		c_memmove_dest1);
	//
	char ft_memmove_src2[15] = "Hello W\0orld !!";
	char ft_memmove_dest2[15] = {0};
	ft_memmove(ft_memmove_dest2+0, ft_memmove_src2, 14);
	char c_memmove_src2[15] = "Hello W\0orld !!";
	char c_memmove_dest2[15] = {0};
	memmove(c_memmove_dest2+0, c_memmove_src2, 14);
	print_errors_string("ft_memmove",		ft_memmove_dest2,		c_memmove_dest2);
	//
	char ft_memmove_src6[15] = "Hello World !!";
	char ft_memmove_dest6[15] = {0};
	ft_memmove(ft_memmove_dest6+0, ft_memmove_src6, 14);
	char c_memmove_src6[15] = "Hello World !!";
	char c_memmove_dest6[15] = {0};
	memmove(c_memmove_dest6+0, c_memmove_src6, 14);
	print_errors_string("ft_memmove",		ft_memmove_dest6,		c_memmove_dest6);
	//
	// printf("ft_memmove : %s\n", ft_memmove_dest1);
	// printf("memmove : %s\n", c_memmove_dest1);
	// printf("ft_memmove : %s\n", ft_memmove_dest2);
	// printf("ft_memmove char : %c\n", ft_memmove_dest2[11]);
	// printf("memmove : %s\n", c_memmove_dest2);
	// printf("memmove char : %c\n", c_memmove_dest2[11]);
	// printf("ft_memmove : %s\n", ft_memmove_dest6);
	// printf("memmove : %s\n", c_memmove_dest6);

	// ft_strlcpy
	char ft_strlcpy_src1[14] = "Hello\0 World";
	char ft_strlcpy_dst1[14] = {0};
	char c_strlcpy_src1[14] = "Hello\0 World";
	char c_strlcpy_dst1[14] = {0};
	print_errors_size("ft_strlcpy",	ft_strlcpy(ft_strlcpy_dst1, ft_strlcpy_src1, 5),	strlcpy(c_strlcpy_dst1, c_strlcpy_src1, 5));
	print_errors_string("ft_strlcpy",	ft_strlcpy_dst1,	c_strlcpy_dst1);
	// 
	char ft_strlcpy_src2[14] = "Hello World !";
	char ft_strlcpy_dst2[14] = {0};
	char c_strlcpy_src2[14] = "Hello World !";
	char c_strlcpy_dst2[14] = {0};
	print_errors_size("ft_strlcpy",	ft_strlcpy(ft_strlcpy_dst2, ft_strlcpy_src2, 0),	strlcpy(c_strlcpy_dst2, c_strlcpy_src2, 0));
	print_errors_string("ft_strlcpy",	ft_strlcpy_dst2,	c_strlcpy_dst2);
	// 
	char ft_strlcpy_src3[14] = "Hello World !";
	char ft_strlcpy_dst3[14] = {0};
	char c_strlcpy_src3[14] = "Hello World !";
	char c_strlcpy_dst3[14] = {0};
	print_errors_size("ft_strlcpy",	ft_strlcpy(ft_strlcpy_dst3, ft_strlcpy_src3, 14),	strlcpy(c_strlcpy_dst3, c_strlcpy_src3, 14));
	print_errors_string("ft_strlcpy",	ft_strlcpy_dst3,	c_strlcpy_dst3);
	// 
	// printf("ft_strlcpy_dst1 : %s\n", ft_strlcpy_dst1);
	// printf("c_strlcpy_dst1 : %s\n", c_strlcpy_dst1);
	// printf("ft_strlcpy_dst1 : %s\n", ft_strlcpy_dst2);
	// printf("c_strlcpy_dst1 : %s\n", c_strlcpy_dst2);
	// printf("ft_strlcpy_dst1 : %s\n", ft_strlcpy_dst3);
	// printf("c_strlcpy_dst1 : %s\n", c_strlcpy_dst3);

	// ft_strlcat	(VALEUR DE RETOUR ABSURDE....)
	/////////1
	char ft_strlcat_src1[7] = "WORLD";
	char ft_strlcat_dst1[20] = "HELLOOO";
	size_t ft_strlcat_value1 = 0;
	// printf("ft_strlcat_dst1 (before) : %s\n", ft_strlcat_dst1);
	ft_strlcat_value1 = ft_strlcat(ft_strlcat_dst1, ft_strlcat_src1, 0);
	// printf("ft_strlcat_dst1 (after) : %s\n", ft_strlcat_dst1);
	// printf("Return value = %zu\n", ft_strlcat_value1);
	//
	char c_strlcat_src1[7] = "WORLD";
	char c_strlcat_dst1[20] = "HELLOOO";
	size_t c_strlcat_value1 = 0;
	// printf("c_strlcat_dst1 (before): %s\n", c_strlcat_dst1);
	c_strlcat_value1 = strlcat(c_strlcat_dst1, c_strlcat_src1, 0);
	// printf("c_strlcat_dst1 (after): %s\n", c_strlcat_dst1);
	// printf("Return value = %zu\n", c_strlcat_value1);
	//
	// 	focus_on_backslash_zero(ft_strlcat_dst1, 20);
	// focus_on_backslash_zero(c_strlcat_dst1, 20);
	//
	print_errors_size("ft_strlcat",	ft_strlcat_value1,	c_strlcat_value1);
	print_errors_string("ft_strlcat",	ft_strlcat_dst1,	c_strlcat_dst1);
	/////////2
	char ft_strlcat_src2[7] = "WORLD";
	char ft_strlcat_dst2[20] = "HELLOOO";
	size_t ft_strlcat_value2 = 0;
	// printf("ft_strlcat_dst2 (before) : %s\n", ft_strlcat_dst2);
	ft_strlcat_value2 = ft_strlcat(ft_strlcat_dst2, ft_strlcat_src2, 1);
	// printf("ft_strlcat_dst2 (after) : %s\n", ft_strlcat_dst2);
	// printf("Return value = %zu\n", ft_strlcat_value2);
	//
	char c_strlcat_src2[7] = "WORLD";
	char c_strlcat_dst2[20] = "HELLOOO";
	size_t c_strlcat_value2 = 0;
	// printf("c_strlcat_dst1 (before): %s\n", c_strlcat_dst2);
	c_strlcat_value2 = strlcat(c_strlcat_dst2, c_strlcat_src2, 1);
	// printf("c_strlcat_dst1 (after): %s\n", c_strlcat_dst2);
	// printf("Return value = %zu\n", c_strlcat_value2);
	//
	// focus_on_backslash_zero(ft_strlcat_dst2, 20);
	// focus_on_backslash_zero(c_strlcat_dst2, 20);
	//
	print_errors_size("ft_strlcat",	ft_strlcat_value2,	c_strlcat_value2);
	print_errors_string("ft_strlcat",	ft_strlcat_dst2,	c_strlcat_dst2);
	/////////3
	char ft_strlcat_src3[7] = "WORLD";
	char ft_strlcat_dst3[20] = "HELLOOO";
	size_t ft_strlcat_value3 = 0;
	// printf("ft_strlcat_dst3 (before) : %s\n", ft_strlcat_dst3);
	ft_strlcat_value3 = ft_strlcat(ft_strlcat_dst1, ft_strlcat_src3, 5);
	// printf("ft_strlcat_dst3 (after) : %s\n", ft_strlcat_dst3);
	// printf("Return value = %zu\n", ft_strlcat_value3);
	//
	char c_strlcat_src3[7] = "WORLD";
	char c_strlcat_dst3[20] = "HELLOOO";
	size_t c_strlcat_value3 = 0;
	// printf("c_strlcat_dst1 (before): %s\n", c_strlcat_dst3);
	c_strlcat_value3 = strlcat(c_strlcat_dst3, c_strlcat_src3, 5);
	// printf("c_strlcat_dst3 (after): %s\n", c_strlcat_dst3);
	// printf("Return value = %zu\n", c_strlcat_value3);
	//
	// focus_on_backslash_zero(ft_strlcat_dst3, 20);
	// focus_on_backslash_zero(c_strlcat_dst3, 20);
	//
	print_errors_size("ft_strlcat",	ft_strlcat_value3,	c_strlcat_value3);
	print_errors_string("ft_strlcat",	ft_strlcat_dst3,	c_strlcat_dst3);
	/////////4
	char ft_strlcat_src4[7] = "WORLD";
	char ft_strlcat_dst4[20] = "HELLOOO";
	size_t ft_strlcat_value4 = 0;
	// printf("ft_strlcat_dst4 (before) : %s\n", ft_strlcat_dst4);
	ft_strlcat_value4 = ft_strlcat(ft_strlcat_dst4, ft_strlcat_src4, 10);
	// printf("ft_strlcat_dst4 (after) : %s\n", ft_strlcat_dst4);
	// printf("Return value = %zu\n", ft_strlcat_value4);
	//
	char c_strlcat_src4[7] = "WORLD";
	char c_strlcat_dst4[20] = "HELLOOO";
	size_t c_strlcat_value4 = 0;
	// printf("c_strlcat_dst4 (before): %s\n", c_strlcat_dst4);
	c_strlcat_value4 = strlcat(c_strlcat_dst4, c_strlcat_src4, 10);
	// printf("c_strlcat_dst4 (after): %s\n", c_strlcat_dst4);
	// printf("Return value = %zu\n", c_strlcat_value4);
	//
	// focus_on_backslash_zero(ft_strlcat_dst4, 20);
	// focus_on_backslash_zero(c_strlcat_dst4, 20);
	//
	print_errors_size("ft_strlcat",	ft_strlcat_value4,	c_strlcat_value4);
	print_errors_string("ft_strlcat",	ft_strlcat_dst4,	c_strlcat_dst4);
	/////////5
	char ft_strlcat_src5[7] = "WORLD";
	char ft_strlcat_dst5[20] = "HELLOOO";
	size_t ft_strlcat_value5 = 0;
	// printf("ft_strlcat_dst5 (before) : %s\n", ft_strlcat_dst5);
	ft_strlcat_value5 = ft_strlcat(ft_strlcat_dst5, ft_strlcat_src5, 15);
	// printf("ft_strlcat_dst5 (after) : %s\n", ft_strlcat_dst5);
	// printf("Return value = %zu\n", ft_strlcat_value5);
	//
	char c_strlcat_src5[7] = "WORLD";
	char c_strlcat_dst5[20] = "HELLOOO";
	size_t c_strlcat_value5 = 0;
	// printf("c_strlcat_dst5 (before): %s\n", c_strlcat_dst5);
	c_strlcat_value5 = strlcat(c_strlcat_dst5, c_strlcat_src5, 15);
	// printf("c_strlcat_dst5 (after): %s\n", c_strlcat_dst5);
	// printf("Return value = %zu\n", c_strlcat_value5);
	//
	// focus_on_backslash_zero(ft_strlcat_dst5, 20);
	// focus_on_backslash_zero(c_strlcat_dst5, 20);
	//
	print_errors_size("ft_strlcat",	ft_strlcat_value5,	c_strlcat_value5);
	print_errors_string("ft_strlcat",	ft_strlcat_dst5,	c_strlcat_dst5);
	/////////6
	char ft_strlcat_src6[50] = "Jerry";
	char ft_strlcat_dst6[50] = "Tom AND ";
	size_t ft_strlcat_value6 = 0;
	// printf("ft_strlcat_dst6 (before) : %s\n", ft_strlcat_dst6);
	ft_strlcat_value6 = ft_strlcat(ft_strlcat_dst6, ft_strlcat_src6, 30);
	// printf("ft_strlcat_dst6 (after) : %s\n", ft_strlcat_dst6);
	// printf("Return value = %zu\n", ft_strlcat_value6);
	//
	char c_strlcat_src6[50] = "Jerry";
	char c_strlcat_dst6[50] = "Tom AND ";
	size_t c_strlcat_value6 = 0;
	// printf("c_strlcat_dst6 (before): %s\n", c_strlcat_dst6);
	c_strlcat_value6 = strlcat(c_strlcat_dst6, c_strlcat_src6, 30);
	// printf("c_strlcat_dst6 (after): %s\n", c_strlcat_dst6);
	// printf("Return value = %zu\n", c_strlcat_value6);
	//
	// focus_on_backslash_zero(ft_strlcat_dst6, 20);
	// focus_on_backslash_zero(c_strlcat_dst6, 20);
	//
	print_errors_size("ft_strlcat",	ft_strlcat_value6,	c_strlcat_value6);
	print_errors_string("ft_strlcat",	ft_strlcat_dst6,	c_strlcat_dst6);
	/////////7
	char ft_strlcat_src7[50] = "";
	char ft_strlcat_dst7[50] = "Tom AND ";
	size_t ft_strlcat_value7 = 0;
	ft_strlcat_value7 = ft_strlcat(ft_strlcat_dst7, ft_strlcat_src7, 30);
	char c_strlcat_src7[50] = "";
	char c_strlcat_dst7[50] = "Tom AND ";
	size_t c_strlcat_value7 = 0;
	c_strlcat_value7 = strlcat(c_strlcat_dst7, c_strlcat_src7, 30);
	print_errors_size("ft_strlcat",	ft_strlcat_value7,	c_strlcat_value7);
	print_errors_string("ft_strlcat",	ft_strlcat_dst7,	c_strlcat_dst7);
	/////////8
	char ft_strlcat_src8[50] = "Jerry";
	char ft_strlcat_dst8[50] = "";
	size_t ft_strlcat_value8 = 0;
	ft_strlcat_value8 = ft_strlcat(ft_strlcat_dst8, ft_strlcat_src8, 30);
	char c_strlcat_src8[50] = "Jerry";
	char c_strlcat_dst8[50] = "";
	size_t c_strlcat_value8 = 0;
	c_strlcat_value8 = strlcat(c_strlcat_dst8, c_strlcat_src8, 30);
	print_errors_size("ft_strlcat",	ft_strlcat_value8,	c_strlcat_value8);
	print_errors_string("ft_strlcat",	ft_strlcat_dst8,	c_strlcat_dst8);
	/////////9
	char ft_strlcat_src9[50] = "";
	char ft_strlcat_dst9[50] = "";
	size_t ft_strlcat_value9 = 0;
	ft_strlcat_value9 = ft_strlcat(ft_strlcat_dst9, ft_strlcat_src9, 30);
	char c_strlcat_src9[50] = "";
	char c_strlcat_dst9[50] = "";
	size_t c_strlcat_value9 = 0;
	c_strlcat_value9 = strlcat(c_strlcat_dst9, c_strlcat_src9, 30);
	print_errors_size("ft_strlcat",	ft_strlcat_value9,	c_strlcat_value9);
	print_errors_string("ft_strlcat",	ft_strlcat_dst9,	c_strlcat_dst9);

	//////////////////////////////////////////////////////////////////

	// ft_strchr
	char abc[4] = "abc\0";
	print_errors_pointer("ft_strchr",	ft_strchr(abc, 'a'),	strchr(abc, 'a'));
	print_errors_pointer("ft_strchr",	ft_strchr(abc, 'b'),	strchr(abc, 'b'));
	print_errors_pointer("ft_strchr",	ft_strchr(abc, 'c'),	strchr(abc, 'c'));
	print_errors_pointer("ft_strchr",	ft_strchr(abc, 0),		strchr(abc, 0));
	//
	char phrase[50] = "J'aime le tofu bien grillé.\n\0";
	print_errors_pointer("ft_strchr",	ft_strchr(phrase, '.'),	strchr(phrase, '.'));
	print_errors_pointer("ft_strchr",	ft_strchr(phrase, 'e'),	strchr(phrase, 'e'));
	print_errors_pointer("ft_strchr",	ft_strchr(phrase, ' '),	strchr(phrase, ' '));
	print_errors_pointer("ft_strchr",	ft_strchr(phrase, '\n'),	strchr(phrase, '\n'));
	print_errors_pointer("ft_strchr",	ft_strchr(phrase, 'w'),	strchr(phrase, 'w'));
	print_errors_pointer("ft_strchr",	ft_strchr(phrase, 0),		strchr(phrase, 0));
	//
	// char *ptr;
	// char abc[4] = "abc\0";
	// printf("Ptr : %p\n", abc);
	// ptr = ft_strchr(abc, 0);
	// printf("Ptr : %p\n", ptr);

	// ft_strrchr
	char strrchr1[50] = "J'aime le tofu bien grillé.\n\0";
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr1, '.'),	strrchr(strrchr1, '.'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr1, 'e'),	strrchr(strrchr1, 'e'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr1, ' '),	strrchr(strrchr1, ' '));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr1, '\n'),	strrchr(strrchr1, '\n'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr1, 'w'),	strrchr(strrchr1, 'w'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr1, 0),	strrchr(strrchr1, 0));
	//
	char strrchr2[50] = "J'aime le tofu\0 bien grillé.\n\0";
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr2, '.'),	strrchr(strrchr2, '.'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr2, 'e'),	strrchr(strrchr2, 'e'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr2, ' '),	strrchr(strrchr2, ' '));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr2, '\n'),	strrchr(strrchr2, '\n'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr2, 'w'),	strrchr(strrchr2, 'w'));
	print_errors_pointer("ft_strrchr",	ft_strrchr(strrchr2, 0),	strrchr(strrchr2, 0));
	//
	// char *ptr;
	// char strrchr1[20] = "abcdefgh\0ijk";
	// printf("Ptr : %p\n", strrchr1);
	// ptr = ft_strrchr(strrchr1, 'g');
	// printf("Ptr : %p\n", ptr);

	// ft_strncmp
	char strncmp1[50] = "J'aime le tofu\0";
	char strncmp2[50] = "J'aime le poulet\0";
	print_errors("ft_strncmp",	ft_strncmp(strncmp1, strncmp2, 50),	strncmp(strncmp1, strncmp2, 50));
	print_errors("ft_strncmp",	ft_strncmp(strncmp1, strncmp2, 0),	strncmp(strncmp1, strncmp2, 0));
	
	char strncmp3[50] = "J'ai\0me le tofu\0";
	char strncmp4[50] = "J'aime le poulet\0";
	ft_strncmp(strncmp3, strncmp4, 50);
	print_errors("ft_strncmp",	ft_strncmp(strncmp3, strncmp4, 50),	strncmp(strncmp3, strncmp4, 50));
	print_errors("ft_strncmp",	ft_strncmp(strncmp3, strncmp4, 10),	strncmp(strncmp3, strncmp4, 10));

	char strncmp5[50] = "J'aime le tofu\0";
	char strncmp6[50] = "J'aimais le poulet\0";
	print_errors("ft_strncmp",	ft_strncmp(strncmp5, strncmp6, 50),	strncmp(strncmp5, strncmp6, 50));
	print_errors("ft_strncmp",	ft_strncmp(strncmp5, strncmp6, 10),	strncmp(strncmp5, strncmp6, 10));

	char strncmp7[50] = "1234567890";
	char strncmp8[50] = "1234567890";
	print_errors("ft_strncmp",	ft_strncmp(strncmp7, strncmp8, 50),	strncmp(strncmp7, strncmp8, 50));

	char strncmp9[50] = "123467890";
	char strncmp10[50] = "1234567890";
	print_errors("ft_strncmp",	ft_strncmp(strncmp9, strncmp10, 50),	strncmp(strncmp9, strncmp10, 50));

	char strncmp11[50] = "?123467890";
	char strncmp12[50] = "1234567890";
	print_errors("ft_strncmp",	ft_strncmp(strncmp11, strncmp12, 50),	strncmp(strncmp11, strncmp12, 50));

	char strncmp13[50] = "1234567890";
	char strncmp14[50] = "1234567890?";
	print_errors("ft_strncmp",	ft_strncmp(strncmp13, strncmp14, 50),	strncmp(strncmp13, strncmp14, 50));

	char strncmp15[50] = "1234\0 567890";
	char strncmp16[50] = "1234\0 567890?";
	print_errors("ft_memcmp",	ft_strncmp(strncmp15, strncmp16, 50),	strncmp(strncmp15, strncmp16, 50));

	// char strncmp1[50] = "J'aime le tofu\0";
	// char strncmp2[50] = "J'aime le poulet\0";
	// ft_strncmp(strncmp1, strncmp2, 40);		// i = 10   | cmp = 4
	// printf("strncmp : %d\n", strncmp(strncmp1, strncmp2, 40));

	// ft_memchr
	char memchr1[12] = "memchr1\0";
	print_errors_pointer("ft_memchr",	ft_memchr(memchr1, 'a', 12),	memchr(memchr1, 'a', 12));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr1, 'b', 12),	memchr(memchr1, 'b', 12));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr1, 'c', 12),	memchr(memchr1, 'c', 12));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr1, 0, 12),		memchr(memchr1, 0, 12));
	//
	char memchr3[12] = "mem\0chr1\0";
	print_errors_pointer("ft_memchr",	ft_memchr(memchr3, 'a', 12),	memchr(memchr3, 'a', 12));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr3, 'b', 12),	memchr(memchr3, 'b', 12));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr3, 'c', 12),	memchr(memchr3, 'c', 12));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr3, 0, 12),		memchr(memchr3, 0, 12));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr3, 0, 150),		memchr(memchr3, 0, 150));
	// //
	char memchr2[50] = "J'aime le tofu bien grillé.\n\0";
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '.', 50),		memchr(memchr2, '.', 50));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'e', 50),		memchr(memchr2, 'e', 50));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, ' ', 50),		memchr(memchr2, ' ', 50));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '\n', 50),		memchr(memchr2, '\n', 50));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'w', 50),		memchr(memchr2, 'w', 50));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 0, 50),			memchr(memchr2, 0, 50));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '.', 10),		memchr(memchr2, '.', 10));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'e', 10),		memchr(memchr2, 'e', 10));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, ' ', 10),		memchr(memchr2, ' ', 10));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '\n', 10),		memchr(memchr2, '\n', 10));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'w', 10),		memchr(memchr2, 'w', 10));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 0, 10),			memchr(memchr2, 0, 10));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '.', 5),		memchr(memchr2, '.', 5));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'e', 5),		memchr(memchr2, 'e', 5));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, ' ', 5),		memchr(memchr2, ' ', 5));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '\n', 5),		memchr(memchr2, '\n', 5));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'w', 5),		memchr(memchr2, 'w', 5));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 0, 5),			memchr(memchr2, 0, 5));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '.', 1),		memchr(memchr2, '.', 1));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'e', 1),		memchr(memchr2, 'e', 1));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, ' ', 1),		memchr(memchr2, ' ', 1));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, '\n', 0),		memchr(memchr2, '\n', 0));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 'w', 0),		memchr(memchr2, 'w', 0));
	print_errors_pointer("ft_memchr",	ft_memchr(memchr2, 0, 0),			memchr(memchr2, 0, 0));
	//
	// char *ptr;
	// char memchr3[10] = "memchr3\0";
	// printf("Ptr : %p\n", memchr3);
	// ptr = ft_memchr(memchr3, 'c', 1);
	// printf("Ptr : %p\n", ptr);

	// ft_memcmp
	char memcmp1[50] = "J'aime le tofu\0";
	char memcmp2[50] = "J'aime le poulet\0";
	print_errors("ft_memcmp",	ft_memcmp(memcmp1, memcmp2, 50),	memcmp(memcmp1, memcmp2, 50));
	print_errors("ft_memcmp",	ft_memcmp(memcmp1, memcmp2, 0),	memcmp(memcmp1, memcmp2, 0));
	
	char memcmp3[50] = "J'ai\0me le tofu\0";
	char memcmp4[50] = "J'aime le poulet\0";
	ft_memcmp(memcmp3, memcmp4, 50);
	print_errors("ft_memcmp",	ft_memcmp(memcmp3, memcmp4, 50),	memcmp(memcmp3, memcmp4, 50));
	print_errors("ft_memcmp",	ft_memcmp(memcmp3, memcmp4, 10),	memcmp(memcmp3, memcmp4, 10));

	char memcmp5[50] = "J'aime le tofu\0";
	char memcmp6[50] = "J'aimais le poulet\0";
	print_errors("ft_memcmp",	ft_memcmp(memcmp5, memcmp6, 50),	memcmp(memcmp5, memcmp6, 50));
	print_errors("ft_memcmp",	ft_memcmp(memcmp5, memcmp6, 10),	memcmp(memcmp5, memcmp6, 10));

	char memcmp7[5] = "123\0\0";		//ERROR
	char memcmp8[5] = "123\0\0";		//ERROR
	print_errors("ft_memcmp",	ft_memcmp(memcmp7, memcmp8, 5),	memcmp(memcmp7, memcmp8, 5));

	char memcmp9[50] = "123467890";
	char memcmp10[50] = "1234567890";
	print_errors("ft_memcmp",	ft_memcmp(memcmp9, memcmp10, 50),	memcmp(memcmp9, memcmp10, 50));

	char memcmp11[50] = "?123467890";
	char memcmp12[50] = "1234567890";
	print_errors("ft_memcmp",	ft_memcmp(memcmp11, memcmp12, 50),	memcmp(memcmp11, memcmp12, 50));

	char memcmp13[50] = "1234567890";
	char memcmp14[50] = "1234567890?";
	print_errors("ft_memcmp",	ft_memcmp(memcmp13, memcmp14, 50),	memcmp(memcmp13, memcmp14, 50));

	char memcmp15[50] = "1234\0 567890";
	char memcmp16[50] = "1234\0 567890?";
	print_errors("ft_memcmp",	ft_memcmp(memcmp15, memcmp16, 50),	memcmp(memcmp15, memcmp16, 50));

	// char memcmp1[50] = "J'aime le tofu\0";
	// char memcmp2[50] = "J'aime le poulet\0";
	// printf("ft_memcmp : %d\n", ft_memcmp(memcmp1, memcmp2, 40));		// i = 10   | cmp = 4
	// printf("memcmp : %d\n", memcmp(memcmp1, memcmp2, 40));

	// ft_strnstr
	char 	haystack[50] = "Une chaine pas comme les autres";
	char 	needle[50] = "comme";
	size_t	len1 = 50;
	size_t	len2 = 5;
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack, needle, len1), strnstr(haystack, needle, len1));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack, needle, len2), strnstr(haystack, needle, len2));
	//
	char 	haystack11[50] = "Salut";
	char 	haystack12[50] = "Saluuuuuuuuut";
	char 	haystack13[50] = "Saluu\0uuuuuuut";
	char 	haystack14[50] = "";
	char 	needle11[50] = "s";
	char 	needle12[50] = "t";
	char 	needle13[50] = "";
	char 	needle14[50] = "2";
	size_t	len11 = 50;
	size_t	len12 = 5;
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack11, needle11, len11), strnstr(haystack11, needle11, len11));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack11, needle11, len12), strnstr(haystack11, needle11, len12));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack11, needle12, len11), strnstr(haystack11, needle12, len11));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack12, needle12, len11), strnstr(haystack12, needle12, len11));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack12, needle12, len12), strnstr(haystack12, needle12, len12));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack13, needle12, len11), strnstr(haystack13, needle12, len11));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack13, needle13, len11), strnstr(haystack13, needle13, len11));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack13, needle14, len11), strnstr(haystack13, needle14, len11));
	print_errors_pointer("ft_strnstr", ft_strnstr(haystack14, needle12, len11), strnstr(haystack14, needle12, len11));
	//
	// char 	haystack[50] = "Une chaine pas comme les autres";
	// char 	needle[50] = "comme";
	// size_t	len = 50;
	// // printf("haystack[0] : 	%p\n", haystack);
	// // printf("haystack[13] : 	%p\n\n", &haystack[15]);
	// // printf("needle : %p\n", needle[0]);
	// printf("ft_strnstr : 	%p\nc_strnstr : 	%p\n", ft_strnstr(haystack, needle, len), strnstr(haystack, needle, len));

	//////////////////////////////////////////////////////////////////

	// ft_atoi
	print_errors("ft_atoi", 	ft_atoi("abc123"), 			atoi("abc123"));
	print_errors("ft_atoi", 	ft_atoi("123abc"), 			atoi("123abc"));
	print_errors("ft_atoi", 	ft_atoi("    abc123"), 		atoi("    abc123"));
	print_errors("ft_atoi", 	ft_atoi("    123abc"), 		atoi("    123abc"));
	print_errors("ft_atoi", 	ft_atoi("    +123abc"), 	atoi("    +123abc"));
	print_errors("ft_atoi", 	ft_atoi("    -123abc"), 	atoi("    -123abc"));
	print_errors("ft_atoi", 	ft_atoi("    --123abc"), 	atoi("    --123abc"));
	print_errors("ft_atoi", 	ft_atoi("    ++123abc"), 	atoi("    ++123abc"));
	print_errors("ft_atoi", 	ft_atoi("0"), 				atoi("0"));
	print_errors("ft_atoi", 	ft_atoi("1"), 				atoi("1"));
	print_errors("ft_atoi", 	ft_atoi("-0"), 				atoi("-0"));
	print_errors("ft_atoi", 	ft_atoi("-1"), 				atoi("-1"));
	print_errors("ft_atoi", 	ft_atoi("       100"), 		atoi("       100"));
	print_errors("ft_atoi", 	ft_atoi("       -100"), 	atoi("       -100"));
	print_errors("ft_atoi", 	ft_atoi("\0 100"), 			atoi("\0 100"));
	print_errors("ft_atoi", 	ft_atoi("100\0"), 			atoi("100\0"));
	print_errors("ft_atoi", 	ft_atoi("2147483647"), 		atoi("2147483647"));
	print_errors("ft_atoi", 	ft_atoi("2147483648"), 		atoi("2147483648"));
	print_errors("ft_atoi", 	ft_atoi("-2147483648"), 	atoi("-2147483648"));
	print_errors("ft_atoi", 	ft_atoi("-2147483649"), 	atoi("-2147483649"));
	// int ft_atoi_int1;
	// int atoi_int1;
	// ft_atoi_int1 = ft_atoi("    2147483648");		// ==> 0
	// atoi_int1 = atoi("    2147483648");		// ==> -123
	// printf("%d\n", ft_atoi_int1);
	// printf("%d\n", atoi_int1);
	// // atoi("2147483647");	// ==> 2147483647
	// // atoi("2147483648");	// ==> -2147483648 (overflow)
	// // atoi("-2147483648");	// ==> -2147483648
	// // atoi("-2147483649");	// ==> 2147483647 (overflow)

	//////////////////////////////////////////////////////////////////

	// ft_strdup
	char ft_strdup1[50]="FT string to duplicate\0";
	char c_strdup1[50]="FT string to duplicate\0";
	print_errors_string("ft_strdup", ft_strdup(ft_strdup1), strdup(c_strdup1));
	print_errors_string("ft_strdup", ft_strdup("Phrase test"), strdup("Phrase test"));
	print_errors_string("ft_strdup", ft_strdup("Phrase\0 test"), strdup("Phrase\0 test"));
	print_errors_string("ft_strdup", ft_strdup(""), strdup(""));
	print_errors_string("ft_strdup", ft_strdup("\n\n\n\n\n\0\n\n\n\n"), strdup("\n\n\n\n\n\0\n\n\n\n"));
	//
	// char ft_str_to_dup[50]="FT string to duplicate\0";
	// char c_str_to_dup[50]="FT string to duplicate\0";
	// char *ft_str_duplicated;
	// char *c_str_duplicated;
	// ft_str_duplicated = ft_strdup(ft_str_to_dup);
	// c_str_duplicated = strdup(c_str_to_dup);
	// // printf("%s\n", ft_str_duplicated);
	// // printf("%s\n", c_str_duplicated);
	// // focus_on_backslash_zero(ft_str_duplicated, 23);
	// // focus_on_backslash_zero(c_str_duplicated, 23);

	// ft_calloc
	// TESTS POUR FT_CALLOC 
	// 1. comparer pointeur en position [0]
	// 2. comparer pour (count*size)x pointeur en position [count*size]
	int	int_size = sizeof(int);
	int char_size = sizeof(char);

	int zero = 0;
	int one = 1;
	int four = 4;
	int ten = 10;
	int hundred = 100;
	
	int *calloc1;
	int *ft_calloc1;
	int i = -1;
	calloc1 = calloc(one, four * int_size);
	ft_calloc1 = ft_calloc(one, four * int_size);
	print_errors_int_calloc("ft_calloc", ft_calloc1, calloc1);
	while(++i < (one * four))
		print_errors_int_calloc("ft_calloc", &ft_calloc1[i], &calloc1[i]);

	char *calloc2;
	char *ft_calloc2;
	int j = -1;
	calloc2 = calloc(one, four * char_size);
	ft_calloc2 = ft_calloc(one, four * char_size);
	print_errors_char_calloc("ft_calloc", ft_calloc2, calloc2);
	while(++j < (one * four))
		print_errors_char_calloc("ft_calloc", &ft_calloc2[j], &calloc2[j]);

	int *calloc3;
	int *ft_calloc3;
	int k = -1;
	calloc3 = calloc(one, zero * int_size);
	ft_calloc3 = ft_calloc(one, zero * int_size);
	print_errors_int_calloc("ft_calloc", ft_calloc3, calloc3);
	while(++k < (one * zero))
		print_errors_int_calloc("ft_calloc", &ft_calloc3[k], &calloc3[k]);
	

	int *calloc5;
	int *ft_calloc5;
	int m = -1;
	calloc5 = calloc(four, hundred * int_size);
	ft_calloc5 = ft_calloc(four, hundred * int_size);
	print_errors_int_calloc("ft_calloc", ft_calloc5, calloc5);
	while(++m < (four * hundred))
		print_errors_int_calloc("ft_calloc", &ft_calloc5[m], &calloc5[m]);

	char *calloc6;
	char *ft_calloc6;
	int n = -1;
	calloc6 = calloc(ten, hundred * char_size);
	ft_calloc6 = ft_calloc(ten, hundred * char_size);
	print_errors_char_calloc("ft_calloc", ft_calloc6, calloc6);
	while(++n < (ten * hundred))
		print_errors_char_calloc("ft_calloc", &ft_calloc6[n], &calloc6[n]);

	// int *calloc1;
	// calloc1 = (int *)calloc(2, 2 * sizeof(int));
	// int *calloc2;
	// calloc2 = (int *)ft_calloc(2, 2 * sizeof(int));
	// calloc1[3] = 10;
	// int j = -1;
	// printf("Calloc (int) :\n");
	// while (++j < 4)
	// 	printf("calloc1[%d] : %d (%p)\n", j , calloc1[j], &calloc1[j]);
	// calloc2[3] = 47;
	// int i = -1;
	// printf("\nFT_calloc (int) :\n");
	// while (++i < 4)
	// 	printf("calloc2[%d] : %d (%p)\n", i , calloc2[i], &calloc2[i]);
	// //
	// //
	// char *calloc3;
	// calloc3 = calloc(2, 2 * sizeof(char));
	// char *calloc4;
	// calloc4 = ft_calloc(2, 2 * sizeof(char));
	// calloc3[3] = 'a';
	// int k = -1;
	// printf("\nCalloc (char) :\n");
	// while (++k < 4)
	// 	printf("calloc3[%d] : %c (%p)\n", k , calloc3[k], &calloc3[k]);
	// calloc4[3] = 'z';
	// int l = -1;
	// printf("\nFT_calloc (char) :\n");
	// while (++l < 4)
	// 	printf("calloc4[%d] : %c (%p)\n", l , calloc4[l], &calloc4[l]);

	// ft_substr
	char *substr1 = "Phrase\0 une.\0";
	char *ft_substr1;
	unsigned int substr_start1 = 3;
	size_t substr_len1 = 3;
	ft_substr1 = ft_substr(substr1, substr_start1, substr_len1);
	substr_test("ft_substr", ft_substr1, substr1, substr_start1, substr_len1);
	
	char *substr2 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\0";
	char *ft_substr2;
	unsigned int substr_start2 = 0;
	size_t substr_len2 = 10;
	ft_substr2 = ft_substr(substr2, substr_start2, substr_len2);
	substr_test("ft_substr", ft_substr2, substr2, substr_start2, substr_len2);

	char *substr3 = "";
	char *ft_substr3;
	unsigned int substr_start3 = 0;
	size_t substr_len3 = 10;
	ft_substr3 = ft_substr(substr3, substr_start3, substr_len3);
	substr_test("ft_substr", ft_substr3, substr3, substr_start3, substr_len3);

	char *substr4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\0";
	char *ft_substr4;
	unsigned int substr_start4 = 0;
	size_t substr_len4 = 0;
	ft_substr4 = ft_substr(substr4, substr_start4, substr_len4);
	substr_test("ft_substr", ft_substr4, substr4, substr_start4, substr_len4);

	char *substr5 = "Phrase une.\0";
	char *ft_substr5;
	unsigned int substr_start5 = 11;
	size_t substr_len5 = 0;
	ft_substr5 = ft_substr(substr5, substr_start5, substr_len5);
	substr_test("ft_substr", ft_substr5, substr5, substr_start5, substr_len5);

	char *substr6 = "Phrase une.\0";
	char *ft_substr6;
	unsigned int substr_start6 = 11;
	size_t substr_len6 = 5;
	ft_substr6 = ft_substr(substr6, substr_start6, substr_len6);
	substr_test("ft_substr", ft_substr6, substr6, substr_start6, substr_len6);

	// ft_strjoin
	char *join1 = "Il était une fois\0";
	char *join2 = " un jeune louvetau.\0";
	char *strjoin1 = "Il était une fois un jeune louvetau.\0";
	char *strjoin2;
	strjoin2 = ft_strjoin(join1, join2);
	strjoin_test("ft_strlcat",	strjoin1,	strjoin2);

	char *join3 = "        \n bla bla bla ... \0  bla bla bla ... ";
	char *join4 = " bli bli bli bli bli bli \t blo blo ...\0";
	char *strjoin3 = "        \n bla bla bla ...  bli bli bli bli bli bli \t blo blo ...\0";
	char *strjoin4;
	strjoin4 = ft_strjoin(join3, join4);
	strjoin_test("ft_strlcat",	strjoin3,	strjoin4);

	char *join5 = "\0";
	char *join6 = " un jeune louvetau.\0";
	char *strjoin5 = " un jeune louvetau.\0";
	char *strjoin6;
	strjoin6 = ft_strjoin(join5, join6);
	strjoin_test("ft_strlcat",	strjoin5,	strjoin6);

	char *join7 = "Il était une fois\0";
	char *join8 = "\0";
	char *strjoin7 = "Il était une fois\0";
	char *strjoin8;
	strjoin8 = ft_strjoin(join7, join8);
	strjoin_test("ft_strlcat",	strjoin7,	strjoin8);
	//////////////////////////////////////////////////////////////////

	// ft_strtrim
	char *strtrim1 = "___Une_chaine_comme_ça_____\0";
	char *set1 = ",;_\0";
	char *strtrimed;
	strtrimed = ft_strtrim(strtrim1, set1);
	printf("\n%s\n", strtrimed);
	// focus_on_backslash_zero(strtrimed, 25);
	//
	char *strtrim2 = "        ........,,,{{{{{{{[[[[[[[[((((((((   ...  Il était une fois ...   ))))))))]]]]]]]]}}}}}},,,........          \0";
	char *set2 = " .,()[]{}\0";
	char *strtrimed2;
	strtrimed2 = ft_strtrim(strtrim2, set2);
	printf("\n%s\n", strtrimed2);

	// ft_split
	char *s1 = "_Une__petite_chaineeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee____de_caracteres.\0";
	char c1 = '_';
	char **words;
	words = ft_split(s1, c1);
	// Expected words :
	char *word_1_1 = "Une";
	char *word_1_2 = "petite";
	char *word_1_3 = "chaineeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	char *word_1_4 = "de";
	char *word_1_5 = "caracteres.";
	// Tests :
	print_errors_string("ft_split", ft_split(s1, c1)[0], word_1_1);
	print_errors_string("ft_split", ft_split(s1, c1)[1], word_1_2);
	print_errors_string("ft_split", ft_split(s1, c1)[2], word_1_3);
	print_errors_string("ft_split", ft_split(s1, c1)[3], word_1_4);
	print_errors_string("ft_split", ft_split(s1, c1)[4], word_1_5);
	//
	//
	char *s2 = "     salut       les   copines    \0 Vous allez bien ?\0";
	char c2 = ' ';
	char **words2;
	words2 = ft_split(s2, c2);
	// Expected words :
	char *word_2_1 = "salut";
	char *word_2_2 = "les";
	char *word_2_3 = "copines";
	// Tests :
	print_errors_string("ft_split", ft_split(s2, c2)[0], word_2_1);
	print_errors_string("ft_split", ft_split(s2, c2)[1], word_2_2);
	print_errors_string("ft_split", ft_split(s2, c2)[2], word_2_3);
	//
	//
	char *s3 = "_Une__petite_chaineeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee____de_caracteres.\0";
	char c3 = 0;
	char **words3;
	words3 = ft_split(s3, c3);
	// Expected words :
	char *word_3_1 = "_Une__petite_chaineeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee____de_caracteres.";
	// Tests :
	print_errors_string("ft_split", ft_split(s3, c3)[0], word_3_1);
	//
	//
	char *s4 = 0;
	char c4 = ' ';
	// char c4 = 0;
	char **words4;
	words4 = ft_split(s4, c4);
	// Tests :
	test_index++;
	if(words4 != NULL)
	{
		red_color();
		printf("ERROR (test n.%d) in function \"ft_split\"\n", test_index);
		defaut_color();
		printf("ft_function : %p | Expected :  %s\n\n", words4, NULL);
		error_count++;
		return(1);
	}
	//
	//
	char *s5 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\0";
	char c5 = ' ';
	char c6 = 'e';
	char **words5;
	char **words6;
	words5 = ft_split(s5, c5);
	words6 = ft_split(s5, c6);


	int words5_count = 0;
	int words5_i = -1;
	while(words5[++words5_i] != NULL)
		words5_count++;
	// printf("words5_count : %d\n", words5_count);
	// printf("words5[137] : %s\n", words5[137]);
	// printf("words5[138] : %s\n", words5[138]);
	print_errors_string("ft_split", words5[0], "Lorem");
	print_errors_string("ft_split", words5[137], "laborum.");

	int words6_count = 0;
	int words6_i = -1;
	while(words6[++words6_i] != NULL)
		words6_count++;
	// printf("words6_count : %d\n", words6_count);
	// printf("words6[74] : %s\n", words6[74]);
	// printf("words6[75] : %s\n", words6[75]);
	print_errors_string("ft_split", words6[0], "Lor");
	print_errors_string("ft_split", words6[74], "st laborum.");

	// ft_itoa 
	int number1 = 0;
	print_errors_string("ft_itoa", ft_itoa(number1), "0");
	int number2 = -0;
	print_errors_string("ft_itoa", ft_itoa(number2), "0");
	int number3 = 1;
	print_errors_string("ft_itoa", ft_itoa(number3), "1");
	int number4 = -1;
	print_errors_string("ft_itoa", ft_itoa(number4), "-1");
	int number5 = 2147483647;
	print_errors_string("ft_itoa", ft_itoa(number5), "2147483647");
	int number6 = -2147483647;
	print_errors_string("ft_itoa", ft_itoa(number6), "-2147483647");
	int number7 = -2147483648;
	print_errors_string("ft_itoa", ft_itoa(number7), "-2147483648");
	// printf("%s\n", ft_itoa(number7));

	//////////////////////////////////////////////////////////////////

	// Total of errors in tests
	error_count > 0 ? red_color() : green_color();
	printf("%d errors in tests.\n", error_count);
	defaut_color();
	return (0);
}
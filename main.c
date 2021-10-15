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
		printf("ft_function : %d\nC_function :  %d\n\n", ft_function, c_function);
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
		printf("ft_function : %s\nC_function :  %s\n\n", ft_str, c_str);
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
		printf("ft_function : %zu\nC_function :  %zu\n\n", ft_str, c_str);
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
	char ft_strlcat_src6[50] = "Tom AND ";
	char ft_strlcat_dst6[50] = "Jerry";
	size_t ft_strlcat_value6 = 0;
	// printf("ft_strlcat_dst6 (before) : %s\n", ft_strlcat_dst6);
	ft_strlcat_value6 = ft_strlcat(ft_strlcat_dst6, ft_strlcat_src6, 30);
	// printf("ft_strlcat_dst6 (after) : %s\n", ft_strlcat_dst6);
	// printf("Return value = %zu\n", ft_strlcat_value6);
	//
	char c_strlcat_src6[50] = "Tom AND ";
	char c_strlcat_dst6[50] = "Jerry";
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
	char ft_strlcat_src7[50] = "Tom AND ";
	char ft_strlcat_dst7[50] = "";
	size_t ft_strlcat_value7 = 0;
	ft_strlcat_value7 = ft_strlcat(ft_strlcat_dst7, ft_strlcat_src7, 30);
	char c_strlcat_src7[50] = "Tom AND ";
	char c_strlcat_dst7[50] = "";
	size_t c_strlcat_value7 = 0;
	c_strlcat_value7 = strlcat(c_strlcat_dst7, c_strlcat_src7, 30);
	print_errors_size("ft_strlcat",	ft_strlcat_value7,	c_strlcat_value7);
	print_errors_string("ft_strlcat",	ft_strlcat_dst7,	c_strlcat_dst7);
	/////////8
	char ft_strlcat_src8[50] = "";
	char ft_strlcat_dst8[50] = "Jerry";
	size_t ft_strlcat_value8 = 0;
	ft_strlcat_value8 = ft_strlcat(ft_strlcat_dst8, ft_strlcat_src8, 30);
	char c_strlcat_src8[50] = "";
	char c_strlcat_dst8[50] = "Jerry";
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

	// Total of errors in tests
	error_count > 0 ? red_color() : green_color();
	printf("%d errors in tests.\n", error_count);
	defaut_color();
	return (0);
}
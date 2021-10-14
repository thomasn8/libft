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
	char src[40] = "Hello World ! Je suis ton père";
	char ft_dest[40] = {0};
	char dest[40] = {0};
	ft_memcpy(ft_dest, src, 5);	
	memcpy(dest, src, 5);
	print_errors_string("ft_memcpy",		ft_dest,		dest);
	//
	char src2[40] = "Le jour se lève";
	char ft_dest2[40] = {0};
	char dest2[40] = {0};
	ft_memcpy(ft_dest2, src2, 0);	
	memcpy(dest2, src2, 0);
	print_errors_string("ft_memcpy",		ft_dest2,		dest2);
	//
	char src3[40] = "Le jour se lève";
	char ft_dest3[40] = {0};
	char dest3[40] = {0};
	ft_memcpy(ft_dest3, src3, 1);	
	memcpy(dest3, src3, 1);
	print_errors_string("ft_memcpy",		ft_dest3,		dest3);
	// printf("ft_memcpy : %s\n", ft_dest); 
	// printf("memcpy  : %s\n", dest);
	// printf("ft_memcpy : %s\n", ft_dest2); 
	// printf("memcpy  : %s\n", dest2);
	// printf("ft_memcpy : %s\n", ft_dest3); 
	// printf("memcpy  : %s\n", dest3);

	// ft_memmove
	char src4[20] = "Le jour se couche";
	char ft_dest4[20] = {0};
	char dest4[20] = {0};
	ft_memmove(ft_dest4, src4, 14);
	memmove(dest4, src4, 14);
	print_errors_string("ft_memmove",		ft_dest4,		dest4);
	//
	char src5[15] = "Hello World !";
	char ft_dest5[15] = {0};
	char dest5[15] = {0};
	ft_memmove(ft_dest5, src5, 1);
	memmove(dest5, src5, 1);
	print_errors_string("ft_memmove",		ft_dest5,		dest5);
	//
	char src6[15] = "Hello World !";
	char ft_dest6[15] = {0};
	char dest6[15] = {0};
	ft_memmove(ft_dest6, src6, 1);
	memmove(dest6, src6, 1);
	print_errors_string("ft_memmove",		ft_dest6,		dest6);
	//
	char src7[15] = "Hello \0World !";
	char ft_dest7[15] = {0};
	char dest7[15] = {0};
	ft_memmove(ft_dest7, src7, 14);
	memmove(dest7, src7, 14);
	print_errors_string("ft_memmove",		ft_dest7,		dest7);
	// printf("Src : %s\n", src4);
	// printf("ft_memmove : %s\n", ft_dest4);
	// printf("memmove : %s\n", dest4);
	// printf("Src : %s\n", src5);
	// printf("ft_memmove : %s\n", ft_dest5);
	// printf("memmove : %s\n", dest5);
	// printf("Src : %s\n", src6);
	// printf("ft_memmove : %s\n", ft_dest6);
	// printf("memmove : %s\n", dest6);
	// printf("Src : %s\n", src7);
	// printf("ft_memmove : %s\n", ft_dest7);
	// printf("memmove : %s\n", dest7);
	// printf("memmove : %c\n", dest7[6]);
	// printf("memmove : %c\n", dest7[7]);
	// printf("memmove : %c\n", dest7[8]);

	// ft_strlcpy
	// char ft_strlcpy_src1[14] = "Hello\0 World";
	// char ft_strlcpy_dst1[14] = {0};
	// char c_strlcpy_src1[14] = "Hello\0 World";
	// char c_strlcpy_dst1[14] = {0};
	// print_errors_size("ft_strlcpy",	ft_strlcpy(ft_strlcpy_dst1, ft_strlcpy_src1, 5),	strlcpy(c_strlcpy_dst1, c_strlcpy_src1, 5));
	//
	// char ft_strlcpy_src2[14] = "Hello World !";
	// char ft_strlcpy_dst2[14] = {0};
	// char c_strlcpy_src2[14] = "Hello World !";
	// char c_strlcpy_dst2[14] = {0};
	// print_errors_size("ft_strlcpy",	ft_strlcpy(ft_strlcpy_dst2, ft_strlcpy_src2, 0),	strlcpy(c_strlcpy_dst2, c_strlcpy_src2, 0));
	//
	char ft_strlcpy_src3[14] = "Hello World !";
	char ft_strlcpy_dst3[14] = {0};					// ERROR (on doit mettre un 15 pour nul terminer)
	char c_strlcpy_src3[14] = "Hello World !";
	char c_strlcpy_dst3[14] = {0};
	print_errors_size("ft_strlcpy",	ft_strlcpy(ft_strlcpy_dst3, ft_strlcpy_src3, 13),	strlcpy(c_strlcpy_dst3, c_strlcpy_src3, 13));	// PAS LE MEME COMPORTEMENT entre les fonctions SI dstsize >= taille de dst
	// printf("ft_strlcpy_dst1 : %s\n", ft_strlcpy_dst1);
	// printf("c_strlcpy_dst1 : %s\n", c_strlcpy_dst1);
	// printf("ft_strlcpy_dst1 : %s\n", ft_strlcpy_dst2);
	// printf("c_strlcpy_dst1 : %s\n", c_strlcpy_dst2);
	// printf("ft_strlcpy_dst1 : %s\n", ft_strlcpy_dst3);
	// printf("c_strlcpy_dst1 : %s\n", c_strlcpy_dst3);
	// printf("ft_strlcpy_dst1[i] : %c\n", ft_strlcpy_dst3[1]);
	//////////////////////////////////////////////////////////////////

	// Total of errors in tests
	error_count > 0 ? red_color() : green_color();
	printf("%d errors in tests.\n", error_count);
	defaut_color();
	return (0);
}
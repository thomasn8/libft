/* ------------------------------ */
// 			LIBFT TESTS			 //
/* ---------------------------- */
//
// -------------------------------------------------------------------------------
// | make re && gcc -Wall -Wextra -Werror libft_tests/main2.c -L. -lft -o a.out && ./a.out |
// -------------------------------------------------------------------------------
//
// 	a) 	make all	(ou "make fclean" puis "make all" ou "make" ou "make libft.a")
// 				a.a) 	Optional:	ranlib libft.a 	(créer index dans lib pour trouver rapidement les fonctions nécessaires)
// 	b)	gcc -Wall -Wextra -Werror libft_tests/main2.c -L. -lft -o a.out && ./a.out
// 				b.b) 	Optional:	ar -t libft.a 	(display the modules/functions)

// libft.h
#include "../libft.h"

// lib for printf() and write()
#include <stdio.h>
#include <unistd.h>

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
void	yellow_color(void)
{
	printf("\033[0;33m");
}
void	blue_color(void)
{
	printf("\033[0;34m");
}

int	main(void)
{
	int fd = 1;
	//
	blue_color();
	printf("ft_putchar_fd\n");
	char putchar1 = 'a';
	char putchar2 = '.';
	char putchar3 = ' ';
	char putchar4 = '>';
	char putchar5 = '	';
	char putchar6 = 'Z';
	char putchar7 = '\0';
	yellow_color();
	printf("Expected :\n");
	defaut_color();
	printf("%c", putchar1);
	printf("%c", putchar2);
	printf("%c", putchar3);
	printf("%c", putchar4);
	printf("%c", putchar5);
	printf("%c", putchar6);
	printf("%c", putchar7);
	printf("\n");
	yellow_color();
	printf("FT :");
	defaut_color();
	printf("\n");
	ft_putchar_fd(putchar1, fd);
	ft_putchar_fd(putchar2, fd);
	ft_putchar_fd(putchar3, fd);
	ft_putchar_fd(putchar4, fd);
	ft_putchar_fd(putchar5, fd);
	ft_putchar_fd(putchar6, fd);
	ft_putchar_fd(putchar7, fd);
	printf("\n");
	//
	blue_color();
	printf("ft_putstr_fd\n");
	char *putstr1 = "abcdefghijklmopqrstu...\0";
	char *putstr2 = "NO_BACKSLASH_0_AT_THE_END";
	char *putstr3 = "		    		  Hello 		  there.";
	yellow_color();
	printf("Expected :\n");
	defaut_color();
	printf("%s", putstr1);
	printf("\n");
	printf("%s", putstr2);
	printf("\n");
	printf("%s", putstr3);
	printf("\n");
	yellow_color();
	printf("FT :");
	defaut_color();
	printf("\n");
	ft_putstr_fd(putstr1, fd);
	printf("\n");
	ft_putstr_fd(putstr2, fd);
	printf("\n");
	ft_putstr_fd(putstr3, fd);
	printf("\n");
	//
	blue_color();
	printf("ft_putendl_fd\n");
	char *putendl1 = "abcdefghijklmopqrstu...\0";
	char *putendl2 = "NO_BACKSLASH_0_AT_THE_END";
	char *putendl3 = "		    		  Hello 		  there.";
	yellow_color();
	printf("Expected :\n");
	defaut_color();
	printf("%s", putendl1);
	printf("\n");
	printf("%s", putendl2);
	printf("\n");
	printf("%s", putendl3);
	printf("\n");
	yellow_color();
	printf("FT :");
	defaut_color();
	printf("\n");
	ft_putendl_fd(putendl1, fd);
	ft_putendl_fd(putendl2, fd);
	ft_putendl_fd(putendl3, fd);
	//
	blue_color();
	printf("ft_putnbr_fd\n");
	int putnbr1 = 0;
	int putnbr2 = -1;
	int putnbr3 = 1;
	int putnbr4 = +2147483647;
	int putnbr5 = -2147483647;
	int putnbr6 = -2147483648;
	yellow_color();
	printf("Expected :\n");
	defaut_color();
	printf("%d", putnbr1);printf("\n");
	printf("%d", putnbr2);printf("\n");
	printf("%d", putnbr3);printf("\n");
	printf("%d", putnbr4);printf("\n");
	printf("%d", putnbr5);printf("\n");
	printf("%d", putnbr6);printf("\n");
	yellow_color();
	printf("FT :");
	defaut_color();
	printf("\n");
	ft_putnbr_fd(putnbr1, fd);printf("\n");
	ft_putnbr_fd(putnbr2, fd);printf("\n");
	ft_putnbr_fd(putnbr3, fd);printf("\n");
	ft_putnbr_fd(putnbr4, fd);printf("\n");
	ft_putnbr_fd(putnbr5, fd);printf("\n");
	ft_putnbr_fd(putnbr6, fd);printf("\n");
	defaut_color();
	return (0);
}
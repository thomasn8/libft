
LIBFT TESTS

________________________________________________________________________________

HOW TO USE

I. 		Past this "libft_tests" folder at the root of your libft folder.


II. 	Execute this all-in-one command in your terminal :

	-------------------------------------------------------------------------------
	| make re && gcc -Wall -Wextra -Werror libft_tests/main.c -L. -lft && ./a.out |
	-------------------------------------------------------------------------------


III.	What does is do ?

==> Test your makefile + clean (fclean) + compile (cc) + make the lib (ar) + link (.c.o) + executable (a.out)

==>	It will tell you how many errors it gets from your libft functions and where they are (in which function)

________________________________________________________________________________

COMMANDS TO USE THESE TESTS WITH YOUR LIBRARY

a) Makefile :

	make all (or make/make libft.a)
	make fclean
	make re


b) Index the library (optional) :

	ranlib libft.a 


c) Compile your libft with the main.c and execute a.out	to test your functions :

	gcc -Wall -Wextra -Werror libft_tests/main.c -L. -lft && ./a.out


d) Display the modules/functions from your library (optional) :

	ar -t libft.a

________________________________________________________________________________

	focus_on_backslash_zero()

focus_on_backslash_zero.c contains a function you can use to debug.
It will display all char and \0 from a string
After or before and after replacing all the '\0' by '_'

________________________________________________________________________________

BY

Thomas Nanchen (thomasn8 / tnanchen)
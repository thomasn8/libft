/* ------------------------------ */
// MAIN FUNCTION TO TEST LIBFT.A //
/* ---------------------------- */


HOW TO USE

I. 		Past this "libft_tests" folder at the root of your libft folder.


II. 	Execute this all-in-one command in your terminal :

	-------------------------------------------------------------------------------
	| make re && gcc -Wall -Wextra -Werror libft_tests/main.c -L. -lft && ./a.out |
	-------------------------------------------------------------------------------


III.	What does is do ?

==> test your makefile + clean (fclean) + compile (cc) + make the lib (ar) + link (.c.o) + executable (a.out)
==>	It will tell you how many errors it gets from your libft functions and where they are (in which function)

________________________________________________________________________________

MAKEFILE COMMANDS

a) 	make all		(ou "make fclean" puis "make all" ou "make" ou "make libft.a")

	a.a) Optional:	ranlib libft.a 		(créer index dans lib pour trouver rapidement les fonctions nécessaires)

b)	gcc -Wall -Wextra -Werror libft_tests/main.c -L. -lft && ./a.out
	
	b.b) Optional:	ar -t libft.a 		(display the modules/functions)

________________________________________________________________________________

focus_on_backslash_zero()

focus_on_backslash_zero.c contains a function you can use to debug.
It will display all char and \0 from a string
After or before and after a replacing the \0 by _

________________________________________________________________________________

BY
© Thomas Nanchen (thomasn8 / tnanchen)
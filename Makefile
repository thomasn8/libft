#	= 	est utilisé pour spécifier une variable
#	:	est utilisé pour spécifier une règle
# make (sans paramètre) exécute par défaut la 1ère règle du makefile : all

###########################
## Variables du makefile ##
###########################

# fichiers sources à compiler
SRCS	= ft_isalpha.c	\
		  main.c		

# créer les .o à partir des .c à compiler et linker les .o
OBJS	= ${SRCS:.c=.o}

# compilateur
CC		= cc

#  variables du Makefile utilisées pour paramétrer la compilation d'un logiciel (but d'optimiser ou déboguer le code)
CFLAGS	= -Wall -Wextra -Werror

# nom qu'on va utiliser pour appeler la cmd du makefile (make + nom) et pour nommer l'executable
NAME	= libft

# cmd rm -f pour forcer la supression
RM		= rm -f

########################
## Règles du makefile ##
########################

# règle 1 par défaut pour appeler "make all" (ou juste "make") à la place de "make + name"
all:		${NAME}

# redéfinit une règle implicite du makefile pour créer les .o à partir des .c
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# dépendances : si .o sont inexistants ou si .c sont + récents que les .o
# compile le tout et créer l'exécutable au nom de la règle
${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

# supprimer les .o
clean:
			${RM} ${OBJS}

# appelle la règle clean pour supprimer les .o
# et supprime aussi l'executable
fclean:		clean
			${RM} ${NAME}

# préciser que ces règles sont des params du makefile (au cas où des fichiers auraient ces noms)
.PHONY:		all clean fclean

# supprime les .o et l'executable et recompile le tout
re:			fclean all
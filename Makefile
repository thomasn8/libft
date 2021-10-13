SRCS	= ft_isalpha.c	\
		  ft_isdigit.c	\
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c 

OBJS	= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

NAME		= libft.a

RM		= rm -f


all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			${RM} a.out

.PHONY:		all clean fclean re

re:			fclean all


# bonus
# ...
# ajouter les divers headers, librairies ou fonctions qui ne sont pas autorisées dans la
# partie principale du projet. Les bonus doivent être dans une fichier _bonus.{c/h}
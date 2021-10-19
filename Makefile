SRCS	= ft_isalpha.c	\
		  ft_isdigit.c	\
		  ft_isalnum.c 	\
		  ft_isascii.c 	\
		  ft_isprint.c 	\
		  ft_toupper.c 	\
		  ft_tolower.c 	\
		  ft_strlen.c 	\
		  ft_memset.c 	\
		  ft_bzero.c 	\
		  ft_memcpy.c 	\
		  ft_memmove.c 	\
		  ft_strlcpy.c 	\
		  ft_strlcat.c 	\
		  ft_strchr.c 	\
		  ft_strrchr.c 	\
		  ft_strncmp.c 	\
		  ft_memchr.c 	\
		  ft_memcmp.c 	\
		  ft_strnstr.c 	\
		  ft_atoi.c 	\
		  ft_strdup.c	\
		  ft_calloc.c	\
		  ft_substr.c	\
		  ft_strjoin.c	\
		  ft_strtrim.c	\
		  ft_split.c	\
		  ft_itoa.c		\
		  ft_strmapi.c	\
		  ft_striteri.c \
		  ft_putchar_fd.c	\
		  ft_putstr_fd.c	\
		  ft_putendl.c		\
		  ft_putnbr_fd.c

OBJS	= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

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
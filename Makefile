NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

INCLUDES = ./include/ft_printf.h

SRC = \
	src/ft_printf.c \
	src/ft_printf_char.c \
	src/ft_printf_num.c \
	src/ft_printf_hexa.c

OBJS = $(SRC:.c=.o)

.c.o :
	${CC} -I ./include ${CFLAGS} -c $< -o ${<:.c=.o}

all :	${NAME}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS} 

fclean :	clean
	rm -f ${NAME}

re :	fclean all

.PHONY :	all clean fclean re bonus rebonus

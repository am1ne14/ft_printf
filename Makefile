SRCS	= ft_printf.c \
		  utils/check_format.c \
		  utils/ft_put_hex.c \
		  utils/ft_put_ptr.c \
		  utils/ft_put_unsigned.c \
		  utils/ft_put_char.c \
		  utils/ft_put_nbr.c \
		  utils/ft_put_str.c \
		  utils/ft_strchr.c

OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@ -I.

all: ${NAME}

${NAME}: ${OBJS} ft_printf.h
	ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

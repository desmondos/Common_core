NAME = libftprintf.a

SRCS = ft_check_in.c ft_printf.c ft_print_char.c ft_print_nbr.c ft_print_unbr.c \
       ft_print_adress.c ft_print_lowhexa.c ft_print_str.c ft_print_uphexa.c

OBJS = ${SRCS:.c=.o}

LIBC = ar -rcs

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

INCS = includes\libftprintf.h

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	@${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re  .c.o

NAME = push_swap

SRC_DIR = ./sources/

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/main_utils.c $(SRC_DIR)/fill_stack.c \
	   $(SRC_DIR)/manage_error.c $(SRC_DIR)/push.c $(SRC_DIR)/push_swap.c \
	   $(SRC_DIR)/reverse_rot.c $(SRC_DIR)/rotate.c $(SRC_DIR)/sort.c \
	   $(SRC_DIR)/sort_utils.c $(SRC_DIR)/swap.c $(SRC_DIR)/utils.c \
	   $(SRC_DIR)/push_swap_utils.c \

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./Libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INC = -I${LIBFT_DIR}/includes

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCS = ${LIBFT_INC}

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${LIBFT}:
	@make -C ${LIBFT_DIR}

fclean: clean
	@${RM} ${NAME}
	@make -C ${LIBFT_DIR} fclean

clean:
	@${RM} ${OBJS}
	@make -C ${LIBFT_DIR} clean

re: fclean all

.PHONY: all fclean clean re

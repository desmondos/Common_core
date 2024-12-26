NAME = philo

SRC_DIR = ./source

SRCS = $(SRC_DIR)/main.c  $(SRC_DIR)/handle_error.c $(SRC_DIR)/init.c $(SRC_DIR)/cleanup.c \
	   $(SRC_DIR)/time_utils.c $(SRC_DIR)/utils.c $(SRC_DIR)/thread.c \
	   $(SRC_DIR)/philo_utils.c $(SRC_DIR)/philo_action.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

PFLAGS = -pthread

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${PFLAGS} -o ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

fclean: clean
	@${RM} ${NAME}

clean:
	@${RM} ${OBJS}

re: fclean all

.PHONY: all fclean clean re

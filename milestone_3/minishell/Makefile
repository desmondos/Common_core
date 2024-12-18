NAME = minishell

SRC_DIR = ./source

SRC_BUILT = ./builtins

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/main_utils.c $(SRC_DIR)/command.c \
	   $(SRC_DIR)/in_out.c $(SRC_DIR)/in_out_utils.c \
	   $(SRC_DIR)/process.c $(SRC_DIR)/process_utils.c $(SRC_DIR)/redir_utils.c \
	   $(SRC_DIR)/process_path_utils.c $(SRC_DIR)/quote_utils.c \
	   $(SRC_DIR)/parse_input.c $(SRC_DIR)/signal.c $(SRC_DIR)/signal_utils.c \
	   $(SRC_DIR)/utils.c $(SRC_DIR)/utils_utils.c $(SRC_DIR)/input_utils.c \
	   $(SRC_DIR)/expand_var.c $(SRC_DIR)/var_utils.c $(SRC_DIR)/env.c \
	   $(SRC_DIR)/builtins_utils.c $(SRC_DIR)/fork.c $(SRC_DIR)/environment.c \
	   $(SRC_DIR)/parse_pipe.c $(SRC_DIR)/redirection.c $(SRC_DIR)/env_utils.c \
	   $(SRC_DIR)/check.c $(SRC_DIR)/check_input.c $(SRC_DIR)/check_utils.c \
	   $(SRC_DIR)/execution.c $(SRC_DIR)/fd.c $(SRC_DIR)/handle_token.c \
	   $(SRC_DIR)/init_pipe.c $(SRC_DIR)/pipe_utils.c $(SRC_DIR)/char_utils.c \
	   $(SRC_DIR)/pid.c $(SRC_DIR)/fd_utils.c \
	   $(SRC_BUILT)/builtin_cd.c $(SRC_BUILT)/builtin_exit.c \
	   $(SRC_BUILT)/builtin_pwd.c $(SRC_BUILT)/builtin_echo.c \
	   $(SRC_BUILT)/builtin_env.c $(SRC_BUILT)/builtin_export.c \
	   $(SRC_BUILT)/builtin_unset.c \
	   
OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ./libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INC = -I${LIBFT_DIR}/includes

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -lreadline -lhistory

INCS = ${LIBFT_INC}

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${LDFLAGS} -o ${NAME} -lncurses -ltinfo

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

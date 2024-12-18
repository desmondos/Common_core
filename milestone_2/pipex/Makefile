NAME = pipex

SRCS_DIR = sources

SRCS = $(SRCS_DIR)/pipex.c $(SRCS_DIR)/pipex_utils_1.c \
	   $(SRCS_DIR)/pipex_utils_2.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

PRINTF_DIR = ./ft_printf/

PRINTF = $(PRINTF_DIR)/libftprintf.a

PRINTF_INC = -I$(PRINTF_DIR)/includes

LIBFT_DIR = ./Libft/

LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_INC = -I$(LIBFT_DIR)/includes

INCS = ${LIBFT_INC} ${PRINTF_INC}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} $(INCS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

re: fclean all

.PHONY: all fclean clean re


NAME = fdf

NAME_B = fdf_bonus

SRC_DIR = ./Mandatory/sources/

BNS_DIR = ./bonus/sources_bonus/

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/main_utils.c $(SRC_DIR)/main_utils_1.c \
	  $(SRC_DIR)/draw_utils.c $(SRC_DIR)/extras_utils.c $(SRC_DIR)/keys_tools.c \
	  $(SRC_DIR)/colors_utils.c $(SRC_DIR)/algo_fdf.c $(SRC_DIR)/clean_utils.c \
	  $(SRC_DIR)/display_set.c $(SRC_DIR)/matrix_utils.c \
	  $(SRC_DIR)/drawing.c $(SRC_DIR)/colors_utils_1.c $(SRC_DIR)/disp_set_utils.c \
	  $(SRC_DIR)/map_info.c $(SRC_DIR)/keys_utils.c $(SRC_DIR)/mouse_utils.c\
	  $(SRC_DIR)/../get_next_line/get_next_line.c $(SRC_DIR)/drawing_utility.c \
	  $(SRC_DIR)/../get_next_line/get_next_line_utils.c $(SRC_DIR)/transformation.c\

BNS = $(BNS_DIR)/main_bonus.c $(BNS_DIR)/main_utils_bonus.c \
	  $(BNS_DIR)/main_utils_1_bonus.c $(BNS_DIR)/draw_utils_bonus.c \
	  $(BNS_DIR)/extras_utils_bonus.c $(BNS_DIR)/keys_tools_bonus.c \
	  $(BNS_DIR)/colors_utils_bonus.c $(BNS_DIR)/algo_fdf_bonus.c \
	  $(BNS_DIR)/clean_utils_bonus.c $(BNS_DIR)/display_set_bonus.c \
	  $(BNS_DIR)/matrix_utils_bonus.c $(BNS_DIR)/drawing_bonus.c \
	  $(BNS_DIR)/colors_utils_1_bonus.c $(BNS_DIR)/disp_set_utils_bonus.c \
	  $(BNS_DIR)/map_info_bonus.c $(BNS_DIR)/keys_utils_bonus.c \
	  $(BNS_DIR)/../get_next_line/get_next_line.c \
	  $(BNS_DIR)/drawing_utility_bonus.c $(BNS_DIR)/mouse_utils_bonus.c\
	  $(BNS_DIR)/../get_next_line/get_next_line_utils.c \
	  $(BNS_DIR)/transformation_bonus.c \

OBJS = ${SRCS:.c=.o}

OBJS_B = ${BNS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_DIR =  ./minilibx-linux

MLX_LIB = -L${MLX_DIR} -lmlx -lXext -lX11

MLX_INC = -I${MLX_DIR}

RM = rm -f

LIBFT_DIR = ./Mandatory/Libft

LIBFT = ${LIBFT_DIR}/libft.a

LIBFT_INC = -I${LIBFT_DIR}/includes

PRINTF_DIR = ./Mandatory/ft_printf

PRINTF = ${PRINTF_DIR}/libftprintf.a

PRINTF_INC = -I${PRINTF_DIR}/includes

INCS = ${LIBFT_INC} ${PRINTF_INC} ${MLX_INC}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${PRINTF}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${PRINTF} ${MLX_LIB} -lm -o ${NAME}

${NAME_B}: ${OBJS_B} ${LIBFT} ${PRINTF}
	@${CC} ${CFLAGS} ${OBJS_B} ${LIBFT} ${PRINTF} ${MLX_LIB} -lm -o ${NAME_B}

.c.o:
	@${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

${LIBFT}:
	@make -C ${LIBFT_DIR}

${PRINTF}:
	@make -C ${PRINTF_DIR}

fclean: clean
	@${RM} ${NAME} ${NAME_B}
	@make -C ${LIBFT_DIR} fclean
	@make -C ${PRINTF_DIR} fclean
	@${RM} ${NAME_B}

clean:
	@${RM} ${OBJS} ${OBJS_B}
	@make -C ${LIBFT_DIR} clean
	@make -C ${PRINTF_DIR} clean
	@${RM} ${OBJS_B}

re: fclean all

bonus: $(NAME_B) $(OBJS_B)

.PHONY: all fclean clean re bonus

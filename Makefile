SHELL :=/bin/bash

# FdF
SRC_DIR = src/
SRC =	src/colors.c \
		src/draw.c \
		src/hooks.c \
		src/main.c \
		src/parse_map.c \
		src/project.c \
		src/split.c \
		src/test_fts.c \
		src/utils.c \
		src/utils2.c \
		src/xiaolin.c
SRCS = $(SRC)

TEST_SRC = src/test_fts.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRCS:.c=.o)))

# LIBFT
LIBFT = libft/libft.a
LIBFT_DIR = libft/

# MINILIBX
LIBX = minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
LIBX_DIR = minilibx-linux/

# PROGRESS BAR
TOTAL_C := $(shell find src/ -type f -name '*.c' -not -path '*/.*' | wc -l)

define	progress_bar
	@COUNT=$$(find obj -type f -name '*.o' | wc -l); \
	BAR_WIDTH=30; \
	NUM_HASHES=$$(( COUNT * BAR_WIDTH / $(TOTAL_C) )); \
	BAR=$$(printf "%-$${BAR_WIDTH}s" "$$(printf '%0.s#' $$(seq 1 $$NUM_HASHES))"); \
	echo -ne "Compiling: [$$BAR] ($$COUNT/$(TOTAL_C))\r"
endef


INCS_DIR = incs/
# CC = cc
CC = clang
# CFLAGS = -Wall -Werror -Wextra -g -Imlx_linux
CFLAGS = -Wall -Werror -Wextra -g -Imlx_linux -O3
L_CFLAGS = -L/usr/lib -Lmlx_linux -lXext -lX11 -lm -lz 
NAME = fdf
RM = rm -f

all: $(OBJ_DIR) $(LIBX) $(LIBFT) $(NAME)
	@echo -e "Compilation complete! fdf file generated.                         \n"

print_fdf:
	@echo -e "\n======  FdF  ======"

print_libx:
	@echo -e "\n=====  MiniLibX  ====="

print_libft:
	@echo -e "\n=====  Libft  ====="

$(OBJ_DIR):
	@mkdir $@

$(LIBX): print_libx
	@make --no-print-directory -C $(LIBX_DIR) all
	@make --no-print-directory print_libx
	@echo -e "Compilation complete! libmlx.a and libmlx_Linux.a files    "

$(LIBFT): print_libft
	@make --no-print-directory -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)
	$(progress_bar)

$(NAME): print_fdf $(LIBFT) $(LIBX) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBX) $(L_CFLAGS) -o $(NAME)

clean: $(OBJ_DIR)
	@make --no-print-directory print_libx
	@make --no-print-directory -C $(LIBX_DIR) clean
	@make --no-print-directory print_libft
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@make --no-print-directory print_fdf
	@$(RM) -r $(OBJ_DIR)
	@echo -e "cleaned .o files\n"

fclean: $(OBJ_DIR)
	@make --no-print-directory print_libx
	@make --no-print-directory -C $(LIBX_DIR) clean
	@$(RM) $(LIBX)
	@echo -e "\nCleaned $(LIBX) files"
	@make --no-print-directory print_libft
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@make --no-print-directory print_fdf
	@$(RM) -r $(OBJ_DIR)
	@echo "Cleaned .o files"
	@$(RM) $(NAME)
	@echo -e "Cleaned fdf executable\n"

re: fclean $(OBJ_DIR)
	@make --no-print-directory all

.PHONY: all clean fclean re print_fdf print_libft print_libx
# # TESTING
# TEST_PS = test_ps
# TEST_DIR = src/db/
# TEST_SRC = src/db/print_stack.c src/db/main.c
#
# $(TEST_PS): print_ps $(OBJ) $(LIB)
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(TEST_PS)

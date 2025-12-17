SHELL :=/bin/bash

# FdF
SRC_DIR = src/
SRC =	atoi_base_fdf.c \
		changes.c \
		check_files.c \
		colors.c \
		draw.c \
		hooks.c \
		main.c \
		parse_map.c \
		project.c \
		rotations.c \
		split.c \
		utils.c \
		utils2.c \
		xiaolin.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

BONUS_DIR = src_bonus/
BONUS_SRC = atoi_base_fdf_bonus.c \
			changes_bonus.c \
			check_files_bonus.c \
			colors_bonus.c \
			draw_bonus.c \
			hooks_bonus.c \
			list_changes_bonus.c \
			list_hooks_bonus.c \
			list_utils2_bonus.c \
			list_utils_bonus.c \
			main_bonus.c \
			mult_maps_bonus.c \
			mult_maps_utils_bonus.c \
			parse_map_bonus.c \
			project_bonus.c \
			rotations_bonus.c \
			split_bonus.c \
			utils2_bonus.c \
			utils_bonus.c \
			xiaolin_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_DIR)/, $(BONUS_SRC))


OBJ_DIR = obj/
BONUS_OBJ_DIR = obj/bonus/
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRCS:.c=.o)))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR),$(notdir $(BONUS_SRCS:.c=.o)))

# LIBFT
LIBFT = libft/libft.a
LIBFT_DIR = libft/

# MINILIBX
LIBX = minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
LIBX_DIR = minilibx-linux/

# PROGRESS BAR
TOTAL_C := $(shell find src/ -type f -name '*.c' -not -path '*/.*' | wc -l)
TOTAL_BONUS_C := $(shell find src_bonus/ -type f -name '*_bonus.c' -not -path '*/.*' | wc -l)

#		========== PROGRESS BAR SCRIPTS ===========

define	progress_bar
	@COUNT=$$(find obj -maxdepth 1 -type f -name '*.o' | wc -l); \
	BAR_WIDTH=30; \
	NUM_HASHES=$$(( COUNT * BAR_WIDTH / $(TOTAL_C) )); \
	BAR=$$(printf "%-$${BAR_WIDTH}s" "$$(printf '%0.s#' $$(seq 1 $$NUM_HASHES))"); \
	echo -ne "Compiling: [$$BAR] ($$COUNT/$(TOTAL_C))\r"
endef

define	progress_bar_bonus
	@COUNT=$$(find obj/bonus -type f -name '*_bonus.o' | wc -l); \
	BAR_WIDTH=30; \
	NUM_HASHES=$$(( COUNT * BAR_WIDTH / $(TOTAL_BONUS_C) )); \
	BAR=$$(printf "%-$${BAR_WIDTH}s" "$$(printf '%0.s#' $$(seq 1 $$NUM_HASHES))"); \
	echo -ne "Compiling: [$$BAR] ($$COUNT/$(TOTAL_BONUS_C))\r"
endef

#		========== PROGRESS BAR SCRIPTS ===========

INCS_DIR = incs/
CC = cc
# CC = clang
# CFLAGS = -Wall -Werror -Wextra -g -Imlx_linux -pg -O0
CFLAGS = -Wall -Werror -Wextra -g -Imlx_linux -O3
L_CFLAGS = -L/usr/lib -Lmlx_linux -lXext -lX11 -lm -lz 
NAME = fdf
NAME_BONUS = fdf_bonus
RM = rm -f

all: $(OBJ_DIR) $(LIBX) $(LIBFT) $(NAME)
	@echo -e "Compilation complete! fdf file generated.                         \n"

bonus: $(BONUS_OBJ_DIR) $(LIBX) $(LIBFT) $(NAME_BONUS)
	@echo -e "Compilation complete! fdf_bonus file generated.                         \n"

print_fdf:
	@echo -e "\n======  FdF  ======"

print_fdf_bonus:
	@echo -e "\n======  FdF Bonus  ======"

print_libx:
	@echo -e "\n=====  MiniLibX  ====="

print_libft:
	@echo -e "\n=====  Libft  ====="

$(OBJ_DIR):
	@mkdir $@

$(BONUS_OBJ_DIR):
	@mkdir -p $@

$(LIBX): print_libx
	@make --no-print-directory -C $(LIBX_DIR) all
	@make --no-print-directory print_libx
	@echo -e "Compilation complete! libmlx.a and libmlx_Linux.a files generated."

$(LIBFT): print_libft
	@make --no-print-directory -C $(LIBFT_DIR)

#		========== COMPILATION ===========

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)
	$(progress_bar)

$(BONUS_OBJ_DIR)%.o: $(BONUS_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)
	$(progress_bar_bonus)

#		========== COMPILATION ===========

$(NAME): print_fdf $(LIBFT) $(LIBX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBX) $(L_CFLAGS) -o $(NAME)

$(NAME_BONUS): print_fdf_bonus $(LIBFT) $(LIBX) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(LIBX) $(L_CFLAGS) -o $(NAME_BONUS)

clean: $(OBJ_DIR)
	@make --no-print-directory print_libx
	@make --no-print-directory -C $(LIBX_DIR) clean
	@make --no-print-directory print_libft
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@make --no-print-directory print_fdf
	@$(RM) -rf $(OBJ_DIR)
	@echo -e "cleaned .o files\n"

fclean: $(OBJ_DIR)
	@make --no-print-directory print_libx
	@make --no-print-directory -C $(LIBX_DIR) clean
	@$(RM) $(LIBX)
	@echo -e "\nCleaned $(LIBX) files"
	@make --no-print-directory print_libft
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@make --no-print-directory print_fdf
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned .o files"
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo -e "Cleaned fdf executables\n"

re: fclean $(OBJ_DIR)
	@make --no-print-directory all

.PHONY: all clean fclean re print_fdf print_libft print_libx bonus

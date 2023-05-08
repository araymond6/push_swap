NAME = push_swap
LIBFT = $(LIB_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src
LIB_DIR = libft
OP_DIR = src/ops
UTILS_DIR = src/utils
OBJ_DIR = obj/

SRCS =	main.c parsing.c parsing2.c process.c sort.c utils.c \
		long_atoi.c rotate.c reverse_rotate.c swap.c push.c sort_utils.c
VPATH = $(SRC_DIR) $(OP_DIR) $(UTILS_DIR)

OBJS = $(SRCS:%.c=%.o)
OBJ_PRE = $(addprefix $(OBJ_DIR), $(OBJS))
DEP = push_swap.h utils.h ops.h

# Colors
RESET = \033[0m
GREEN = \033[92m
MAGENTA = \033[95m

all: lib $(NAME)

$(OBJ_DIR)%.o: %.c $(DEP)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_PRE)
	@echo "$(GREEN)----$(MAGENTA) Compiling push_swap.. $(GREEN)----$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo "$(GREEN)-----$(MAGENTA) Push_swap compiled! $(GREEN)-----$(RESET)"

lib:
	@echo "$(GREEN)------$(MAGENTA) Compiling libft.. $(GREEN)------$(RESET)"
	@make -C $(LIB_DIR)
	@echo "$(GREEN)-------$(MAGENTA) Libft compiled! $(GREEN)-------$(RESET)"

clean:
	@echo "$(GREEN)-----$(MAGENTA) Cleaning project... $(GREEN)-----$(RESET)"
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)------$(MAGENTA) Project cleaned!! $(GREEN)------$(RESET)"

fclean: clean
	@echo "$(GREEN)-----$(MAGENTA) Removing program... $(GREEN)-----$(RESET)"
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)
	@echo "$(GREEN)------$(MAGENTA) Program removed!! $(GREEN)------$(RESET)"

debug: CFLAGS+=-g
debug: all

re: fclean all
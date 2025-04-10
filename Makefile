

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# 📌 Library name
NAME	= libftprintf.a

# 📜 Source files for printf
SRCS	= srcs/ft_putchar_lf.c \
          srcs/ft_putstr_pf.c \
          srcs/print_pointer_pf.c \
          srcs/print_signed_pf.c \
          srcs/print_unsigned_pf.c \
          srcs/print_hex_pf.c \
          srcs/print_percent_pf.c \
          srcs/ft_printf.c \
          srcs/utilis.c

# 🔨 Generate object files
OBJS	= $(SRCS:.c=.o)

# 📜 Libft directory
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# 🎨 Colors
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RED		= \033[1;31m
RESET	= \033[0m

# 📌 Compile object files
%.o: %.c
	@echo "$(YELLOW)🔧 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# 🔹 Main compilation
all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(YELLOW)🔧 Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✅ LibftPrintf successfully compiled!$(RESET)"

# 🧹 Clean object files
clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)🧹 Object files removed.$(RESET)"

# 🗑️ Full cleanup
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)🗑️  libftprintf.a removed.$(RESET)"

# 🔄 Recompile from scratch
re: fclean all

.PHONY: all clean fclean re
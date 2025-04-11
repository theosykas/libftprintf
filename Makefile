

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f


NAME	= libftprintf.a


SRCS	= srcs/ft_putchar_lf.c \
          srcs/ft_putstr_pf.c \
          srcs/print_pointer_pf.c \
          srcs/print_signed_pf.c \
          srcs/print_unsigned_pf.c \
          srcs/print_hex_pf.c \
          srcs/print_percent_pf.c \
          srcs/ft_printf.c \
          srcs/utilis.c


OBJS	= $(SRCS:.c=.o)


LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a


GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RED		= \033[1;31m
RESET	= \033[0m


%.o: %.c
	@echo "$(YELLOW)🔧 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@


all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(YELLOW)🔧 Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✅ LibftPrintf successfully compiled!$(RESET)"


clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)🧹 Object files removed.$(RESET)"


fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)🗑️  libftprintf.a removed.$(RESET)"


re: fclean all

.PHONY: all clean fclean re
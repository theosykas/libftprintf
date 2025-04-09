C         = cc
CFLAGS     = -Wall -Wextra -Werror
AR         = ar rcs
RM         = rm -f


NAME       = libftprintf.a



SRCS       = srcs/ft_putchar


OBJS       = $(SRCS:.c=.o)



GREEN      = \033[1;32m
RED      = \033[1;35m
CYAN       = \033[1;36m
PURPLE        = \033[1;31m
RESET      = \033[0m

%.o: %.c
	@echo "$(PURPLE)🀂 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✅ printf successfully compiled!$(RESET)"


bonus: $(NAME) $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)
	@echo "$(CYAN)😏 printf With Bonus Compiled!$(RESET)"


clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)🀃 Object files removed.$(RESET)"


fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🃅  printf.a removed.$(RESET)"


re: fclean all


.PHONY: all clean fclean re bonus
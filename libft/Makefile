# 🛠️ Compiler and options
CC         = cc
CFLAGS     = -Wall -Wextra -Werror
AR         = ar rcs
RM         = rm -f

# 📌 Library name
NAME       = libft.a

# 📜 Source files

SRCS       = srcs/ft_isalnum.c srcs/ft_isprint.c srcs/ft_memcmp.c srcs/ft_putchar_fd.c srcs/ft_split.c \
             srcs/ft_strlcat.c srcs/ft_strncmp.c srcs/ft_substr.c srcs/ft_atoi.c srcs/ft_isalpha.c \
             srcs/ft_itoa.c srcs/ft_memcpy.c srcs/ft_putendl_fd.c srcs/ft_strchr.c srcs/ft_strlcpy.c \
             srcs/ft_strnstr.c srcs/ft_tolower.c srcs/ft_bzero.c srcs/ft_isascii.c \
             srcs/ft_memmove.c srcs/ft_putnbr_fd.c srcs/ft_strdup.c srcs/ft_strlen.c srcs/ft_strrchr.c \
             srcs/ft_toupper.c srcs/ft_calloc.c srcs/ft_isdigit.c srcs/ft_memchr.c srcs/ft_memset.c \
             srcs/ft_putstr_fd.c srcs/ft_strjoin.c srcs/ft_strmapi.c srcs/ft_strtrim.c srcs/ft_striteri.c

BONUS_SRCS = srcs/ft_lstadd_front_bonus.c srcs/ft_lstnew_bonus.c srcs/ft_lstsize_bonus.c \
             srcs/ft_lstlast_bonus.c srcs/ft_lstadd_back_bonus.c srcs/ft_lstdelone_bonus.c \
             srcs/ft_lstclear_bonus.c srcs/ft_lstiter_bonus.c srcs/ft_lstmap_bonus.c


OBJS       = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


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
	@echo "$(GREEN)🀪 Libft successfully compiled!$(RESET)"

# 🔹 Bonus
bonus: $(NAME) $(BONUS_OBJS)
	@$(AR) $(NAME) $(BONUS_OBJS)
	@echo "$(CYAN)😏 Libft With Bonus Compiled!$(RESET)"


clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(RED)🀃 Object files removed.$(RESET)"


fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🃅  libft.a removed.$(RESET)"


re: fclean all


.PHONY: all clean fclean re bonus
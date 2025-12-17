NAME = pushswap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = pushswap.h
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = main.c \
		errors.c \
		stack1.c\
		sortutills.c \
		sort3num.c \
		sort.c\
		operations1.c\
		utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
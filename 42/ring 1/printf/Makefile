NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ft_printf.h
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = ft_printf.c\
	ft_put_c_and_s.c\
	ft_Put_x_and_X.c\
	ft_put_d_and_i_and_u.c\
	ft_put_p.c
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
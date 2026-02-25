NAME        = pipex
LIBFT       = libft/libft.a
LIBFT_DIR   = libft
MAIN        = src/main.c
SRCS        = src/utils
OBJS        = $(SRCS:.c=.o)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
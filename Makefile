NAME = pipex
LIBFT = libft
LIBFT_A = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS = src/main.c src/exec.c src/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
NAME = pipex

LIBFT = libft

MAIN = main.c

SRCS_PS =	

OBJ_PS = $(SRCS_PS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME) 

$(NAME): makelib
	cc $(CFLAGS) $(MAIN) $(NAME).a -o $(NAME)

makelib: $(OBJ_PS) 
	$(MAKE) -C $(LIBFT) all
	cp libft/libft.a $(NAME).a
	ar rcs $(NAME).a $(OBJ_PS)

clean:  
	rm -f $(OBJ_PS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME).a
	$(MAKE) -C $(LIBFT) fclean

re: fclean clean all 
	$(MAKE) -C $(LIBFT) re

.PHONY: all clean fclean re makelib
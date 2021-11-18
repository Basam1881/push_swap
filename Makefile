SRC_NAME = algorithm.c initialize_validation.c\
			operations_r.c operations_sp.c output.c\
			main.c sorted.c sorters.c sorters_utils.c\
			armored_atoi.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CFLAG = -Wall -Wextra -Werror

LIBFT_DIR = ./libft/

LIBFT_LIB = ./libft/libft.a

NAME = ft_push_swap.a

NAME_ALL = push_swap.a

EXEC_NAME = push_swap

all: ${NAME}

${NAME}:
	$(MAKE) -C $(LIBFT_DIR) all
	gcc -c $(CFLAG) $(SRC_NAME)
	ar -r $(NAME) $(OBJ_NAME)
	libtool -static -o $(NAME_ALL) $(NAME) $(LIBFT_LIB)
	gcc $(NAME_ALL) -o $(EXEC_NAME)

push: debug
	gcc $(NAME_ALL) -o $(EXEC_NAME)

debug:
	gcc -c $(CFLAG) $(SRC_NAME)
	ar -r $(NAME) $(OBJ_NAME)
	libtool -static -o $(NAME_ALL) $(NAME) $(LIBFT_LIB)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_NAME)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) $(NAME_ALL)

pclean:
	rm -rf $(OBJ_NAME)

pfclean: clean
	rm -rf $(NAME) $(NAME_ALL)

e: 
	rm -rf $(EXEC_NAME)

re: fclean all

pre: pfclean push

dre: pfclean debug

.PHONY: all clean fclean re
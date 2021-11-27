SRC_NAME = algorithm.c initialize_validation.c\
			operations_r.c operations_sp.c output.c\
			sorted.c sorters.c sorters_utils.c\
			armored_atoi.c sorters_utils2.c big_sorter.c\
			sorters_utils3.c

PUSH_MAIN = main.c

CHECKER_MAIN = checker.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CFLAG = -Wall -Wextra -Werror

LIBFT_DIR = ./libft/

LIBFT_LIB = ./libft/libft.a

GNL_DIR = ./get_next_line/

GNL_LIB = ./get_next_line/gnl.a

NAME = ft_push_swap.a

NAME_ALL = push_swap.a

EXEC_NAME = push_swap

EXEC_CHECKER_NAME = checker

all: ${NAME}

${NAME}:

	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(GNL_DIR) all
	gcc -c $(CFLAG) $(SRC_NAME)
	ar -r $(NAME) $(OBJ_NAME)
	libtool -static -o $(NAME_ALL) $(NAME) $(LIBFT_LIB) $(GNL_LIB)
	gcc $(NAME_ALL) $(PUSH_MAIN) -o $(EXEC_NAME)
	gcc $(NAME_ALL) $(CHECKER_MAIN) -o $(EXEC_CHECKER_NAME)

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
	rm -rd $(EXEC_CHECKER_NAME)

re: fclean all

pre: pfclean push

dre: pfclean debug

test:
	././push_swap_tester1/push_stats.sh

.PHONY: all clean fclean re
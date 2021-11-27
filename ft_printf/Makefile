
SRC_NAME = putchar_fd.c\
		putstr_fd.c\
		putnbr_fd.c\
		ft_printf.c\
		putunbr_fd.c\
		putpnbr_fd.c\
		putxnbr_fd.c\
		putxxnbr_fd.c\
		ft_checks.c\
		ft_print_arg.c\
		ft_get_me_arg_len.c

OBJ_NAME = $(SRC_NAME:%.c=%.o) 
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJ_NAME}
	@gcc -c ${CFLAG} ${SRC_NAME}
	@ar -rc $(NAME) $(OBJ_NAME)

bonus: ${NAME}

clean:
	@rm -rf ${OBJ_NAME}

fclean: clean
	@rm -f ${NAME}

re: fclean all
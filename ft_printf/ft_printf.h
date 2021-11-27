/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:58:48 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 12:25:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flag
{
	va_list			arg;
	int				plus;
	int				minus;
	int				space;
	int				hash;
	int				zero;
	int				precision_flag;
	int				precision;
	int				f_precision;
	int				padding;
	int				width;
	int				len;
	int				zero_int_flag;
	int				size_only;
	int				empty_string;
	char			type;
	int				counter;
	int				print_flag;
}				t_flag;

void	putnbr_fd(int n, t_flag *new_arg, int fd);
int		ft_printf(const char *var, ...);
void	putpnbr_fd(unsigned long long int nb, t_flag *new_arg, int fd);
void	putunbr_fd(unsigned int nb, t_flag *new_arg, int fd);
void	putxnbr_fd(unsigned int nb, t_flag *new_arg, int fd);
void	putxxnbr_fd(unsigned int nb, t_flag *new_arg, int fd);
void	putchar_fd(char c, int fd, t_flag *new_arg);
void	putstr_fd(char *s, int fd, t_flag *new_arg);
int		get_arg_len(t_flag *new_arg, va_list arg);
void	print_all(t_flag *new_arg, va_list arg);
void	check_padding(t_flag *new_arg, va_list arg);
int		check_flags(char *fmt, t_flag *new_arg);
int		check_type(char c);
void	print_no_spicifier(t_flag *new_arg);

#endif

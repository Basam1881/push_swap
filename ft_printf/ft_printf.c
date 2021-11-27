/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:28:20 by marvin            #+#    #+#             */
/*   Updated: 2021/11/27 12:14:52 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	initialize_new_arg(t_flag *new_arg)
{
	new_arg->plus = 0;
	new_arg->minus = 0;
	new_arg->space = 0;
	new_arg->hash = 0;
	new_arg->zero = 0;
	new_arg->precision_flag = 0;
	new_arg->precision = 0;
	new_arg->f_precision = 0;
	new_arg->padding = 0;
	new_arg->width = 0;
	new_arg->len = 0;
	new_arg->zero_int_flag = 0;
	new_arg->size_only = 0;
	new_arg->empty_string = 0;
	new_arg->type = 0;
	new_arg->print_flag = 0;
	return (*new_arg);
}

static int	print_arg(char *fmt, t_flag *new_arg, va_list arg)
{
	int		i;

	initialize_new_arg(new_arg);
	i = 0;
	i += check_flags(fmt, new_arg);
	new_arg->type = check_type(fmt[i]);
	if (new_arg->type)
		check_padding(new_arg, arg);
	else
	{
		if (new_arg->size_only && !new_arg->zero)
			print_no_spicifier(new_arg);
		else
			putchar_fd(fmt[i], 1, new_arg);
	}
	return (i);
}

int	ft_printf(const char *var, ...)
{
	int		i;
	va_list	arg;
	t_flag	*new_arg;

	new_arg = (t_flag *)malloc(sizeof(t_flag));
	if (!new_arg)
		return (0);
	new_arg->counter = 0;
	va_start (arg, var);
	i = 0;
	new_arg->print_flag = 0;
	while (var[i])
	{
		if (var[i] == '%' && new_arg->print_flag == 0)
			new_arg->print_flag = 1;
		else if (var[i] != '%' && new_arg->print_flag == 1)
			i += print_arg((char *)&var[i], new_arg, arg);
		else
			putchar_fd(var[i], 1, new_arg);
		i++;
	}
	free (new_arg);
	va_end (arg);
	return (new_arg->counter);
}

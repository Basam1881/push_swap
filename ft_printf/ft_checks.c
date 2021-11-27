/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:54:41 by bnaji             #+#    #+#             */
/*   Updated: 2021/10/29 21:41:19 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	store_padding(t_flag *new_arg, int tmp)
{
	if (new_arg->len >= new_arg->precision)
	{
		if (new_arg->type == 's' && new_arg->precision_flag)
			new_arg->padding = new_arg->width - new_arg->precision;
		else if ((new_arg->type == 'd' || new_arg->type == 'i')
			&& tmp < 0 && new_arg->f_precision >= 0)
			new_arg->padding = new_arg->width - new_arg->len
				- new_arg->f_precision;
		else
			new_arg->padding = new_arg->width - new_arg->len;
	}
	else
	{
		if (new_arg->type == 's' && new_arg->precision_flag)
			new_arg->padding = new_arg->width - new_arg->len;
		else if ((new_arg->type == 'd' || new_arg->type == 'i') && tmp < 0)
			new_arg->padding = new_arg->width - new_arg->len
				- new_arg->f_precision;
		else
			new_arg->padding = new_arg->width - new_arg->precision;
	}
	if ((new_arg->plus == 1 || new_arg->space == 1) && tmp < 0)
		new_arg->padding--;
	else if (new_arg->hash)
		new_arg->padding -= 2;
}

void	check_padding(t_flag *new_arg, va_list arg)
{
	int		tmp;
	va_list	arg_copy;
	va_list	arg_copy2;

	va_copy(arg_copy, arg);
	va_copy(arg_copy2, arg);
	tmp = va_arg(arg_copy2, int);
	if (new_arg->type == 's' && !tmp)
		new_arg->empty_string = 1;
	if (tmp == 0 && !new_arg->precision && new_arg->precision_flag)
		new_arg->zero_int_flag = 1;
	new_arg->len = get_arg_len(new_arg, arg_copy);
	if (new_arg->precision_flag == 1 && new_arg->type != 's')
	{			
		new_arg->f_precision = new_arg->precision - new_arg->len;
		if (tmp < 0 && (new_arg->type == 'd' || new_arg->type == 'i'))
			new_arg->f_precision += 1;
	}
	if (new_arg->width)
		store_padding(new_arg, tmp);
	print_all(new_arg, arg);
}

static int	check_signs(char *fmt, t_flag *new_arg, int i)
{
	if (fmt[i] == '#')
		new_arg->hash = 1;
	else if (fmt[i] == ' ')
		new_arg->space = 1;
	else if (fmt[i] == '+')
		new_arg->plus = 1;
	else if (fmt[i] == '-')
		new_arg->minus = 1;
	else if (fmt[i] == '.')
		new_arg->precision_flag = 1;
	else
		return (0);
	return (1);
}

int	check_flags(char *fmt, t_flag *new_arg)
{
	int			i;

	i = 0;
	while (fmt[i])
	{
		if (check_signs(fmt, new_arg, i))
			;
		else if (!new_arg->width && fmt[i] == '0' && !new_arg->precision)
			new_arg->zero = 1;
		else if (fmt[i] >= '0' && fmt[i] <= '9' && !new_arg->precision_flag)
			new_arg->width = (new_arg->width * 10) + (fmt[i] - '0');
		else if (fmt[i] >= '0' && fmt[i] <= '9' && new_arg->precision_flag)
			new_arg->precision = (new_arg->precision * 10) + (fmt[i] - '0');
		else if (fmt[i] == '%' && new_arg->width)
		{
			new_arg->size_only = 1;
			break ;
		}
		else
			break ;
		i++;
	}
	return (i);
}

int	check_type(char c)
{
	char	*types;
	int		i;

	i = 0;
	types = "cspdiuxX";
	while (i < 8)
	{
		if (types[i] == c)
			return (types[i]);
		i++;
	}
	return (0);
}

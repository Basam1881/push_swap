/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:52:44 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 12:07:15 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_no_spicifier(t_flag *new_arg)
{
	if (new_arg->size_only && !new_arg->zero)
	{
		if (new_arg->minus)
			new_arg->counter += new_arg->width - 1;
		else
		{
			if (!new_arg->zero)
				while (new_arg->width-- > 1)
					putchar_fd(' ', 1, new_arg);
			else
				while (new_arg->width-- > 1)
					putchar_fd('0', 1, new_arg);
		}
		putchar_fd('%', 1, new_arg);
	}
}

static void	print_type(t_flag *new_arg, va_list arg)
{
	if (new_arg->type == 'c')
		putchar_fd(va_arg(arg, int), 1, new_arg);
	else if (new_arg->type == 's')
		putstr_fd(va_arg(arg, char *), 1, new_arg);
	else if ((new_arg->type == 'd' || new_arg->type == 'i'))
		putnbr_fd(va_arg(arg, int), new_arg, 1);
	else if (new_arg->type == 'u')
		putunbr_fd(va_arg(arg, unsigned int), new_arg, 1);
	else if (new_arg->type == 'x')
		putxnbr_fd(va_arg(arg, unsigned int), new_arg, 1);
	else if (new_arg->type == 'X')
		putxxnbr_fd(va_arg(arg, unsigned int), new_arg, 1);
	else if (new_arg->type == 'p')
	{
		putstr_fd("0x", 1, new_arg);
		putpnbr_fd(va_arg(arg, unsigned long long int), new_arg, 1);
	}
}

static void	print_sign(t_flag *new_arg, va_list arg)
{
	int		tmp;
	va_list	arg_copy;

	va_copy(arg_copy, arg);
	tmp = va_arg(arg_copy, int);
	if (new_arg->type == 'd' || new_arg->type == 'i')
	{
		if (new_arg->plus == 1 && tmp >= 0)
			putchar_fd('+', 1, new_arg);
		else if (new_arg->space == 1 && tmp >= 0)
			putchar_fd(' ', 1, new_arg);
		else if (tmp < 0)
			putchar_fd('-', 1, new_arg);
	}
	else if (new_arg->hash == 1)
	{
		if (new_arg->type == 'x' && tmp)
			putstr_fd("0x", 1, new_arg);
		else if (new_arg->type == 'X' && tmp)
			putstr_fd("0X", 1, new_arg);
	}
}

static void	print_no_minus(t_flag *new_arg, va_list arg)
{
	if (new_arg->zero && !new_arg->precision_flag)
	{
		print_sign(new_arg, arg);
		while (new_arg->padding-- > 0)
			putchar_fd('0', 1, new_arg);
	}
	else
	{
		while (new_arg->padding-- > 0)
			putchar_fd(' ', 1, new_arg);
		print_sign(new_arg, arg);
		while (new_arg->f_precision-- > 0)
			putchar_fd('0', 1, new_arg);
	}
	print_type(new_arg, arg);
}

void	print_all(t_flag *new_arg, va_list arg)
{
	if (new_arg->padding > 0)
	{
		if (new_arg->minus == 1)
		{
			print_sign(new_arg, arg);
			while (new_arg->f_precision-- > 0)
				putchar_fd('0', 1, new_arg);
			print_type(new_arg, arg);
			while (new_arg->padding-- > 0)
				putchar_fd(' ', 1, new_arg);
		}
		else
			print_no_minus(new_arg, arg);
	}
	else
	{
		print_sign(new_arg, arg);
		while (new_arg->f_precision-- > 0)
			putchar_fd('0', 1, new_arg);
		print_type(new_arg, arg);
	}
}

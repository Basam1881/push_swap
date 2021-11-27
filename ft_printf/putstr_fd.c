/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:56:57 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 12:13:16 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_null(int fd, t_flag *new_arg)
{
	if (new_arg->precision < new_arg->len && new_arg->type == 's'
		&& new_arg->precision_flag)
	{
		write(fd, "(null)", new_arg->precision);
		new_arg->counter += new_arg->precision;
	}
	else
	{
		write(fd, "(null)", 6);
		new_arg->counter += 6;
		return ;
	}
}

void	putstr_fd(char *s, int fd, t_flag *new_arg)
{
	if (!s)
		if_null(fd, new_arg);
	else
	{
		if (new_arg->precision < new_arg->len && new_arg->type == 's'
			&& new_arg->precision_flag)
		{
			write(fd, s, new_arg->precision);
			new_arg->counter += new_arg->precision;
		}
		else
		{
			new_arg->type = new_arg->type;
			write(fd, s, ft_strlen(s));
			new_arg->counter += ft_strlen(s);
		}
	}
}

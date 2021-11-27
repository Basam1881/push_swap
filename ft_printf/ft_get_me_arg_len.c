/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_me_arg_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:49:56 by bnaji             #+#    #+#             */
/*   Updated: 2021/10/29 21:42:26 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_p(t_flag *new_arg, va_list arg)
{
	int						i;
	unsigned long long int	ltmp;
	va_list					arg_copy;
	char					*tmp;

	va_copy(arg_copy, arg);
	tmp = va_arg(arg_copy, char *);
	i = 0;
	if (new_arg->type == 's' && tmp)
		i = ft_strlen(va_arg(arg, char *));
	else if (new_arg->type == 's' && !tmp)
		i = 6;
	if (new_arg->type == 'p')
	{
		ltmp = va_arg(arg, unsigned long long int);
		if (!ltmp)
			i++;
		while (ltmp)
		{
			ltmp = ltmp / 16;
			i++;
		}
		i += 2;
	}
	return (i);
}

static int	get_i_d_c_s_p(t_flag *new_arg, va_list arg)
{
	int						i;
	int						itmp;

	i = 0;
	if (new_arg->type == 'c')
		i++;
	else if (new_arg->type == 'd' || new_arg->type == 'i')
	{
		itmp = va_arg(arg, int);
		if (itmp <= 0 && !new_arg->zero_int_flag)
			i++;
		while (itmp)
		{
			itmp = itmp / 10;
			i++;
		}
	}
	i += get_p(new_arg, arg);
	return (i);
}

int	get_arg_len(t_flag *new_arg, va_list arg)
{
	int				i;
	unsigned int	utmp;

	i = 0;
	if (new_arg->type == 'x' || new_arg->type == 'X' || new_arg->type == 'u')
	{
		utmp = va_arg(arg, int);
		if (!utmp && !new_arg->zero_int_flag)
			i++;
		while (utmp)
		{
			if (new_arg->type == 'u')
				utmp = utmp / 10;
			else
				utmp = utmp / 16;
			i++;
		}
	}
	i += get_i_d_c_s_p(new_arg, arg);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   armored_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:11:03 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/18 04:03:46 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	type_check(char *str)
{
	int					i;
	int					digits;

	i = 0;
	digits = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '-'
				|| str[i] == '+' || (str[i] >= '0' && str[i] <= '9')))
			error();
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (digits >= 10)
				error();
			digits++;
		}
		i++;
	}
	if (!digits)
		error();
}

static int	length_check(unsigned long long nb, int mult)
{
	if (nb > 2147483647 && mult == 1)
		error();
	else if (nb > 2147483648 && mult == -1)
		error();
	nb *= mult;
	return (nb);
}

int	armored_atoi(const char *str)
{
	int						i;
	int						mult;
	unsigned long long		nb;

	mult = 1;
	nb = 0;
	i = 0;
	type_check((char *)str);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (str[i])
		error();
	nb = length_check(nb, mult);
	return (nb);
}

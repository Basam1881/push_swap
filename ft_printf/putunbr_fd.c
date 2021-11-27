/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:57:27 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 12:13:07 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putunbr_fd(unsigned int nb, t_flag *new_arg, int fd)
{
	unsigned int	new_nb;

	if (new_arg->zero_int_flag)
		return ;
	if (nb == 0)
		putchar_fd(nb + 48, fd, new_arg);
	else if (nb > 0)
	{
		new_nb = nb / 10;
		if (new_nb != 0)
			putunbr_fd(new_nb, new_arg, fd);
		putchar_fd(nb % 10 + 48, fd, new_arg);
	}
}

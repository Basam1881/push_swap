/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putxnbr_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 01:46:41 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 12:12:55 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putxnbr_fd(unsigned int nb, t_flag *new_arg, int fd)
{
	unsigned int	new_nb;

	if (new_arg->zero_int_flag)
		return ;
	if (nb == 0)
		putchar_fd(nb + 48, fd, new_arg);
	else if (nb > 0)
	{
		new_nb = nb / 16;
		if (new_nb != 0)
			putxnbr_fd(new_nb, new_arg, fd);
		if (nb % 16 < 10)
			putchar_fd(nb % 16 + 48, fd, new_arg);
		else
			putchar_fd(nb % 16 + 87, fd, new_arg);
	}
}

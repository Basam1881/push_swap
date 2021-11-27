/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:00:59 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 12:06:17 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putchar_fd(char c, int fd, t_flag *new_arg)
{
	write(fd, &c, 1);
	new_arg->counter++;
	new_arg->print_flag = 0;
}

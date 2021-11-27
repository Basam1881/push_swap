/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:50:51 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 18:57:46 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solver(t_var *stack_info)
{
	if (stack_info->atop == 0)
		return ;
	else if (stack_info->atop == 1)
		sort_2(stack_info);
	else if (stack_info->atop == 2)
		sort_3(stack_info);
	else if (stack_info->atop == 3)
		sort_4(stack_info);
	else if (stack_info->atop == 4)
		sort_5(stack_info);
	else if (stack_info->atop < 100)
		big_sorter(stack_info);
	else
		big_big_sorter(stack_info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:50:51 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/18 07:07:34 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a(t_var *stack_info)
{
	int	i;

	printf("+-----------------------------------+\n");
	i = 4;
	while (i >= 0)
	{
		printf("stack a: %d\n", stack_info->a_stack[i]);
		i--;
	}
	printf("+-----------------------------------+\n");
}

void	solver(t_var *stack_info)
{
	// print_a(stack_info);
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
	// print_a(stack_info);
}

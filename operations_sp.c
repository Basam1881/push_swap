/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 02:39:34 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 11:21:12 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_var *stack_info, char c, int checker_flag)
{
	int	tmp;

	if ((c == 'a' || c == 's') && stack_info->atop > 0)
	{
		tmp = stack_info->a_stack[stack_info->atop];
		stack_info->a_stack[stack_info->atop] = stack_info
			->a_stack[stack_info->atop - 1];
		stack_info->a_stack[stack_info->atop - 1] = tmp;
		if (!checker_flag)
			printf("s%c\n", c);
	}
	if ((c == 'b' || c == 's') && stack_info->btop > 0)
	{
		tmp = stack_info->b_stack[stack_info->btop];
		stack_info->b_stack[stack_info->btop] = stack_info
			->b_stack[stack_info->btop - 1];
		stack_info->b_stack[stack_info->btop - 1] = tmp;
		if (!checker_flag)
			printf("s%c\n", c);
	}
}

void	push(t_var *stack_info, char c, int checker_flag)
{
	if (c == 'a' && stack_info->btop > -1)
	{
		stack_info->a_stack[stack_info->atop + 1] = stack_info
			->b_stack[stack_info->btop];
		stack_info->a_stack[stack_info->atop + 2] = 0;
		stack_info->atop++;
		stack_info->b_stack[stack_info->btop] = 0;
		stack_info->btop--;
		if (!checker_flag)
			printf("p%c\n", c);
	}
	else if (c == 'b' && stack_info->atop > -1)
	{
		stack_info->b_stack[stack_info->btop + 1] = stack_info
			->a_stack[stack_info->atop];
		stack_info->b_stack[stack_info->btop + 2] = 0;
		stack_info->btop++;
		stack_info->a_stack[stack_info->atop] = 0;
		stack_info->atop--;
		if (!checker_flag)
			printf("p%c\n", c);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:35:06 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/21 15:35:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_size(t_var *stack_info, char c)
{
	int	i;
	int	zero_index;

	i = 0;
	zero_index = 0;
	if (c == 'a')
	{
		while (i <= stack_info->atop)
		{
			if (stack_info->a_stack[zero_index] < stack_info->a_stack[i])
				zero_index = i;
			i++;
		}
	}
	else
	{
		while (i <= stack_info->btop)
		{
			if (stack_info->b_stack[zero_index] > stack_info->b_stack[i])
				zero_index = i;
			i++;
		}
	}
	rotate_to(stack_info, c, zero_index, 0);
}

int	final_ckeck(t_var *stack_info, char c)
{
	int	i;

	i = 0;
	if (c == 'a')
	{
		while (i < stack_info->atop)
		{
			if (stack_info->a_stack[i] < stack_info->a_stack[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < stack_info->btop)
		{
			if (stack_info->a_stack[i] > stack_info->a_stack[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

// void	sort_last_a(t_var *stack_info)
// {	
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:35:06 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 02:04:50 by bnaji            ###   ########.fr       */
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

// void	sort_last_a(t_var *stack_info)
// {	
// }

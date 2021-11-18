/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:32:52 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/18 06:14:41 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_var *stack_info)
{
	if (!is_a_sorted(stack_info))
		swap(stack_info, 'a');
}

void	sort_3(t_var *stack_info)
{
	if (!is_a_sorted(stack_info))
	{
		rev_rotate_helper(stack_info, 1, 0);
		rotate_helper(stack_info, 2, 0);
		sort_2(stack_info);
	}
}

void	sort_4(t_var *stack_info)
{
	if (!is_a_sorted(stack_info))
	{
		rev_rotate_helper(stack_info, 1, 0);
		rotate_helper(stack_info, 2, 0);
		rotate_helper(stack_info, 2, 0);
		rotate_helper(stack_info, 3, 0);
		if (!is_a_sorted(stack_info))
		{
			if (stack_info->a_stack[1] == stack_info->sorted_stack[1])
			{
				swap(stack_info, 'a');
				return ;
			}
			if (stack_info->a_stack[3] == stack_info->sorted_stack[1])
				swap(stack_info, 'a');
			rotate(stack_info, 'a');
			swap(stack_info, 'a');
			rev_rotate(stack_info, 'a');
			sort_2(stack_info);
		}
	}
}

void	sort_5(t_var *stack_info)
{
	int	n;

	if (!is_a_sorted(stack_info))
	{
		n = 2;
		while (n)
		{
			if (stack_info->a_stack[stack_info->atop] < stack_info
				->sorted_stack[stack_info->sorted_median])
			{
				push(stack_info, 'b');
				n--;
			}
			else if (stack_info->a_stack[0] < stack_info
				->sorted_stack[stack_info->sorted_median])
				rev_rotate(stack_info, 'a');
			else
				rotate(stack_info, 'a');
		}
		if (stack_info->b_stack[1] < stack_info->b_stack[0])
			swap(stack_info, 'b');
		sort_3(stack_info);
		push(stack_info, 'a');
		push(stack_info, 'a');
	}
}

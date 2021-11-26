/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:21:36 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/24 15:16:55 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_helper(t_var *stack_info, int a, int s)
{
	if (stack_info->a_stack[a] == stack_info->sorted_stack[s])
		rotate(stack_info, 'a');
}

void	rev_rotate_helper(t_var *stack_info, int a, int s)
{
	if (stack_info->a_stack[a] == stack_info->sorted_stack[s])
		rev_rotate(stack_info, 'a');
}

static void	rotate_b_to(t_var *stack_info, char c, int old, int n)
{
	int	i;

	i = 0;
	if (c == 'b')
	{
		if (n > old)
		{
			if (n - old <= old)
			{
				while (old++ < n)
					rotate(stack_info, 'b');
			}
			else
			{
				while (old-- >= 0)
					rev_rotate(stack_info, 'b');
			}
		}
		else
		{
			if (old - n <= n)
			{
				while (n++ < old)
					rotate(stack_info, 'b');
			}
			else
			{
				while (old-- > 0)
					rev_rotate(stack_info, 'b');
			}
		}
	}
}

void	rotate_to(t_var *stack_info, char c, int old, int n)
{
	if (c == 'a')
	{
		if (n - old <= old)
		{
			while (old++ < n)
			{
				sort_b(stack_info, get_closest_b(stack_info));
				if ((stack_info->btop - stack_info->index <= stack_info->index || stack_info->btop - (n - old) - 1 <= stack_info->index + 1) && stack_info->index < stack_info->btop)
				{
					rotate(stack_info, 'r');
					stack_info->index++;
				}
				else
					rotate(stack_info, 'a');
			}
		}
		else
		{
			while (old-- >= 0)
			{
				sort_b(stack_info, get_closest_b(stack_info));
				if ((stack_info->btop - stack_info->index > stack_info->index || stack_info->index - old <= stack_info->btop - stack_info->index) && stack_info->index >= 0)
				{
					rev_rotate(stack_info, 'r');
					stack_info->index--;
				}
				else
					rev_rotate(stack_info, 'a');
			}
		}
	}
	rotate_b_to(stack_info, c, old, n);
}

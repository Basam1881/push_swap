/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:21:36 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 18:58:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_helper(t_var *stack_info, int a, int s)
{
	if (stack_info->a_stack[a] == stack_info->sorted_stack[s])
		rotate(stack_info, 'a', 0);
}

void	rev_rotate_helper(t_var *stack_info, int a, int s)
{
	if (stack_info->a_stack[a] == stack_info->sorted_stack[s])
		rev_rotate(stack_info, 'a', 0);
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
				while (old++ < n)
					rotate(stack_info, 'b', 0);
			else
				while (old-- >= 0)
					rev_rotate(stack_info, 'b', 0);
		}
		else
		{
			if (old - n <= n)
				while (n++ < old)
					rotate(stack_info, 'b', 0);
			else
				while (old-- > 0)
					rev_rotate(stack_info, 'b', 0);
		}
	}
}

static void	rotate_to_helper(t_var *stack_info, int *old, int *n)
{
	while ((*old)++ < *n)
	{
		sort_b(stack_info, get_closest_b(stack_info));
		if ((stack_info->btop - stack_info->index <= stack_info->index
				|| stack_info->btop - (*n - *old) - 1 <= stack_info
				->index + 1) && stack_info->index < stack_info
			->btop && stack_info->sorted_top < 100)
		{
			rotate(stack_info, 'r', 0);
			stack_info->index++;
		}
		else
			rotate(stack_info, 'a', 0);
	}
	if (!*n)
	{
		*n = stack_info->atop + 2;
		while ((*old)++ < *n)
			rotate(stack_info, 'a', 0);
	}
}

void	rotate_to(t_var *stack_info, char c, int old, int n)
{
	if (c == 'a')
	{
		if (n - old <= old || stack_info->atop - old <= old - n)
			rotate_to_helper(stack_info, &old, &n);
		else
		{
			while (old-- >= 0)
			{
				sort_b(stack_info, get_closest_b(stack_info));
				if ((stack_info->btop - stack_info->index > stack_info->index
						|| stack_info->index - old <= stack_info
						->btop - stack_info->index) && stack_info->index >= 0
					&& stack_info->sorted_top < 100)
				{
					rev_rotate(stack_info, 'r', 0);
					stack_info->index--;
				}
				else
					rev_rotate(stack_info, 'a', 0);
			}
		}
	}
	rotate_b_to(stack_info, c, old, n);
}

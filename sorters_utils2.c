/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 08:34:00 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/26 20:26:09 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_closest_b(t_var *stack_info)
{
	int	i;
	int	first;
	int	first_flag;
	int	last;

	i = 0;
	first_flag = 0;
	while (i <= stack_info->atop)
	{
		if (stack_info->a_stack[i] <= stack_info
			->sorted_stack[stack_info->sorted_chunk])
		{
			if (!first_flag)
				first = i;
			first_flag = 1;
			last = i;
		}
		i++;
	}
	if (!first_flag)
		return (-1);
	if (stack_info->atop - last <= first + 1)
		return (last);
	else
		return (first);
}

// static void	check_shortest_b(t_var *stack_info, int *b_val, int a_index)
// {
// 	int			a_steps;
// 	int			b_steps;
// 	int			n;
// 	int			old;

// 	n = stack_info->atop;
// 	old = a_index;
// 	a_steps = 0;
// 	b_steps = 0;
// 	sort_b(stack_info, a_index);
// 	if (stack_info->atop - a_index <= a_index)
// 	{
// 		a_steps = stack_info->atop - a_index;
// 		if (stack_info->btop - stack_info->index <= stack_info->index && stack_info->btop - stack_info->index >= n - old)
// 			b_steps = (stack_info->btop - stack_info->index) - (n - old);
// 		// b_steps = stack_info->btop - stack_info->index;
// 		else if (stack_info->btop - (n - old) - 1 > 0 && stack_info->btop - (n - old) - 1 < stack_info->index + 1)
// 			b_steps = stack_info->btop - (n - old) - 1;
// 	}
// 	else
// 	{
// 		a_steps = a_index + 1;
// 		if (stack_info->btop - stack_info->index > stack_info->index && stack_info->index > old)
// 			b_steps = stack_info->index - old;
// 		else if (stack_info->index - old > 0 && stack_info->index - old < stack_info->btop - stack_info->index)
// 			b_steps = stack_info->index - old;
// 	}
// 	if (a_steps + b_steps <= stack_info->total || !stack_info->total)
// 	{
// 		stack_info->total = a_steps + b_steps;
// 		*b_val = a_index;
// 	}
// }

// int	get_closest_b(t_var *stack_info)
// {
// 	int	i;
// 	int	first_flag;
// 	int	b_val;

// 	i = 0;
// 	stack_info->total = 0;
// 	first_flag = 0;
// 	while (i <= stack_info->atop)
// 	{
// 		if (stack_info->a_stack[i] <= stack_info
// 			->sorted_stack[stack_info->sorted_chunk])
// 		{
// 			first_flag = 1;
// 			check_shortest_b(stack_info, &b_val, i);
// 		}
// 		i++;
// 	}
// 	if (!first_flag)
// 		return (-1);
// 	return (b_val);
// }

int	go_to_closest_b(t_var *stack_info)
{
	int	b_val;

	b_val = get_closest_b(stack_info);
	if (b_val == -1)
		return (0);
	// sort_b(stack_info);
	rotate_to(stack_info, 'a', b_val, stack_info->atop);
	return (1);
}

// void	sort_b(t_var *stack_info)
// {
// 	int	i;
// 	int	index;

// 	i = 0;
// 	index = 0;
// 	while (i <= stack_info->btop)
// 	{
// 		if (stack_info->b_stack[i] == stack_info->sorted_stack[stack_info
// 				->atop + 1])
// 			index = i;
// 		i++;
// 	}
// 	rotate_to(stack_info, 'b', index, stack_info->btop);
// }

void	sort_b(t_var *stack_info, int a_index)
{
	int	i;
	int	index;

	i = 0;
	index = stack_info->btop;
	if (a_index < 0)
		return ;
	while (i < stack_info->btop)
	{
		if ((stack_info->a_stack[a_index] > stack_info->b_stack[i]
				&& (stack_info->a_stack[a_index] < stack_info
					->b_stack[i + 1]))
			|| ((stack_info->a_stack[a_index] < stack_info
					->b_stack[i + 1] || stack_info->a_stack[a_index]
					> stack_info->b_stack[i]) && stack_info->b_stack[i]
				> stack_info->b_stack[i + 1]))
			index = i;
		i++;
	}
	stack_info->index = index;
	// rotate_to(stack_info, 'b', index, stack_info->btop);
}

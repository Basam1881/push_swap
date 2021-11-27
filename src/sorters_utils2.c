/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 08:34:00 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 18:58:37 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_shortest_a(t_var *stack_info, int *a_val, int b_index)
{
	int			a_steps;
	int			b_steps;

	a_steps = 0;
	b_steps = 0;
	sort_a(stack_info, b_index);
	if (stack_info->btop - b_index <= b_index)
		b_steps = stack_info->btop - b_index;
	else
		b_steps = b_index + 1;
	if (stack_info->atop - stack_info->a_index <= stack_info->a_index)
		a_steps = stack_info->atop - stack_info->a_index;
	else
		a_steps = stack_info->a_index;
	if (a_steps + b_steps <= stack_info->total || !stack_info->total)
	{
		stack_info->total = a_steps + b_steps;
		*a_val = b_index;
	}
}

void	get_closest_a(t_var *stack_info)
{
	int	i;
	int	a_val;

	i = 0;
	stack_info->total = 0;
	a_val = stack_info->btop;
	while (i <= stack_info->btop)
	{
		sort_a(stack_info, i);
		check_shortest_a(stack_info, &a_val, i);
		i++;
	}
	stack_info->b_index = a_val;
}

int	go_to_closest_b(t_var *stack_info)
{
	int	b_val;

	b_val = get_closest_b(stack_info);
	if (b_val == -1)
		return (0);
	rotate_to(stack_info, 'a', b_val, stack_info->atop);
	return (1);
}

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
}

void	sort_a(t_var *stack_info, int b_index)
{
	int	i;
	int	index;

	i = 0;
	index = stack_info->atop;
	if (b_index < 0)
		return ;
	while (i < stack_info->atop)
	{
		if ((stack_info->b_stack[b_index] < stack_info->a_stack[i]
				&& (stack_info->b_stack[b_index] > stack_info
					->a_stack[i + 1]))
			|| ((stack_info->b_stack[b_index] > stack_info
					->a_stack[i + 1] || stack_info->b_stack[b_index]
					< stack_info->a_stack[i]) && stack_info->a_stack[i]
				< stack_info->a_stack[i + 1]))
			index = i;
		i++;
	}
	stack_info->a_index = index;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 02:34:43 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/18 03:00:54 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	get_median(t_var *stack_info)
// {
// 	stack_info->sorted_median = stack_info->sorted_top / 2;
// }

int	is_a_sorted(t_var *stack_info)
{
	int	i;

	i = 1;
	while (i <= stack_info->atop)
	{
		if (stack_info->a_stack[i - 1] < stack_info->a_stack[i])
			return (0);
		i++;
	}
	return (1);
}

static void	primary_sort_helper(t_var *stack_info, int *i, int *n, int *n_index)
{
	int	tmp;

	tmp = stack_info->sorted_stack[*i];
	stack_info->sorted_stack[(*i)++] = *n;
	stack_info->sorted_stack[*n_index] = tmp;
}

void	primary_sort(t_var *stack_info)
{
	int	i;
	int	j;
	int	n;
	int	n_index;

	i = 0;
	while (i <= stack_info->sorted_top)
	{
		j = i + 1;
		n = stack_info->sorted_stack[i];
		n_index = i;
		while (j <= stack_info->sorted_top)
		{
			if (n < stack_info->sorted_stack[j])
			{
				n = stack_info->sorted_stack[j];
				n_index = j;
			}
			if (stack_info->sorted_stack[i] == stack_info->sorted_stack[j])
				error();
			j++;
		}
		primary_sort_helper(stack_info, &i, &n, &n_index);
	}
	stack_info->sorted_median = stack_info->sorted_top / 2;
}

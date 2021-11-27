/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 02:34:43 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 18:58:20 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	select_chuck(t_var *stack_info)
{
	if (stack_info->sorted_top < 100)
		stack_info->num = CHUNK_NUM;
	else
		stack_info->num = BIG_CHUNK_NUM;
	stack_info->sorted_chunk = stack_info->sorted_top / stack_info->num;
	stack_info->chunk_size = stack_info->sorted_chunk + 1;
	stack_info->sorted_chunk = stack_info->sorted_top - stack_info->chunk_size;
}

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

static void	primary_sort_helper1(t_var *stack_info, int *i,
	int *n, int *n_index)
{
	int	tmp;

	tmp = stack_info->sorted_stack[*i];
	stack_info->sorted_stack[(*i)++] = *n;
	stack_info->sorted_stack[*n_index] = tmp;
}

static void	primary_sort_helper2(t_var *stack_info, int *j,
	int *n, int *n_index)
{
	if (*n < stack_info->sorted_stack[*j])
	{
		*n = stack_info->sorted_stack[*j];
		*n_index = *j;
	}
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
			primary_sort_helper2(stack_info, &j, &n, &n_index);
			if (i >= 0 && stack_info->sorted_stack[i] == stack_info
				->sorted_stack[j])
				error(stack_info);
			j++;
		}
		primary_sort_helper1(stack_info, &i, &n, &n_index);
	}
	select_chuck(stack_info);
}

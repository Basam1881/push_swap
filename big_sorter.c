/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 08:58:54 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/26 16:46:08 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sorter(t_var *stack_info)
{
	// int i = 0;
	while (stack_info->atop > 4)
	{
		while (go_to_closest_b(stack_info))
		{
			// printf("atop: %d\n", stack_info->a_stack[stack_info->atop]);
			// sort_b(stack_info, get_closest_b(stack_info));
			sort_b(stack_info, stack_info->atop);
			rotate_to(stack_info, 'b', stack_info->index, stack_info->btop);
			push(stack_info, 'b');
			// if (stack_info->atop <= 46)
			// 	return ;
			// if (stack_info->atop <= 4)
			// 	break ;
		}
		// if (i == 1)
		// 	return ;
		// i++;
		if (stack_info->atop <= 4)
		{
			solver(stack_info);
			break ;
		}
		// exit (0);
		// if (stack_info->sorted_chunk >= stack_info->chunk_size * 2 - 1)
		// 	stack_info->sorted_chunk -= stack_info->chunk_size;
		// else if (stack_info->sorted_chunk >= stack_info->chunk_size - 1)
		// 	stack_info->sorted_chunk += 6 - stack_info->chunk_size;
		if (stack_info->sorted_chunk <= stack_info->chunk_size)
			stack_info->sorted_chunk = 5;
		else
			stack_info->sorted_chunk -= stack_info->chunk_size;
	}
	sort_by_size(stack_info, 'b');
	// exit (0);
	if (stack_info->atop >= 0)
		solver (stack_info);
	while (stack_info->btop >= 0)
		push(stack_info, 'a');
	// if (final_ckeck(stack_info, 'a'))
	// {
	// 	printf("OK");
	// }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:21:36 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/17 20:33:45 by bnaji            ###   ########.fr       */
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

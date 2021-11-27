/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 01:17:59 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 21:41:42 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	final_ckeck(t_var *stack_info)
{
	int	i;

	i = 0;
	while (i <= stack_info->sorted_top)
	{
		if (stack_info->a_stack[i] < stack_info->sorted_stack[i])
			return (0);
		i++;
	}
	if (stack_info->btop != -1)
		return (0);
	return (1);
}

int	check_for_operation(t_var *stack_info, char **m)
{
	if (!ft_strcmp(*m, "sa\n"))
		swap(stack_info, 'a', 1);
	else if (!ft_strcmp(*m, "sb\n"))
		swap(stack_info, 'b', 1);
	else if (!ft_strcmp(*m, "ss\n"))
		swap(stack_info, 's', 1);
	else if (!ft_strcmp(*m, "pa\n"))
		push(stack_info, 'a', 1);
	else if (!ft_strcmp(*m, "pb\n"))
		push(stack_info, 'b', 1);
	else if (!ft_strcmp(*m, "ra\n"))
		rotate(stack_info, 'a', 1);
	else if (!ft_strcmp(*m, "rb\n"))
		rotate(stack_info, 'b', 1);
	else if (!ft_strcmp(*m, "rr\n"))
		rotate(stack_info, 'r', 1);
	else if (!ft_strcmp(*m, "rra\n"))
		rev_rotate(stack_info, 'a', 1);
	else if (!ft_strcmp(*m, "rrb\n"))
		rev_rotate(stack_info, 'b', 1);
	else if (!ft_strcmp(*m, "rrr\n"))
		rev_rotate(stack_info, 'r', 1);
	else
		error(stack_info);
	return (1);
}

void	read_operations(t_var *stack_info)
{
	char	*m;

	while (1)
	{
		m = get_next_line(0);
		if (!m)
			break ;
		if (!(check_for_operation(stack_info, &m)))
			;
	}
	if (final_ckeck(stack_info))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_var	stack_info;

	if (ac == 1)
		return (0);
	else if (ac == 2)
		double_check_arg(&stack_info, av[1]);
	else
		initialize(&stack_info, av + 1);
	primary_sort(&stack_info);
	read_operations(&stack_info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 02:05:55 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/23 17:41:34 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	solver(&stack_info);
	// print_a(&stack_info);
	return (0);
}

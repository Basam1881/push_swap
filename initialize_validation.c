/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:12:47 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/18 00:40:20 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_var *stack_info, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
		i++;
	stack_info->sorted_stack = (int *)malloc(sizeof(int) * i);
	stack_info->a_stack = (int *)malloc(sizeof(int) * i);
	stack_info->b_stack = (int *)malloc(sizeof(int) * i);
	if (!stack_info->sorted_stack || !stack_info->a_stack
		|| !stack_info->b_stack)
		error();
	j = 0;
	i--;
	while (i >= 0)
	{
		stack_info->sorted_stack[j] = armored_atoi(av[i]);
		stack_info->a_stack[j++] = armored_atoi(av[i--]);
	}
	stack_info->atop = j - 1;
	stack_info->btop = -1;
	stack_info->sorted_top = j - 1;
}

void	double_check_arg(t_var *stack_info, char *str)
{
	int		i;
	char	**args;

	args = ft_split(str, ' ');
	initialize(stack_info, args);
	i = 0;
	while (args[i])
	{
		free (args[i]);
		i++;
	}
	free(args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 02:14:10 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/18 02:49:52 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_var
{
	int	*sorted_stack;
	int	*a_stack;
	int	*b_stack;
	int	atop;
	int	btop;
	int	sorted_top;
	int	sorted_median;
}				t_var;

void	error(void);
int		armored_atoi(const char *str);
void	swap(t_var *stack_info, char c);
void	push(t_var *stack_info, char c);
void	rotate(t_var *stack_info, char c);
void	rev_rotate(t_var *stack_info, char c);
void	solver(t_var *stack_info);
void	double_check_arg(t_var *stack_info, char *str);
void	initialize(t_var *stack_info, char **av);
void	primary_sort(t_var *stack_info);
int		is_a_sorted(t_var *stack_info);
void	rotate_helper(t_var *stack_info, int a, int s);
void	rev_rotate_helper(t_var *stack_info, int a, int s);
void	sort_2(t_var *stack_info);
void	sort_3(t_var *stack_info);
void	sort_4(t_var *stack_info);
void	sort_5(t_var *stack_info);

#endif

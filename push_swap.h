/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 02:14:10 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/26 13:55:52 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# define MEDIAN_CHUNK 2
# define CHUNK_NUM 6
# define BIG_CHUNK_NUM 14

typedef struct s_var
{
	int	*sorted_stack;
	int	*a_stack;
	int	*b_stack;
	int	atop;
	int	btop;
	int	sorted_top;
	int	sorted_chunk;
	int	chunk_size;
	int	index;
	int	total;
	int	a_index;
	int	num;
}				t_var;

void	print_a(t_var *stack_info);
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
void	rotate_to(t_var *stack_info, char c, int old, int n);
void	swap_up(t_var *stack_info, char c);
void	swap_down(t_var *stack_info, char c);
int		get_closest_b(t_var *stack_info);
int		go_to_closest_b(t_var *stack_info);
void	sort_b(t_var *stack_info, int a_index);
void	sort_by_size(t_var *stack_info, char c);
int		final_ckeck(t_var *stack_info, char c);
void	sort_2(t_var *stack_info);
void	sort_3(t_var *stack_info);
void	sort_4(t_var *stack_info);
void	sort_5(t_var *stack_info);
void	big_sorter(t_var *stack_info);

#endif

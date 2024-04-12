/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate_small.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:31:59 by tcharpen          #+#    #+#             */
/*   Updated: 2022/02/20 18:32:02 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_rra(int *stack_a, int size_stack_a)
{
	unsigned int	i_stack_a;
	int				tmp;

	i_stack_a = size_stack_a - 1;
	tmp = stack_a[size_stack_a - 1];
	while (i_stack_a > 0)
	{
		stack_a[i_stack_a] = stack_a[i_stack_a - 1];
		i_stack_a--;
	}
	stack_a[i_stack_a] = tmp;
	ft_putstr_fd("rra\n", 1);
}

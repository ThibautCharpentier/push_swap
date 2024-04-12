/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:59:40 by tcharpen          #+#    #+#             */
/*   Updated: 2022/02/20 17:59:43 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_ra(int *stack_a, int size_stack_a)
{
	int	i_stack_a;
	int	tmp;

	i_stack_a = 0;
	tmp = stack_a[0];
	while (i_stack_a < size_stack_a - 1)
	{
		stack_a[i_stack_a] = stack_a[i_stack_a + 1];
		i_stack_a++;
	}
	stack_a[i_stack_a] = tmp;
	ft_putstr_fd("ra\n", 1);
}

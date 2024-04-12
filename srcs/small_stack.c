/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:28:55 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:28:56 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size_three(int *stack_a)
{
	if (stack_a[0] > stack_a[1] && stack_a[0] < stack_a[2])
		ft_swap_sa(stack_a, 3);
	else if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2]
		&& stack_a[1] > stack_a[2])
	{
		ft_swap_sa(stack_a, 3);
		ft_reverse_rotate_rra(stack_a, 3);
	}
	else if (stack_a[0] > stack_a[1] && stack_a[0] > stack_a[2]
		&& stack_a[1] < stack_a[2])
		ft_rotate_ra(stack_a, 3);
	else if (stack_a[0] < stack_a[1] && stack_a[0] < stack_a[2]
		&& stack_a[1] > stack_a[2])
	{
		ft_swap_sa(stack_a, 3);
		ft_rotate_ra(stack_a, 3);
	}
	else if (stack_a[0] < stack_a[1] && stack_a[0] > stack_a[2])
		ft_reverse_rotate_rra(stack_a, 3);
}

int	ft_sort_small_stack(int *stack_a, int size_stack_a)
{
	if (size_stack_a == 2)
		ft_swap_sa(stack_a, size_stack_a);
	else if (size_stack_a == 3)
		ft_size_three(stack_a);
	else if (size_stack_a == 4)
		stack_a = ft_size_four(stack_a);
	else
		stack_a = ft_size_five(stack_a);
	if (!stack_a)
		return (0);
	free(stack_a);
	return (1);
}

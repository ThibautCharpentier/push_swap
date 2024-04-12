/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_size_four.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:29:25 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:29:26 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_resolve_size_four(int *stack_a)
{
	if (stack_a[0] > stack_a[3])
		ft_rotate_ra(stack_a, 4);
	else if (stack_a[0] > stack_a[2])
	{
		ft_reverse_rotate_rra(stack_a, 4);
		ft_swap_sa(stack_a, 4);
		ft_rotate_ra(stack_a, 4);
		ft_rotate_ra(stack_a, 4);
	}
	else if (stack_a[0] > stack_a[1])
		ft_swap_sa(stack_a, 4);
}

int	*ft_size_four(int *stack_a)
{
	int	element;
	int	*stack_b;

	element = stack_a[0];
	stack_a = ft_push_del_pb(stack_a, 4);
	stack_b = ft_push_add(0, 0, element);
	if (!stack_a || !stack_b)
		return (ft_free_stack(stack_a, stack_b));
	ft_size_three(stack_a);
	element = stack_b[0];
	stack_b = ft_push_del_pa(stack_b, 1);
	stack_a = ft_push_add(stack_a, 3, element);
	if (!stack_a || !stack_b)
		return (ft_free_stack(stack_a, stack_b));
	ft_resolve_size_four(stack_a);
	free(stack_b);
	return (stack_a);
}

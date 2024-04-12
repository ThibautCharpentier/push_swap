/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:27:03 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:27:05 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_move_stacks_two(int *stack_a, int s_a, int *stack_b, int s_b)
{
	int	element;

	while (s_b > 0)
	{
		element = stack_b[0];
		stack_b = ft_push_del_big(stack_b, s_b--, "pa");
		stack_a = ft_push_add_big(stack_a, s_a++, element);
		if (!stack_a || !stack_b)
			return (ft_free_stack(stack_a, stack_b));
	}
	free(stack_b);
	return (stack_a);
}

static int	*ft_move_stacks(int *stack_a, int size_a, int i_bits)
{
	int	i_stack;
	int	element;
	int	size_a_tmp;
	int	*stack_b;
	int	size_b;

	i_stack = -1;
	size_a_tmp = size_a;
	size_b = 0;
	stack_b = 0;
	while (++i_stack < size_a)
	{
		if ((stack_a[0] >> i_bits) & 1)
			ft_rotate_ra_big(stack_a);
		else
		{
			element = stack_a[0];
			stack_a = ft_push_del_big(stack_a, size_a_tmp--, "pb");
			stack_b = ft_push_add_big(stack_b, size_b++, element);
			if (!stack_a || !stack_b)
				return (ft_free_stack(stack_a, stack_b));
		}
	}
	stack_a = ft_move_stacks_two(stack_a, size_a_tmp, stack_b, size_b);
	return (check_stack_a(stack_a));
}

static int	ft_resolve_big_stack(int *stack_a, int size_stack_a, int max_bits)
{
	int	i_bits;

	i_bits = -1;
	while (++i_bits < max_bits)
	{
		stack_a = ft_move_stacks(stack_a, size_stack_a, i_bits);
		if (!stack_a)
			return (0);
	}
	free(stack_a);
	return (1);
}

int	ft_sort_big_stack(int *stack_a, int size_stack_a)
{
	int	max_bits;

	stack_a = ft_simplify_stack(stack_a, size_stack_a);
	if (!stack_a)
		return (0);
	max_bits = 0;
	while (((size_stack_a - 1) >> max_bits))
		max_bits++;
	if (!ft_resolve_big_stack(stack_a, size_stack_a, max_bits))
		return (0);
	return (1);
}

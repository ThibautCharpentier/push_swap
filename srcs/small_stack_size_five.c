/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_size_five.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:29:37 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:29:39 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	ft_position_smaller_element(int *stack_a)
{
	int				smaller_element;
	unsigned int	i_stack_a;
	unsigned int	position_smaller;

	smaller_element = stack_a[0];
	position_smaller = 0;
	i_stack_a = 1;
	while (i_stack_a < 5)
	{
		if (smaller_element > stack_a[i_stack_a])
		{
			smaller_element = stack_a[i_stack_a];
			position_smaller = i_stack_a;
		}
		i_stack_a++;
	}
	return (position_smaller);
}

static void	ft_rotate_stack(int *stack_a)
{
	unsigned int	i_smaller_element;
	unsigned int	count;

	i_smaller_element = ft_position_smaller_element(stack_a);
	if (i_smaller_element <= 2)
	{
		count = 0;
		while (count < i_smaller_element)
		{
			ft_rotate_ra(stack_a, 5);
			count++;
		}
	}
	else
	{
		count = 5;
		while (count > i_smaller_element)
		{
			ft_reverse_rotate_rra(stack_a, 5);
			count--;
		}
	}
}

int	*ft_size_five(int *stack_a)
{
	int	element;
	int	*stack_b;

	ft_rotate_stack(stack_a);
	element = stack_a[0];
	stack_a = ft_push_del_pb(stack_a, 5);
	stack_b = ft_push_add(0, 0, element);
	if (!stack_a || !stack_b)
		return (ft_free_stack(stack_a, stack_b));
	stack_a = ft_size_four(stack_a);
	if (!stack_a)
		return (ft_free_stack(stack_a, stack_b));
	element = stack_b[0];
	stack_b = ft_push_del_pa(stack_b, 1);
	stack_a = ft_push_add(stack_a, 4, element);
	if (!stack_a || !stack_b)
		return (ft_free_stack(stack_a, stack_b));
	free(stack_b);
	return (stack_a);
}

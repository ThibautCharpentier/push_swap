/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:17:42 by tcharpen          #+#    #+#             */
/*   Updated: 2022/02/20 16:17:44 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_push_del_pa(int *stack_b, int size_stack_b)
{
	int	*new_stack_b;
	int	i_stack_b;

	ft_putstr_fd("pa\n", 1);
	if (size_stack_b == 0 || size_stack_b == 1)
		return (stack_b);
	new_stack_b = malloc(sizeof(int) * (size_stack_b - 1));
	if (!new_stack_b)
	{
		free(stack_b);
		return (0);
	}
	i_stack_b = 0;
	while (i_stack_b < size_stack_b - 1)
	{
		new_stack_b[i_stack_b] = stack_b[i_stack_b + 1];
		i_stack_b++;
	}
	free(stack_b);
	return (new_stack_b);
}

int	*ft_push_del_pb(int *stack_a, int size_stack_a)
{
	int	*new_stack_a;
	int	i_stack_a;

	ft_putstr_fd("pb\n", 1);
	if (size_stack_a == 0 || size_stack_a == 1)
		return (stack_a);
	new_stack_a = malloc(sizeof(int) * (size_stack_a - 1));
	if (!new_stack_a)
	{
		free(stack_a);
		return (0);
	}
	i_stack_a = 0;
	while (i_stack_a < size_stack_a - 1)
	{
		new_stack_a[i_stack_a] = stack_a[i_stack_a + 1];
		i_stack_a++;
	}
	free(stack_a);
	return (new_stack_a);
}

int	*ft_push_add(int *stack, int size_stack, int element)
{
	int	*new_stack;
	int	i_stack;

	new_stack = malloc(sizeof(int) * (size_stack + 1));
	if (!new_stack)
	{
		free(stack);
		return (0);
	}
	new_stack[0] = element;
	i_stack = 1;
	while (i_stack < size_stack + 1)
	{
		new_stack[i_stack] = stack[i_stack - 1];
		i_stack++;
	}
	free(stack);
	return (new_stack);
}

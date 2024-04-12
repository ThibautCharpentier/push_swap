/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_big_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:28:31 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:28:35 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	ft_search_i_min(int *stack, int size_stack)
{
	int				i_stack;
	int				min_stack;
	unsigned int	i_min_stack;
	static long		old_min_stack = -2147483649;

	i_stack = 0;
	while (stack[i_stack] <= old_min_stack)
		i_stack++;
	min_stack = stack[i_stack];
	i_min_stack = i_stack;
	while (++i_stack < size_stack)
	{
		if (min_stack > stack[i_stack] && stack[i_stack] > old_min_stack)
		{
			min_stack = stack[i_stack];
			i_min_stack = i_stack;
		}
	}
	old_min_stack = (long) min_stack;
	return (i_min_stack);
}

int	*ft_simplify_stack(int *stack, int size_stack)
{
	unsigned int	i_min_stack;
	int				*new_stack;
	int				new_number;

	new_stack = malloc(sizeof(int) * (size_stack + 1));
	if (!new_stack)
		return (ft_free_stack(stack, 0));
	new_number = 0;
	while (new_number < size_stack)
	{
		i_min_stack = ft_search_i_min(stack, size_stack);
		new_stack[i_min_stack] = new_number;
		new_number++;
	}
	new_stack[size_stack] = -1;
	free(stack);
	return (new_stack);
}

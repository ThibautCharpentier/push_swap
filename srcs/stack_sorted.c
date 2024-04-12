/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:29:52 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:29:53 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(int *stack, int size_stack)
{
	int	i_stack;

	i_stack = 0;
	while (i_stack < size_stack - 1)
	{
		if (stack[i_stack] > stack[i_stack + 1])
			return (0);
		i_stack++;
	}
	free(stack);
	return (1);
}

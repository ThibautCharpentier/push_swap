/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:28:13 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:28:13 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_push_del_big(int *stack, int size_stack, char *action)
{
	int	*new_stack;
	int	i_stack;

	ft_printf("%s\n", action);
	new_stack = malloc(sizeof(int) * (size_stack + 1));
	if (!new_stack)
	{
		free(stack);
		return (0);
	}
	i_stack = 0;
	while (i_stack < size_stack - 1)
	{
		new_stack[i_stack] = stack[i_stack + 1];
		i_stack++;
	}
	new_stack[i_stack] = -1;
	free(stack);
	return (new_stack);
}

int	*ft_push_add_big(int *stack, int size_stack, int element)
{
	int	*new_stack;
	int	i_stack;

	new_stack = malloc(sizeof(int) * (size_stack + 2));
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
	new_stack[i_stack] = -1;
	free(stack);
	return (new_stack);
}

void	ft_rotate_ra_big(int *stack_a)
{
	unsigned int	i_stack_a;
	int				tmp;

	i_stack_a = 0;
	tmp = stack_a[0];
	while (stack_a[i_stack_a + 1] != -1)
	{
		stack_a[i_stack_a] = stack_a[i_stack_a + 1];
		i_stack_a++;
	}
	stack_a[i_stack_a] = tmp;
	ft_putstr_fd("ra\n", 1);
}

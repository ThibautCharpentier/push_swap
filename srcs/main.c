/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:26:47 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:26:50 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error(char **parameters)
{
	int	i_param;

	if (parameters)
	{
		i_param = -1;
		while (parameters[++i_param])
			free(parameters[i_param]);
		free(parameters);
	}
	ft_putstr_fd("Error\n", 2);
	return (0);
}

static int	ft_free_parameters(char **parameters)
{
	int	i_param;

	i_param = -1;
	while (parameters[++i_param])
		free(parameters[i_param]);
	free(parameters);
	return (0);
}

static int	ft_paramlen(char **parameters)
{
	int	i_param;
	int	size_param;

	i_param = -1;
	size_param = 0;
	while (parameters[++i_param])
		size_param++;
	return (size_param);
}

int	main(int argc, char **argv)
{
	int		*tab;
	char	**param;

	if (argc == 1)
		return (0);
	param = ft_separate_parameters(argv + 1);
	if (!param)
		return (ft_error(NULL));
	tab = ft_check_parameters(param, ft_paramlen(param));
	if (!tab)
		return (ft_error(param));
	if (ft_is_sorted(tab, ft_paramlen(param)))
		return (ft_free_parameters(param));
	if (ft_paramlen(param) < 6)
	{
		if (!ft_sort_small_stack(tab, ft_paramlen(param)))
			return (ft_error(param));
	}
	else
	{
		if (!ft_sort_big_stack(tab, ft_paramlen(param)))
			return (ft_error(param));
	}
	ft_free_parameters(param);
	return (0);
}

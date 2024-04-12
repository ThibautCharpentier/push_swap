/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:00:22 by tcharpen          #+#    #+#             */
/*   Updated: 2022/02/18 15:00:25 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_long(const char *nptr)
{
	unsigned int	i;
	long			sign;
	unsigned long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	ft_is_integer(char *param)
{
	unsigned int	i_param;
	long			param_number;

	i_param = 0;
	while (param[i_param])
	{
		if (!ft_isdigit(param[i_param]) && i_param != 0)
			return (0);
		else if (i_param == 0 && !ft_isdigit(param[i_param])
			&& param[i_param] != '+' && param[i_param] != '-')
			return (0);
		i_param++;
	}
	if (i_param == 0)
		return (0);
	param_number = ft_atoi_long(param);
	if (param_number > -2147483649 && param_number < 2147483648)
		return (1);
	return (0);
}

static int	ft_are_uniques(int *tab_param, unsigned int size_tab_param)
{
	unsigned int	i_tab_param;
	unsigned int	j_tab_param;

	i_tab_param = 0;
	while (i_tab_param < size_tab_param - 1)
	{
		j_tab_param = i_tab_param + 1;
		while (j_tab_param < size_tab_param)
		{
			if (tab_param[i_tab_param] == tab_param[j_tab_param])
				return (0);
			j_tab_param++;
		}
		i_tab_param++;
	}
	return (1);
}

static int	*ft_free_tab_int(int *tab_param)
{
	free(tab_param);
	return (0);
}

int	*ft_check_parameters(char **parameters, int nb_param)
{
	int				i_param;
	unsigned int	i_tab_param;
	unsigned int	size_tab_param;
	int				*tab_param;

	i_param = 0;
	while (parameters[i_param])
		i_param++;
	if (i_param != nb_param)
		return (0);
	tab_param = malloc(sizeof(int) * nb_param);
	if (!tab_param)
		return (0);
	size_tab_param = i_param;
	i_param = 0;
	i_tab_param = 0;
	while (parameters[i_param])
	{
		if (!ft_is_integer(parameters[i_param]))
			return (ft_free_tab_int(tab_param));
		tab_param[i_tab_param++] = ft_atoi(parameters[i_param++]);
	}
	if (!ft_are_uniques(tab_param, size_tab_param))
		return (ft_free_tab_int(tab_param));
	return (tab_param);
}

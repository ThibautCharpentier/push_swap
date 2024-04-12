/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:15:14 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/26 15:15:16 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\v')
		return (1);
	return (0);
}

static int	ft_find_size_param(char **argv)
{
	int	size_param;
	int	i_par;
	int	j_par;

	i_par = -1;
	size_param = 0;
	while (argv[++i_par])
	{
		j_par = 0;
		if (argv[i_par][0] && !ft_is_space(argv[i_par][0]))
			size_param++;
		while (argv[i_par][j_par])
		{
			if (argv[i_par][j_par] == ' ' && argv[i_par][j_par + 1]
				&& !ft_is_space(argv[i_par][j_par + 1]))
				size_param++;
			j_par++;
		}
	}
	return (size_param);
}

static char	**ft_free_parameters(char **parameters)
{
	int	i_param;

	i_param = -1;
	while (parameters[++i_param])
		free(parameters[i_param]);
	free(parameters);
	return (NULL);
}

static int	ft_add_param(char **param, char *argv, int i_param, int i_argv)
{
	int	j_param;
	int	i_argv_tmp;
	int	j_argv;

	while (argv[i_argv])
	{
		while (argv[i_argv] && ft_is_space(argv[i_argv]))
			i_argv++;
		i_argv_tmp = i_argv;
		while (argv[i_argv] && !ft_is_space(argv[i_argv]))
			i_argv++;
		if (i_argv != i_argv_tmp)
		{
			param[i_param] = malloc(sizeof(char) * (i_argv - i_argv_tmp + 1));
			if (!param[i_param])
				return (-1);
			param[i_param][i_argv - i_argv_tmp] = 0;
			j_param = 0;
			j_argv = i_argv_tmp;
			while (j_param < i_argv - i_argv_tmp)
				param[i_param][j_param++] = argv[j_argv++];
			i_param++;
		}
	}
	return (i_param);
}

char	**ft_separate_parameters(char **argv)
{
	int		size_param;
	char	**param;
	int		i_param;
	int		i_argv;
	int		add_param;

	size_param = ft_find_size_param(argv);
	param = malloc(sizeof(char *) * (size_param + 1));
	if (!param)
		return (NULL);
	i_param = 0;
	i_argv = 0;
	while (i_param < size_param)
	{
		add_param = ft_add_param(param, argv[i_argv], i_param, 0);
		if (add_param - i_param < 0)
			return (ft_free_parameters(param));
		if (add_param - i_param > 0)
			i_param = add_param;
		i_argv++;
	}
	param[i_param] = 0;
	return (param);
}

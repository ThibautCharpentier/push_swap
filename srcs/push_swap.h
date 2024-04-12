/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:27:34 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/02 17:27:36 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

int		ft_sort_big_stack(int *stack_a, int size_stack_a);
int		*ft_check_parameters(char **parameters, int nb_param);
int		*ft_free_stack(int *stack_a, int *stack_b);
int		*check_stack_a(int *stack_a);
int		*ft_push_del_big(int *stack, int size_stack, char *action);
int		*ft_push_add_big(int *stack, int size_stack, int element);
void	ft_rotate_ra_big(int *stack_a);
int		*ft_push_del_pa(int *stack_b, int size_stack_b);
int		*ft_push_del_pb(int *stack_a, int size_stack_a);
int		*ft_push_add(int *stack, int size_stack, int element);
void	ft_reverse_rotate_rra(int *stack_a, int size_stack_a);
void	ft_rotate_ra(int *stack_a, int size_stack_a);
void	ft_swap_sa(int *stack_a, int size_stack_a);
char	**ft_separate_parameters(char **argv);
int		*ft_simplify_stack(int *stack, int size_stack);
int		*ft_size_five(int *stack_a);
int		*ft_size_four(int *stack_a);
int		ft_sort_small_stack(int *stack_a, int size_stack_a);
void	ft_size_three(int *stack_a);
int		ft_is_sorted(int *stack, int size_stack);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:02:39 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 16:41:13 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_sort_last_param(int **tab_a, int **tab_b, int size, t_st *ps)
{
	if (ps->a_len >= 2 && (*tab_a)[0] > ps->med && (*tab_a)[1] <=
			ps->med && !ft_check_next_dig_a(tab_a, ps->med, size, 2))
	{
		if (ps->b_len >= 2 && (*tab_b)[0] < (*tab_b)[1] &&
				(*tab_a)[0] > (*tab_a)[1])
			ft_swap_both(tab_a, tab_b, ps);
		else
			ft_swap_first_a(tab_a, tab_b, ps, 1);
		if (!((*tab_a)[0] >= (*tab_b)[0] && (*tab_a)[0] >=
					(*tab_b)[1] && (size_t)size == ps->a_len))
			return (ft_put_dig_in_b(tab_a, tab_b, ps));
		return (2);
	}
	return (0);
}

int		ft_sort_less_6(int **tab_a, int **tab_b, size_t size, t_st *ps)
{
	size_t	i;
	size_t	res;

	res = 0;
	i = 0;
	while (1)
	{
		if (!ft_check_next_dig_a(tab_a, ps->med, size, 0))
			break ;
		if (res >= 2 && (*tab_b)[0] < (*tab_b)[1] && (*tab_a)[0] > (*tab_a)[1])
			ft_swap_both(tab_a, tab_b, ps);
		else if (res >= 2 && (*tab_b)[0] < (*tab_b)[1] && (ps->b_len != res))
			ft_swap_first_b(tab_b, tab_a, ps, 2);
		else if ((*tab_a)[0] <= ps->med && ++res && --size)
			ft_put_dig_in_b(tab_a, tab_b, ps);
		else if ((i = ft_sort_last_param(tab_a, tab_b, size, ps)))
		{
			i == 1 ? ++res : 0;
			break ;
		}
		else if (size == ps->a_len || ++ps->rot)
			ft_rotate_a(tab_a, tab_b, ps, 1);
	}
	return (res);
}

int		ft_check_next_dig_b(int **tab_a, int med, int size, int fl)
{
	int i;

	fl = fl - 1;
	i = 0;
	while (i < size)
		if ((*tab_a)[i++] > med)
			return (1);
	return (0);
}

int		ft_sort_last_param_b(int **tab_a, int **tab_b, int size, t_st *ps)
{
	if ((*tab_a)[0] <= ps->med && (*tab_a)[1] > ps->med
			&& !ft_check_next_dig_b(tab_a, ps->med, size, 0))
	{
		if ((*tab_b)[0] > (*tab_b)[1] && (*tab_a)[0] < (*tab_a)[1])
			ft_swap_both(tab_a, tab_b, ps);
		else
			ft_swap_first_b(tab_a, tab_b, ps, 2);
		ft_put_dig_in_a(tab_a, tab_b, ps);
		return (1);
	}
	return (0);
}

int		ft_sort_less_6_b(int **tab_a, int **tab_b, int size, t_st *ps)
{
	int	i;
	int	res;
	int	tmp;

	tmp = ps->b_len;
	res = 0;
	i = -1;
	while (1)
	{
		if (!ft_check_next_dig_b(tab_a, ps->med, size - res, 0))
			break ;
		if (res >= 2 && (*tab_b)[0] > (*tab_b)[1] && (*tab_a)[0] < (*tab_a)[1])
			ft_swap_both(tab_a, tab_b, ps);
		else if (res >= 2 && (*tab_b)[0] > (*tab_b)[1])
			ft_swap_first_a(tab_b, tab_a, ps, 1);
		else if ((*tab_a)[0] > ps->med && ++res)
			ft_put_dig_in_a(tab_a, tab_b, ps);
		else if (ft_sort_last_param_b(tab_a, tab_b, size, ps) && ++res)
			break ;
		else if (++ps->rot)
			ft_rotate_b(tab_a, tab_b, ps, 2);
	}
	if (tmp == size)
		ps->rot = 0;
	return (res);
}

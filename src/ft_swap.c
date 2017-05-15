/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:12:02 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 14:47:22 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_swap_first_a(int **tab, int **tab_b, t_st *ps, int flag)
{
	int	swap;

	if (ps->a_len > 1)
	{
		swap = (*tab)[0];
		(*tab)[0] = (*tab)[1];
		(*tab)[1] = swap;
		ps->move++;
		if (flag == 1)
		{
			ps->vis ? ft_put_tabs(tab, tab_b, ps) : 0;
			if (!ps->sil)
				ft_printf("sa\n");
		}
		else if (flag == 2)
		{
			ps->vis ? ft_put_tabs(tab_b, tab, ps) : 0;
			if (!ps->sil)
				ft_printf("sb\n");
		}
	}
	return (1);
}

int		ft_swap_first_b(int **tab, int **tab_b, t_st *ps, int flag)
{
	int	swap;

	if (ps->b_len > 1)
	{
		swap = (*tab)[0];
		(*tab)[0] = (*tab)[1];
		(*tab)[1] = swap;
		ps->move++;
		if (flag == 1)
		{
			ps->vis ? ft_put_tabs(tab, tab_b, ps) : 0;
			if (!ps->sil)
				ft_printf("sa\n");
		}
		else if (flag == 2)
		{
			ps->vis ? ft_put_tabs(tab_b, tab, ps) : 0;
			if (!ps->sil)
				ft_printf("sb\n");
		}
	}
	return (1);
}

int		ft_swap_both(int **tab_a, int **tab_b, t_st *ps)
{
	if (ps->a_len > 1 && ps->b_len > 1)
	{
		ft_swap_first_a(tab_a, tab_b, ps, 0);
		ft_swap_first_b(tab_b, tab_a, ps, 0);
		ps->move--;
		ps->vis ? ft_put_tabs(tab_a, tab_b, ps) : 0;
		if (!ps->sil)
			ft_printf("ss\n");
	}
	return (1);
}

int		ft_count_str(char **src, int *argc)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	(*argc) = i;
	return (1);
}

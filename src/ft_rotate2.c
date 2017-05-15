/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:15:00 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 15:30:48 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_rotate_a(int **tab, int **tab_b, t_st *ps, int flag)
{
	int		swap;
	size_t	i;

	if (ps->a_len)
	{
		i = 0;
		swap = (*tab)[0];
		while (++i < ps->a_len)
			(*tab)[i - 1] = (*tab)[i];
		(*tab)[i - 1] = swap;
		ps->move++;
		if (flag == 1)
		{
			ps->vis ? ft_put_tabs(tab, tab_b, ps) : 0;
			if (!ps->sil)
				ft_printf("ra\n");
		}
		else if (flag == 2)
		{
			ps->vis ? ft_put_tabs(tab_b, tab, ps) : 0;
			if (!ps->sil)
				ft_printf("rb\n");
		}
	}
	return (1);
}

int		ft_rotate_b(int **tab, int **tab_b, t_st *ps, int flag)
{
	int		swap;
	size_t	i;

	if (ps->b_len)
	{
		i = 0;
		swap = (*tab)[0];
		while (++i < ps->b_len)
			(*tab)[i - 1] = (*tab)[i];
		(*tab)[i - 1] = swap;
		ps->move++;
		if (flag == 1)
		{
			ps->vis ? ft_put_tabs(tab, tab_b, ps) : 0;
			if (!ps->sil)
				ft_printf("ra\n");
		}
		else if (flag == 2)
		{
			ps->vis ? ft_put_tabs(tab_b, tab, ps) : 0;
			if (!ps->sil)
				ft_printf("rb\n");
		}
	}
	return (1);
}

int		ft_rotate_all(int **tab_a, int **tab_b, t_st *ps)
{
	if (!ps->a_len && !ps->b_len)
		return (1);
	ft_rotate_a(tab_a, tab_b, ps, 0);
	ft_rotate_b(tab_b, tab_a, ps, 0);
	ps->vis ? ft_put_tabs(tab_a, tab_b, ps) : 0;
	ps->move--;
	if (!ps->sil)
		ft_printf("rr\n");
	return (1);
}

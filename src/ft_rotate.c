/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:51:19 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 15:26:20 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_rotate_rev_a(int **tab, int **tab_b, t_st *ps, int flag)
{
	int		swap;
	int		i;

	if (ps->a_len)
	{
		i = ps->a_len;
		swap = (*tab)[ps->a_len - 1];
		while (--i > 0)
			(*tab)[i] = (*tab)[i - 1];
		(*tab)[0] = swap;
		ps->move++;
		if (flag == 1)
		{
			ps->vis ? ft_put_tabs(tab, tab_b, ps) : 0;
			if (!ps->sil)
				ft_printf("rra\n");
		}
		else if (flag == 2)
		{
			ps->vis ? ft_put_tabs(tab_b, tab, ps) : 0;
			if (!ps->sil)
				ft_printf("rrb\n");
		}
	}
	return (1);
}

int		ft_rotate_rev_b(int **tab, int **tab_b, t_st *ps, int flag)
{
	int		swap;
	int		i;

	if (ps->b_len)
	{
		i = ps->b_len;
		swap = (*tab)[ps->b_len - 1];
		while (--i > 0)
			(*tab)[i] = (*tab)[i - 1];
		(*tab)[0] = swap;
		ps->move++;
		if (flag == 1)
		{
			ps->vis ? ft_put_tabs(tab, tab_b, ps) : 0;
			if (!ps->sil)
				ft_printf("rra\n");
		}
		else if (flag == 2)
		{
			ps->vis ? ft_put_tabs(tab_b, tab, ps) : 0;
			if (!ps->sil)
				ft_printf("rrb\n");
		}
	}
	return (1);
}

int		ft_rotate_all_rev(int **tab_a, int **tab_b, t_st *ps)
{
	if (!ps->a_len && !ps->b_len)
		return (1);
	ft_rotate_rev_a(tab_a, tab_b, ps, 0);
	ft_rotate_rev_b(tab_b, tab_a, ps, 0);
	ps->vis ? ft_put_tabs(tab_a, tab_b, ps) : 0;
	ps->move--;
	if (!ps->sil)
		ft_printf("rrr\n");
	return (1);
}

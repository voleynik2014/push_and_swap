/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:20:09 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 18:24:38 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sort(int **tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (size >= 2 && (*tab)[i] > (*tab)[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_put_tabs(int **tab_a, int **tab_b, t_st *ps)
{
	size_t	i;

	i = 0;
	ft_printf("{BLUE}moves:{EOC} {CYAN}%zu{EOC}\n", ps->move);
	while (i < ps->a_len || i < ps->b_len)
	{
		if (i < ps->a_len)
		{
			if (i < ps->a_len && ps->col)
				ft_printf("A - {GREEN}%d{EOC}\t", (*tab_a)[i]);
			else
				ft_printf("A - %d\t", (*tab_a)[i]);
		}
		else
			ft_printf("\t");
		if (i < ps->b_len)
			ft_printf("B - {GREEN}%d{EOC}\n", (*tab_b)[i]);
		else
			ft_printf("\n");
		i++;
	}
	return (1);
}

char	**ft_bonus(char **argv, int *argc, t_st *ps)
{
	int fl;

	fl = 0;
	if ((*argc) == 2 && ++fl)
		argv = ft_strsplit(argv[1], ' ');
	ft_count_str(argv, argc);
	if ((ft_strequ(argv[1 - fl], "-vc") || ft_strequ(argv[1 - fl], "-cv")) &&
			++ps->col && ++ps->vis)
		return (ft_del_str(argv, 2 - fl, argc));
	else if (ft_strequ(argv[1 - fl], "-c") && ++ps->col)
		return (ft_del_str(argv, 2 - fl, argc));
	else if (ft_strequ(argv[1 - fl], "-v") && ++ps->vis)
		return (ft_del_str(argv, 2 - fl, argc));
	return (ft_del_str(argv, 1 - fl, argc));
}

char	**ft_del_str(char **src, int fl, int *argc)
{
	int		i;
	char	**dup;

	i = 0;
	while (src[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * i + 1);
	i = -1;
	while (src[++i + fl])
		if (src[i + fl])
			dup[i] = ft_strdup(src[i + fl]);
	dup[i] = NULL;
	*argc -= fl;
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:02:32 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 16:59:13 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_argv(char **src, int argc, t_st *ps)
{
	int i;
	int j;
	int k;

	i = ps->sil;
	i = 0;
	while (i < argc)
	{
		k = 0;
		j = 0;
		while (src[i][j])
		{
			if ((src[i][j] == '-' || src[i][j] == '+') && j == 0)
				j++;
			if (!ft_isdigit(src[i][j]))
				return (ft_printf("Error\n") - 6);
			j++;
		}
		while (k < i)
			if (ft_strequ(src[i], src[k++]))
				return (ft_printf("Error\n") - 6);
		i++;
	}
	return (1);
}

int		ft_check_next(int **tab_a, int med, int size, int fl)
{
	int i;

	i = fl;
	while (i < size)
	{
		if ((*tab_a)[i++] <= med)
			return (1);
	}
	return (0);
}

int		ft_maxint(char *src)
{
	long long i;

	if (ft_strlen(src) > 10)
		return (ft_printf("Error\n") - 6);
	if ((i = ft_atoi_ll(src)) > 2147483647)
		return (ft_printf("Error\n") - 6);
	return (1);
}

int		*ft_create_tab(int argc, char **argv, t_st *ps)
{
	int		*tab;
	int		i;

	i = ps->vis;
	tab = (int *)malloc(sizeof(int) * argc);
	if (!tab)
		return (0);
	if (!argv)
		return (tab);
	i = 0;
	while (i < argc)
	{
		if (!ft_maxint(argv[i]))
			return (NULL);
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

void	ft_calc_med(int *tab_tmp, int size, t_st *ps)
{
	int		i;
	int		sum;
	int		j;
	int		*tab;

	i = -1;
	tab = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		tab[i] = tab_tmp[i];
	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
			if (tab[j] > tab[j + 1])
			{
				sum = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = sum;
			}
	}
	ps->med = tab[((size / 2) - (size % 2 ? 0 : 1))];
	free(tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:50:59 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 18:09:22 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker(char *str, int **tab_a, int **tab_b, t_st *ps)
{
	if (++ps->sil && ft_strequ(str, "sa"))
		ft_swap_first_a(tab_a, tab_b, ps, 1);
	else if (ft_strequ(str, "sb"))
		ft_swap_first_b(tab_b, tab_b, ps, 2);
	else if (ft_strequ(str, "ss"))
		ft_swap_both(tab_a, tab_b, ps);
	else if (ft_strequ(str, "pb"))
		ft_put_dig_in_b(tab_a, tab_b, ps);
	else if (ft_strequ(str, "pa"))
		ft_put_dig_in_a(tab_b, tab_a, ps);
	else if (ft_strequ(str, "ra"))
		ft_rotate_a(tab_a, tab_b, ps, 1);
	else if (ft_strequ(str, "rb"))
		ft_rotate_b(tab_b, tab_b, ps, 2);
	else if (ft_strequ(str, "rr"))
		ft_rotate_all(tab_a, tab_b, ps);
	else if (ft_strequ(str, "rra"))
		ft_rotate_rev_a(tab_a, tab_b, ps, 1);
	else if (ft_strequ(str, "rrb"))
		ft_rotate_rev_b(tab_b, tab_b, ps, 2);
	else if (ft_strequ(str, "rrr"))
		ft_rotate_all_rev(tab_a, tab_b, ps);
	else
		return (ft_printf("Error\n"));
	return (0);
}

int		ft_crutch(int **tab_a, int **tab_b, t_st *ps, int argc)
{
	char *tmp;

	if (!argc)
		return (0);
	while (get_next_line(0, &tmp))
		if (ft_checker(tmp, tab_a, tab_b, ps))
			return (0);
	if (ft_check_sort(tab_a, argc) && ps->b_len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}

int		main(int argc, char **argv)
{
	char	**argv1;
	int		*tab_a;
	int		*tab_b;
	t_st	ps;
	int		i;

	ft_bzero(&ps, sizeof(t_st));
	argv1 = ft_bonus(argv, &argc, &ps);
	if (!ft_check_argv(argv1, argc, &ps))
		return (0);
	tab_a = ft_create_tab(argc, argv1, &ps);
	tab_b = ft_create_tab(argc, 0, &ps);
	if (tab_a == NULL)
		return (0);
	i = -1;
	while (++i < argc)
		free(argv1[i]);
	free(argv1);
	ps.a_len = (size_t)argc;
	ft_crutch(&tab_a, &tab_b, &ps, argc);
	free(tab_b);
	free(tab_a);
	return (0);
}

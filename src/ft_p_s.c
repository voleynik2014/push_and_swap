/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:10:44 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 17:33:24 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(int argc, char **argv)
{
	int		*tab_a;
	int		*tab_b;
	t_st	ps;
	char	**argv1;
	int		i;

	ft_bzero(&ps, sizeof(t_st));
	argv1 = ft_bonus(argv, &argc, &ps);
	if (!ft_check_argv(argv1, argc, &ps))
		return ;
	if ((tab_a = ft_create_tab(argc, argv1, &ps)) == NULL)
		return ;
	tab_b = ft_create_tab(argc, 0, &ps);
	i = -1;
	while (++i < argc)
		free(argv1[i]);
	free(argv1);
	ps.a_len = (size_t)argc;
	if (ft_check_sort(&tab_a, argc))
		return ;
	ft_check_a_b(&tab_a, &tab_b, argc, &ps);
	if (ps.vis)
		ft_put_tabs(&tab_a, &tab_b, &ps);
	free(tab_a);
	free(tab_b);
}

int		main(int argc, char **argv)
{
	ft_push_swap(argc, argv);
	return (1);
}

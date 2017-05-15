/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:31:13 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 16:13:08 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct	s_st
{
	size_t		a_len;
	size_t		b_len;
	size_t		move;
	int			rot;
	int			med;
	size_t		a_tmp_len;
	size_t		b_tmp_len;
	int			vis;
	int			col;
	int			sil;
}				t_st;

int				main(int argc, char **argv);
int				ft_put_tabs(int **tab_a, int **tab_b, t_st *ps);
char			**ft_bonus(char **argv, int *argc, t_st *ps);
char			**ft_del_str(char **src, int fl, int *argc);

void			ft_check_b_a(int **tab_a, int **tab_b, int size, t_st *ps);
void			ft_check_a_b(int **tab_a, int **tab_b, int size, t_st *ps);
int				ft_put_med_a(int **tab_a, int **tab_b, t_st *ps, int size);
int				ft_put_med_b(int **tab_a, int **tab_b, t_st *ps, int size);

int				ft_check_argv(char **src, int argc, t_st *ps);
int				ft_check_next(int **tab_a, int med, int size, int fl);
int				ft_check_sort(int **tab, int size);
int				*ft_create_tab(int argc, char **argv, t_st *ps);
void			ft_calc_med(int *tab, int size, t_st *ps);

int				ft_put_dig_in_b(int **tab_a, int **tab_b, t_st *ps);
int				ft_put_dig_in_a(int **tab_a, int **tab_b, t_st *ps);

void			ft_check_and_put(int **tab_a, int **tab_b, t_st *ps);
void			ft_check_and_put_b(int **tab_a, int **tab_b, t_st *ps);
int				ft_check_and_put_single(int **tab_a, int **tab_b, t_st *ps);
int				ft_check_and_put_both(int **tab_a, int **tab_b, t_st *ps);

int				ft_check_next_dig_b(int **tab_a, int med, int size, int fl);
int				ft_check_next_dig_a(int **tab_a, int med, int size, int fl);
int				ft_sort_less_6(int **tab_a, int **tab_b, size_t size, t_st *ps);
int				ft_sort_less_6_b(int **tab_a, int **tab_b, int size, t_st *ps);

int				ft_rotate_a(int **tab, int **tab_b, t_st *ps, int flag);
int				ft_rotate_b(int **tab, int **tab_b, t_st *ps, int flag);
int				ft_rotate_all(int **tab_a, int **tab_b, t_st *ps);

int				ft_rotate_rev_a(int **tab, int **tab_b, t_st *ps, int flag);
int				ft_rotate_rev_b(int **tab, int **tab_b, t_st *ps, int flag);
int				ft_rotate_all_rev(int **tab_a, int **tab_b, t_st *ps);

int				ft_swap_first_a(int **tab, int **tab_b, t_st *ps, int flag);
int				ft_swap_first_b(int **tab, int **tab_b, t_st *ps, int flag);
int				ft_swap_both(int **tab_a, int **tab_b, t_st *ps);
int				ft_count_str(char **src, int *argc);

void			ft_cheker(char *str, int **tab_a, int **tab_b, t_st *ps);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:51:09 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/13 14:22:36 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct		s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_flag
{
	int				a;
	int				b;
	int				g;
}					t_flag;

void				init_flag(t_flag *flag);
t_list				*create_elem(int data);
t_list				*pile_up_elem_first(t_list *list, int data);
t_list				*pile_up_elem_last(t_list *list, int data);
t_list				*last_elem(t_list *list);
t_list				*erase_list(t_list *list, int pos);
void				lst_free(t_list *list);

void				swap(t_list *list);
void				sa(t_list *l_a, t_list *l_b);
void				sb(t_list *l_b);
t_list				*ra(t_list *l_a, t_list *l_b);
t_list				*rb(t_list *l_b);
void				pa(t_list **l_a, t_list **l_b);
void				pb(t_list **l_a, t_list **l_b);

int					check_param(char *argv);
int					check_dup(t_list *list);
void				check_list_order(t_list *list);
int					ft_asc(t_list *list);
int					ft_desc(t_list *list);
void				ft_sort(t_list *l_a);
void				ft_sort_bis(t_list **l_a, t_list **l_b, t_flag *flag);

#endif

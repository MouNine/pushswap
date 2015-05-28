/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:48:42 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/10 15:16:12 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_flag(t_flag *flag)
{
	flag->a = 0;
	flag->b = 0;
	flag->g = 0;
}

int			ft_asc(t_list *list)
{
	if (list == NULL)
		return (0);
	while (list->data < list->next->data)
	{
		list = list->next;
		if (list->next == NULL)
			return (1);
	}
	return (0);
}

int			ft_desc(t_list *list)
{
	if (list == NULL)
		return (0);
	while (list->data > list->next->data)
	{
		list = list->next;
		if (list->next == NULL)
			return (1);
	}
	return (0);
}

void		ft_sort_bis(t_list **l_a, t_list **l_b, t_flag *flag)
{
	if ((*l_a)->data > (*l_a)->next->data)
		sa(*l_a, *l_b);
	flag->a = ft_asc(*l_a);
	if (flag->a == 0 && (*l_a)->data < (*l_a)->next->data)
	{
		pb(l_a, l_b);
		if ((*l_b)->next != NULL)
		{
			if ((*l_b)->data < (last_elem(*l_b))->data)
				*l_b = rb(*l_b);
			if ((*l_b)->data < (*l_b)->next->data)
				sb(*l_b);
			flag->b = ft_desc(*l_b);
		}
		if ((*l_b)->next == NULL)
			flag->b = 1;
	}
}

void		ft_sort(t_list *l_a)
{
	t_list	*l_b;
	t_flag	flag;

	l_b = NULL;
	init_flag(&flag);
	while (flag.g == 0)
	{
		if (l_a->data > (last_elem(l_a))->data)
			l_a = ra(l_a, l_b);
		ft_sort_bis(&l_a, &l_b, &flag);
		while (flag.a == 1 && l_b != NULL)
		{
			pa(&l_a, &l_b);
			flag.a = ft_asc(l_a);
		}
		if (flag.a == 1 && flag.b == 1 && l_b == NULL)
			flag.g = 1;
	}
}

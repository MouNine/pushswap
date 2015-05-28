/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:48:42 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/09 12:21:20 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_list *list)
{
	int		tmp;

	tmp = 0;
	if (list && list->next)
	{
		tmp = list->data;
		list->data = list->next->data;
		list->next->data = tmp;
	}
	else
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}

void		sa(t_list *l_a, t_list *l_b)
{
	swap(l_a);
	if ((ft_asc(l_a) == 1) && l_b == NULL)
	{
		ft_putendl("sa");
		exit(0);
	}
	else
		ft_putstr("sa ");
}

void		sb(t_list *l_b)
{
	swap(l_b);
	ft_putstr("sb ");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 12:29:05 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/09 12:20:55 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(t_list **l_a, t_list **l_b)
{
	int		tmp;

	tmp = 0;
	if ((*l_b) != NULL)
	{
		tmp = (*l_b)->data;
		*l_b = erase_list(*l_b, 0);
		*l_a = pile_up_elem_first(*l_a, tmp);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	if ((ft_asc(*l_a) == 1) && *l_b == NULL)
	{
		ft_putendl("pa");
		exit(0);
	}
	else
		ft_putstr("pa ");
}

void		pb(t_list **l_a, t_list **l_b)
{
	int		tmp;

	tmp = 0;
	if ((*l_a) != NULL)
	{
		tmp = (*l_a)->data;
		*l_a = erase_list(*l_a, 0);
		*l_b = pile_up_elem_first(*l_b, tmp);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	write(1, "pb ", 3);
}

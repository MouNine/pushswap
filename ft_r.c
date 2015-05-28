/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 14:30:06 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/09 12:20:34 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*ra(t_list *l_a, t_list *l_b)
{
	int		tmp;

	if (l_a != NULL)
	{
		tmp = 0;
		tmp = l_a->data;
		l_a = erase_list(l_a, 0);
		l_a = pile_up_elem_last(l_a, tmp);
		if (ft_asc(l_a) == 1 && l_b == NULL)
		{
			ft_putendl("ra");
			exit(0);
		}
		else
			ft_putstr("ra ");
	}
	else
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (l_a);
}

t_list		*rb(t_list *l_b)
{
	int		tmp;

	tmp = 0;
	if (l_b != NULL)
	{
		tmp = l_b->data;
		l_b = erase_list(l_b, 0);
		l_b = pile_up_elem_last(l_b, tmp);
		ft_putstr("rb ");
	}
	else
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (l_b);
}

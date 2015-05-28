/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:52:19 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/13 17:51:37 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			lst_free(t_list *list)
{
	if (list != NULL)
	{
		while (list->next)
			free(list);
	}
}

int				main(int ac, char **av)
{
	t_list		*list;
	int			i;

	list = NULL;
	i = 1;
	if (ac < 2)
		exit(0);
	if (ac == 2 && (check_param(av[i]) == 0))
		return (write(2, "Error\n", 6));
	if (ac > 2)
	{
		while (av[i])
		{
			if (check_param(av[i]) == 0 || ft_isint(av[i]) == 0)
				return (write(2, "Error\n", 6));
			list = pile_up_elem_last(list, ft_atoi(av[i++]));
		}
		if (check_dup(list) == 0)
			return (write(2, "Error\n", 6));
		check_list_order(list);
		ft_sort(list);
		lst_free(list);
	}
	return (0);
}

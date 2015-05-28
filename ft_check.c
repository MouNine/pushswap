/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 17:20:51 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/13 17:51:00 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_param(char *argv)
{
	int			i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-' && ft_isdigit(argv[i + 1]) == 0)
			return (0);
		if (argv[i] == '+' && ft_isdigit(argv[i + 1]) == 0)
			return (0);
		if (ft_isdigit(argv[i]) == 0)
		{
			if (argv[i] != '-' && argv[i] != '+')
				return (0);
		}
		i++;
	}
	return (1);
}

int				check_dup(t_list *list)
{
	t_list		*tmp;
	t_list		*curr;

	curr = list->next;
	while (list && curr)
	{
		if (list->data == curr->data)
			return (0);
		tmp = curr->next;
		if (tmp)
		{
			while (tmp)
			{
				if (tmp->data == curr->data || tmp->data == list->data)
					return (0);
				tmp = tmp->next;
			}
		}
		curr = curr->next;
	}
	return (1);
}

void			check_list_order(t_list *list)
{
	while (list && list->next && list->data < list->next->data)
	{
		list = list->next;
		if (list->next == NULL)
			exit(0);
	}
}

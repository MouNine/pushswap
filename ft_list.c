/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 14:06:27 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/09 12:56:43 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*create_elem(int data)
{
	t_list	*n;

	if ((n = (t_list *)malloc(sizeof(t_list))))
	{
		n->data = data;
		n->prev = NULL;
		n->next = NULL;
	}
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (n);
}

t_list		*pile_up_elem_first(t_list *list, int data)
{
	t_list	*n;
	t_list	*tmp;

	tmp = list;
	n = create_elem(data);
	if (list == NULL)
		return (n);
	else
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
		tmp->prev = n;
		n->next = tmp;
		list = list->prev;
	}
	return (list);
}

t_list		*pile_up_elem_last(t_list *list, int data)
{
	t_list	*tmp;
	t_list	*n;

	tmp = list;
	n = create_elem(data);
	if (list == NULL)
		return (n);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = n;
		n->prev = tmp;
	}
	return (list);
}

t_list		*last_elem(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_list		*erase_list(t_list *list, int pos)
{
	t_list	*n;

	n = list;
	if (pos == 1)
		while (list->next)
			list = list->next;
	else if (list->next != NULL)
		list = list->next;
	else
	{
		free(list);
		return (NULL);
	}
	list->prev->next = NULL;
	list->prev = NULL;
	free(list->prev);
	if (pos == 1)
		return (n);
	else
		return (list);
}

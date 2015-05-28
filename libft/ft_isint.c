/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:44:05 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/13 17:52:22 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_isint(char *str)
{
	int		nbr;
	char	*tmp;
	int		isint;

	if (str[0] == '+')
		str = ft_strsub(str, 1, ft_strlen(str));
	nbr = ft_atoi(str);
	tmp = ft_itoa(nbr);
	if (ft_strcmp(tmp, str) == 0)
		isint = 1;
	else
		isint = 0;
	return (isint);
}

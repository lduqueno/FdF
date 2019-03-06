/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:57:01 by ccharrie          #+#    #+#             */
/*   Updated: 2018/12/13 16:01:32 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpushback(t_dlist **lst, t_dlist *new)
{
	t_dlist	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		(*lst)->next->prev = *lst;
		*lst = tmp;
	}
}

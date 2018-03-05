/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:30:35 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/28 14:10:40 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablenfree(char **tab)
{
	int	res;

	res = 0;
	while (tab[res])
	{	
		ft_strdel(&tab[res]);
		res++;
	}
	free(tab);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:30:35 by ccharrie          #+#    #+#             */
/*   Updated: 2018/03/05 14:14:54 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int		ft_tablen(char **tab)
{
	int	res;

	res = 0;
	while (tab[res])
	{
//		printf("c'est la case : %d\n", res);
//		printf("%p\n", tab[res]);
		res++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increaser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:10:18 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/27 14:58:55 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hup(t_mlx *mlx)
{
	mlx->spacey++;
	ft_resetwin(mlx);
}

void	hdown(t_mlx *mlx)
{
	mlx->spacey--;
	ft_resetwin(mlx);
}

void	wup(t_mlx *mlx)
{
	mlx->spacex++;
	ft_resetwin(mlx);
}

void	wdown(t_mlx *mlx)
{
	mlx->spacex--;
	ft_resetwin(mlx);
}

void	dupdn(t_mlx *mlx, int i)
{
	if (i == 0)
	{
		mlx->dp++;
		if (mlx->dp == 0)
			mlx->dp++;
	}
	else
	{
		mlx->dp--;
		if (mlx->dp == 0)
			mlx->dp--;
	}
	ft_resetwin(mlx);
}

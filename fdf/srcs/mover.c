/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:16:32 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/19 16:41:38 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	left(t_mlx *mlx)
{
		mlx->beginx -= 10;
		ft_resetwin(mlx);
}

void	up(t_mlx *mlx)
{
	if (mlx->beginy > 310)
	{
		mlx->beginy -= 10;
		ft_resetwin(mlx);
	}
}

void	down(t_mlx *mlx)
{
	mlx->beginy += 10;
	ft_resetwin(mlx);
}

void	right(t_mlx *mlx)
{
	mlx->beginx += 10;
	ft_resetwin(mlx);
}

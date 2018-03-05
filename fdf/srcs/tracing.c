/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:56:46 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/27 17:00:33 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_mlx *mlx, int i)
{
	if (mlx->pixtab[i].z == 0)
		return (0x00c800);
	else if (mlx->pixtab[i].z >= 0 && mlx->pixtab[i].z <= 5)
		return (0xFF0000);
	else if (mlx->pixtab[i].z >= 5 && mlx->pixtab[i].z <= 10)
		return (0xFFFF00);
	else if (mlx->pixtab[i].z >= 10 && mlx->pixtab[i].z <= 15)
		return (0xFF9933);
	else if (mlx->pixtab[i].z >= 15)
		return (0xFF007F);
	else if (mlx->pixtab[i].z <= 0 && mlx->pixtab[i].z >= -5)
		return (0x00FFFF);
	else if (mlx->pixtab[i].z <= -5 && mlx->pixtab[i].z >= -10)
		return (0x0000FF);
	else if (mlx->pixtab[i].z <= -10)
		return (0x7F00FF);
	return (0);
}

void	ft_tracevert(t_mlx *mlx, int x, int y, int k)
{
	int		i;
	int		cum;

	i = 0;
	cum = mlx->pixtab[k].dy / 2;
	while (i <= mlx->pixtab[k].dy)
	{
		y += mlx->pixtab[k].yinc;
		cum += mlx->pixtab[k].dx;
		if (cum >= mlx->pixtab[k].dy)
		{
			cum -= mlx->pixtab[k].dy;
			x += mlx->pixtab[k].xinc;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->win, x, y, get_color(mlx, k));
		i++;
	}
}

void	ft_tracehori(t_mlx *mlx, int x, int y, int k)
{
	int		i;
	int		cum;

	i = 1;
	cum = mlx->pixtab[k].dx / 2;
	while (i <= mlx->pixtab[k].dx)
	{
		x += mlx->pixtab[k].xinc;
		cum += mlx->pixtab[k].dy;
		if (cum >= mlx->pixtab[k].dx)
		{
			cum -= mlx->pixtab[k].dx;
			y += mlx->pixtab[k].yinc;
		}
		mlx_pixel_put(mlx->mlx_ptr, mlx->win, x, y, get_color(mlx, k));
		i++;
	}	
}

void	ft_brestracing(t_mlx *mlx, int i, int beginx, int beginy)
{
	int		x;
	int		y;

	x = mlx->pixtab[i].xi + beginx;
	y = mlx->pixtab[i].yi + beginy;
	mlx->pixtab[i].dx = mlx->pixtab[i].xf - mlx->pixtab[i].xi;
	mlx->pixtab[i].dy = mlx->pixtab[i].yf - mlx->pixtab[i].yi;
	mlx->pixtab[i].xinc = (mlx->pixtab[i].dx > 0) ? 1 : -1;
	mlx->pixtab[i].yinc = (mlx->pixtab[i].dy > 0) ? 1 : -1;
	mlx->pixtab[i].dx = abs(mlx->pixtab[i].dx);
	mlx->pixtab[i].dy = abs(mlx->pixtab[i].dy);
	mlx_pixel_put(mlx->mlx_ptr, mlx->win, x, y, get_color(mlx, i));
	if (mlx->pixtab[i].dx > mlx->pixtab[i].dy)
		ft_tracehori(mlx, x, y, i);
	else
		ft_tracevert(mlx, x, y, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:45:17 by ccharrie          #+#    #+#             */
/*   Updated: 2018/03/05 18:08:01 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*ft_getmpixtab(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	mlx->pixtab = (t_pix *)malloc(sizeof(t_pix) * mlx->len);
	i = 0;
	y = 0;
	while (i < mlx->len && y < mlx->ymax)
	{
		x = 0;
		while (x < mlx->xmax)
		{
			mlx->pixtab[i].xi = x * mlx->space;
			mlx->pixtab[i].yi = y * mlx->space;
			mlx->pixtab[i].z = mlx->res[y][x];
			x++;
			i++;
		}
		y++;
	}
	return (mlx);
}

int		ft_getmenu(t_mlx *mlx)
{
	int		i;

	mlx = ft_getmap(mlx, "fdfmenu.fdf", 1);
	mlx = ft_getmpixtab(mlx);
	i = 0;
	while (i < mlx->len && i + 1 < mlx->len)
	{
		if ((i + 1) % mlx->xmax != 0)
		{
			mlx->pixtab[i].xf = mlx->pixtab[i + 1].xi;
			mlx->pixtab[i].yf = mlx->pixtab[i + 1].yi;
			ft_brestracing(mlx, i, mlx->mbeginx, mlx->mbeginy);
		}
		if ((i / mlx->xmax) <  mlx->ymax - 1)
		{
			mlx->pixtab[i].xf = mlx->pixtab[i + mlx->xmax].xi;
			mlx->pixtab[i].yf = mlx->pixtab[i + mlx->xmax].yi;
			ft_brestracing(mlx, i, mlx->mbeginx, mlx->mbeginy);
		}
		i++;
	}
	return (0);
}

void	ft_putstring(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5, 5, 0xFF0000,
			"              Menu : ");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5, 55, 0xFF8000,
			"Move the image              = keyboard arrows");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5, 95, 0xFFFF00,
			"Zoom and unzoom the image   = + -");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5, 135, 0x80FF00,
			"Increase or decrease ymax = w s");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5, 175, 0x00FF00,
			"Increase or decrease witdh  = a d");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 5, 215, 0x00FF80,
			"Increase or decrease depth  = < >");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 1450, 5, 0xFFFFFF, "Credits :");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 1450, 105, 0xFFFFFF,
			"Made by Ccharrie");
	mlx_string_put(mlx->mlx_ptr, mlx->win, 1450, 255, 0xFFFFFF,
			"Performed by Minilibx");
}

void	setmenu(t_mlx *mlx)
{
	int		x;

	x = 0;
	while (x < 1820)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win, x, 300, 0xFFFFFF);
		x++;
	}
	mlx->space = 27;
	mlx->mbeginx = 910;
	mlx->mbeginy = 0;
	free(mlx->pixtab);
	ft_getmenu(mlx);
	ft_putstring(mlx);
}

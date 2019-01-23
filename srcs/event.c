/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:26:14 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/28 15:49:09 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_resetwin(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	free(mlx->pixtab);
	ft_getimage(mlx, mlx->file);
	setmenu(mlx);
}

void	unzoom(t_mlx *mlx)
{
	if (mlx->spacex > 1 && mlx->spacey > 1)
	{
		mlx->spacex--;
		mlx->spacey--;
		ft_resetwin(mlx);
	}
}

void	zoom(t_mlx *mlx)
{
	mlx->spacex++;
	mlx->spacey++;
	ft_resetwin(mlx);
}

int		ft_getkey(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_clear_window(mlx->mlx_ptr, mlx->win);
		free(mlx->pixtab);
		free(mlx->win);
		free(mlx->mlx_ptr);
		ft_strdel(&mlx->file);
		free(mlx);
		exit (0);
	}
	keycode == 27 ? unzoom(mlx) : (keycode == 24 ? zoom(mlx) : keycode);
	keycode == 123 ? left(mlx) : (keycode == 126 ? up(mlx) : (keycode == 125 ?
				down(mlx) : (keycode == 124 ? right(mlx) : keycode)));
	keycode == 13 ? hup(mlx) : (keycode == 1 ? hdown(mlx) : (keycode == 0 ?
				wup(mlx) : (keycode == 2 ? wdown(mlx) : (keycode == 43 ?
				dupdn(mlx, 0) : (keycode == 47 ? dupdn(mlx, 1) : keycode)))));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:34:55 by ccharrie          #+#    #+#             */
/*   Updated: 2018/03/05 18:57:50 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*ft_getpixtab(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	if (!(mlx->pixtab = (t_pix *)malloc(sizeof(t_pix) * mlx->len)))
		return (NULL);
	printf("%p\n", &mlx->dp);
	while(1);
	i = 0;
	y = 0;
	while (i < mlx->len && y < mlx->ymax)
	{
		x = 0;
		while (x < mlx->xmax)
		{
			mlx->pixtab[i].xi = ((x - y) * mlx->spacex) - mlx->res[y][x];
			mlx->pixtab[i].yi = (x + y) * mlx->spacey / 2 - mlx->res[y][x];
			mlx->pixtab[i].z = mlx->res[y][x];
			x++;
			i++;
		}
		y++;
	}
	return (mlx);
}

int		ft_getimage(t_mlx *mlx, char *file)
{
	int		i;

	mlx = ft_getmap(mlx, file, mlx->dp);
	mlx = ft_getpixtab(mlx);
	i = 0;
	while (i < mlx->len && i + 1 < mlx->len)
	{
		if ((i + 1) % mlx->xmax != 0)
		{
			mlx->pixtab[i].xf = mlx->pixtab[i + 1].xi;
			mlx->pixtab[i].yf = mlx->pixtab[i + 1].yi;
			ft_brestracing(mlx, i, mlx->beginx, mlx->beginy);
		}
		if ((i / mlx->xmax) <  mlx->ymax - 1)
		{
			mlx->pixtab[i].xf = mlx->pixtab[i + mlx->xmax].xi;
			mlx->pixtab[i].yf = mlx->pixtab[i + mlx->xmax].yi;
			ft_brestracing(mlx, i, mlx->beginx, mlx->beginy);
		}
		i++;
	}
	ft_tabintdel(mlx->res, mlx->ymax);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	mlx->spacex = 25;
	mlx->spacey = 25;
	mlx->beginx = 1000;
	mlx->beginy = 500;
	mlx->dp = 1;
	if (ac == 2)
	{
		mlx->file = ft_strdup(av[1]);
		mlx->mlx_ptr = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WID, WIN_HEIG, mlx->file);
		check_error(mlx->file);
		ft_getimage(mlx, mlx->file);
		setmenu(mlx);
		mlx_hook(mlx->win, 2, 3, ft_getkey, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
	{
		free(mlx);
		ft_putendl("Usage : ./fdf [mapfile.fdf]");
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:34:55 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/25 17:21:27 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getkey(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	return (0);
}

void	ft_getimage(t_mlx mlx, char *file)
{
	int		i;
	int		j;
	t_map	map;

	map = ft_getmap(file);
	ft_putnbr(map.xmax);
	ft_putnbr(map.ymax);
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, map.xmax * 25 , map.ymax * 25);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &(mlx.img.bpp),
			&(mlx.img.sl), &(mlx.img.en));
	i = -1;
	while (++i <= map.ymax * 25)
	{
		j = -1;
		while (++j <= map.xmax * 25)
		{
			if ((!(i % 25)) && (!(j % 25)))
				mlx.img.data[i * (map.xmax * 25) + j] = 0xFFFFFF;
			else
				mlx.img.data[i * (map.xmax * 25) + j] = 0;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 100, 100);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
	{
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "test");
	ft_getimage(mlx, av[1]);
	mlx_key_hook(mlx.win, ft_getkey, 0);
	mlx_loop(mlx.mlx_ptr);
	}
	return (0);
}

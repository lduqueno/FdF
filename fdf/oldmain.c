/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:39:05 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/16 16:37:18 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_getmapint(char *file, t_win size)
{
	int		fd;
	int		i;
	int		y;
	int		**res;
	char	*line;
	char	**tmp;

	if (!(res = (int **)malloc(sizeof(int *) * size.ymax)))
		return (0);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		y = 0;
		tmp = ft_strsplit(line, ' ');
		if (!(res[i] = (int *)malloc(sizeof(int) * size.xmax)))
			return (0);
		while (tmp[y])
		{
			res[i][y] = ft_atoi(tmp[y]);
			y++;
		}
		i++;
		ft_del2dtab(tmp);
		ft_strdel(&line);
	}
	return (res);
}

void	ft_putmap(void *mlx, void *win, t_win size, char *file)
{
	int		x;
	int		y;
	int		xtmp;
	int		ytmp;
	int		**map;


	map = ft_getmapint(file, size);
	size.xbegin = 125;
	size.ybegin = 125;
	y = 0;
	while (y < size.ymax)
	{
		x = 0;
		while (x < size.xmax)
		{
			ytmp = size.ybegin;
			xtmp = size.xbegin;
				while (ytmp != size.ybegin + 10)
				{
					while (xtmp != size.xbegin + 10)
					{
						if (map[y][x] == 0)
						{
							mlx_pixel_put(mlx, win, xtmp + x, ytmp + y,
									0xFFFF00);
						}
						else
						{
							mlx_pixel_put(mlx, win, xtmp + x, ytmp + y,
									0xFF0000 +  map[y][x] * 20);
						}
						xtmp++;
					}
					xtmp = size.xbegin;
					ytmp++;
				}
			size.xbegin = size.xbegin + 9;
			x++;
		}
		size.xbegin = 125;
		size.ybegin = size.ybegin + 9;
		y++;
	}
}

t_win	ft_calcmapsize(char *file)
{
	int		fd;
	char	*line;
	t_win	size;
	char	**map;

	size.ymax = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		map = ft_strsplit(line, ' ');
		size.xmax = ft_tablen(map);
		size.ymax++;
		ft_strdel(&line);
		ft_del2dtab(map);
	}
	close(fd);
	return (size);
}

int		ft_getkey(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_win	size;

	if (ac == 2)
	{
		size = ft_calcmapsize(av[1]);
		mlx = mlx_init();
		win = mlx_new_window(mlx, size.xmax * 10 + 400,
				size.ymax * 10 + 400, "test");
		ft_putmap(mlx, win, size, av[1]);
		mlx_key_hook(win, ft_getkey, 0);
		mlx_loop(mlx);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:21:37 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/25 17:21:30 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_char2int(t_map map, int fd)
{
	int		i;
	int		j;
	char	**tmp;
	char	*line;

	if (!(map.res = (int **)malloc(sizeof(int *) * map.ymax)))
		return (0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		tmp = ft_strsplit(line, ' ');
		if (!(map.res[i] = (int *)malloc(sizeof(int) * map.xmax)))
			return (0);
		while (tmp[j])
		{
			map.res[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		i++;
//		ft_del2dtab(tmp);
//		ft_strdel(&line);
	}
	return (0);
}

t_map		ft_getmaxcoord(int fd)
{
	char	*line;
	char	**tmp;
	t_map	map;

	map.xmax = 0;
	map.ymax = 0;
	while (get_next_line(fd, &line))
	{
		ft_putstr("hey");
		tmp = ft_strsplit(line, ' ');
		if (map.xmax < ft_tablen(tmp))
			map.xmax = ft_tablen(tmp);
		map.ymax++;
//		ft_strdel(&line);
//		ft_del2dtab(tmp);
	}
	close(fd);
	return (map);
}

t_map		ft_getmap(char *file)
{
	int		fd;
	int		tmp;
	t_map	map;

	fd = open(file, O_RDONLY);
	map = ft_getmaxcoord(fd);
	fd = open(file, O_RDONLY);
	tmp = ft_char2int(map, fd);
	close(fd);
	ft_putnbr(map.xmax);
	ft_putnbr(map.ymax);
	return (map);
}

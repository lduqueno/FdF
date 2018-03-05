/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:21:37 by ccharrie          #+#    #+#             */
/*   Updated: 2018/03/05 18:59:26 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tabintdel(int **res, int len)
{
	int		i;
	
	i = 0;
	while (i < len)
	{
		free(res[i]);
		i++;
	}
	free(res);
}
#include<stdio.h>

t_mlx		*ft_char2int(t_mlx *mlx, int fd, char *line, int dp)
{
	int		i;
	int		j;
	char	**tmp;

	if (!(mlx->res = (int **)malloc(sizeof(int *) * mlx->ymax)))
		return (0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		tmp = ft_strsplit(line, ' ');
		if (!(mlx->res[i] = (int *)malloc(sizeof(int) * mlx->xmax)))
			return (0);
		while (tmp[j])
		{
			mlx->res[i][j] = ft_atoi(tmp[j]) * dp;
			j++;
		}
		i++;
		ft_del2dtab(&tmp);
		ft_strdel(&line);
	}
	return (mlx);
}

t_mlx	*ft_getmaxcoord(t_mlx *mlx, int fd)
{
	char	**tmp;
	char	*line;

	mlx->xmax = 0;
	mlx->ymax = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		if (mlx->xmax < ft_tablen(tmp))
			mlx->xmax = ft_tablen(tmp);
		mlx->ymax++;
		ft_strdel(&line);
		ft_del2dtab(&tmp);
	}
	mlx->len = mlx->xmax * mlx->ymax;
	return (mlx);
}

t_mlx		*ft_getmap(t_mlx *mlx, char *file, int dp)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	mlx = ft_getmaxcoord(mlx, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	mlx = ft_char2int(mlx, fd, line, dp);
	close(fd);
	return (mlx);
}

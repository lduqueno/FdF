/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nparsingconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:22:45 by ccharrie          #+#    #+#             */
/*   Updated: 2018/03/05 15:33:16 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_tabintdel(int **res, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
//		free(res[i]);
		i++;
	}
	free(res);
}

static void		check_width(t_mlx *mlx, char **u_map)
{
	int		width;

	width = 0;
	while (u_map[width])
		width++;
	mlx->width = width;
}

static void		check_height(t_mlx *mlx, char *av)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	line = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_putendl("Error: Open failed.");
	while (get_next_line(fd, &line) >= 1)
	{
		height++;
		ft_strdel(&line);
	}
	mlx->height = height;
	ft_strdel(&line);
	close(fd);
}

static void		array_to_int(t_mlx *mlx, t_var *var, int dp)
{
	while (mlx->tmp[var->j])
	{
		mlx->res[var->i][var->j] = ft_atoi(mlx->tmp[var->j]) * dp;
		ft_strdel(&(mlx->tmp[var->j]));
		var->j++;
	}
}

void			get_map(t_mlx *mlx, char *av, int dp)
{
	t_var		var;

	var.i = 0;
	if ((var.fd = open(av, O_RDONLY)) == -1)
		ft_putendl("Error: Open failed.");
	check_height(mlx, av);
	mlx->res = (int **)malloc(sizeof(int *) * mlx->height);
	while (get_next_line(var.fd, &var.line) >= 1)
	{
		var.j = 0;
		mlx->tmp = ft_strsplit(var.line, ' ');
		check_width(mlx, mlx->tmp);
		mlx->res[var.i] = (int *)malloc(sizeof(int) * mlx->width);
		array_to_int(mlx, &var, dp);
		var.i++;
		ft_del2dtab(&mlx->tmp);
		ft_strdel(&var.line);
	}
	mlx->len = mlx->width * mlx->height;
	mlx->res[var.i] = NULL;
	ft_strdel(&var.line);
	close(var.fd);
}

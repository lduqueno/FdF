/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:29:48 by ccharrie          #+#    #+#             */
/*   Updated: 2018/03/05 15:51:24 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_file(char *file, int fd)
{
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl("fdf error : permission denied or no such file");
//		free(mlx);
		exit(0);
	}
	close(fd);
}

void	ft_dofree(char **line, char ***tmp)
{
	ft_strdel(line);
	ft_del2dtab(tmp);
}
#include<stdio.h>
void	ft_check_tab(char *file, int fd, char *line)
{
	char	**tmp;
	int		xtmp;
	int		xmax;
//	int	i=0;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	tmp = ft_strsplit(line, ' ');
	xmax = ft_tablen(tmp);
	ft_dofree(&line, &tmp);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		xtmp = ft_tablen(tmp);
//		printf("############## ligne :%d\n", i);
//		i++;
		if (xtmp != xmax)
		{
//			free(mlx);
			ft_dofree(&line, &tmp);
			close(fd);
			ft_putendl("fdf error : different lines size");
			exit(0);
		}
		ft_dofree(&line, &tmp);
	}
}

int		check_error(char *file)
{
	int		fd;
	char	*line;
	
	fd = 0;
	line =  NULL;
	ft_check_file(file, fd);
//	ft_check_tab(file, fd, line);
	close(fd);
	return (0);
}

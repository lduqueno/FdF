/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:40:03 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/25 17:21:32 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct	s_map
{
	int	xmax;
	int	ymax;
	int	**res;
}				t_map;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		sl;
	int		en;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
}			t_mlx;

t_map		ft_getmap(char *file);

#endif

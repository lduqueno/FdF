/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:40:03 by ccharrie          #+#    #+#             */
/*   Updated: 2018/03/05 18:39:10 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
#include<stdio.h>

# define WIN_WID 1820
# define WIN_HEIG 1280

# define checkmc0(x) if (!(x)) return (0)
# define checkmcn(x) if (!(x)) return (NULL)

typedef struct		s_var
{
	char			*line;
	int				fd;
	int				i;
	int				j;
}					t_var;


typedef struct	s_map
{
	int		xmax;
	int		ymax;
	int		len;
	int		fd;
	int		**res;
}				t_map;

typedef struct	s_pix
{
	int		xi;
	int		yi;
	int		xf;
	int		yf;
	int		dx;
	int		dy;
	int		z;
	int		yinc;
	int		xinc;
}				t_pix;

typedef struct	s_mlx
{
	int		xmax;
	int		ymax;
	int		len;
	int		**res;
	int		fd;
	void	*mlx_ptr;
	void	*win;
	t_pix	*pixtab;
	int		beginx;
	int		beginy;
	int		mbeginy;
	int		mbeginx;
	int		space;
	int		spacex;
	int		spacey;
	int		zinc;
	int		dp;
	char	*file;
}			t_mlx;


/*
**		void functions
*/

void		ft_brestracing(t_mlx *mlx, int i, int beginx, int beginy);
void		ft_resetwin(t_mlx *mlx);
void		left(t_mlx *mlx);
void		right(t_mlx *mlx);
void		up(t_mlx *mlx);
void		down(t_mlx *mlx);
void		hup(t_mlx *mlx);
void		hdown(t_mlx *mlx);
void		wup(t_mlx *mlx);
void		wdown(t_mlx *mlx);
void		dupdn(t_mlx *mlx, int i);
void		setmenu(t_mlx *mlx);
void		ft_tabintdel(int **res, int len);
void		ft_dofree(char **line, char ***tmp);
void		get_map(t_mlx *mlx, char *av, int dp);

/*
**		integer functions
*/

int			ft_getimage(t_mlx *mlx, char *file);
int			ft_getkey(int keycode, t_mlx *mlx);
int			check_error(char *file);

/*
 **		structures functions
 */

t_mlx		*ft_getmap(t_mlx *mlx, char *file, int dp);

#endif

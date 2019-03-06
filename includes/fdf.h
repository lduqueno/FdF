/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <ccharrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 04:43:54 by ccharrie          #+#    #+#             */
/*   Updated: 2019/03/04 16:20:08 by lduqueno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "define.h"
# include "menu.h"
# include <math.h>
# include <mlx.h>

typedef struct	s_count
{
	struct s_count	*next;
	int				number;
	int				count;
}				t_count;

typedef struct	s_mlx
{
	int				xmax;
	int				ymax;
	int				**map;
	int				win_x;
	int				win_y;
	int				img_cl;
	void			*mlx_p;
	void			*win_p;
	int				ispress;
	void			*men_p;
	void			*whe_p;
	unsigned int	*whe_d;
	int				szp;
	int				men_w;
	void			*img_p;
	unsigned int	*img_d;
	int				spacing;
	int				pix_x;
	int				pix_y;
	int				proj;
	int				depth;
	float			theta_x;
	float			theta_y;
	float			theta_z;
	int				z_base;
	int				zmax;
	int				zmin;
}				t_mlx;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				raw_z;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
}				t_point;

int				assert_error(char *str);
int				screen_reset(t_mlx **data);
int				to_parser(char *file, t_mlx **data);
int				to_file(char *file, t_mlx_data **data, char *res);
int				press(int button, int x, int y, t_mlx **data);
int				mouse(int x, int y, t_mlx **data);
int				release(int button, int x, int y, t_mlx **data);
void			print_header(t_mlx **data);
int				keyboard_input(int keycode, t_mlx **data);
void			draw_str_centered(t_mlx_data *mlx, int x, int y, char *s);
int				draw_init(t_mlx **data);
void			scale_view(t_mlx **data);
void			handle_rotate(t_mlx **data, t_point *pnt);
int				get_color(t_mlx **data, int z);
void			print_help(void);
void			coord_init(t_mlx **data, int i, t_point **point);
void			retrieve_most_occurence(t_mlx **data);

#endif

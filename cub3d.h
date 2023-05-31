/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/05/31 16:58:50 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./Libft/srclib/libft.h"
# include "./Libft/gnl/get_next_line.h"
# include <errno.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

extern int worldMap[24][24];

typedef struct s_op
{
	int		mapw;
	int		maph;
	int		screenw;
	int		screenh;
	double	camx;
	double	pospx;
	double	pospy;
	double	dirpx;
	double	dirpy;
	double	planex;
	double	planey;
	double	r_dirx;
	double	r_diry;
	double	mvspeed;
	double	rotspeed;
}	t_op;

typedef struct s_dda
{
	int		mapx;
	int		mapy;
	double	delta_x;
	double	delta_y;
	double	side_disx;
	double	side_disy;
	int		stepX;
	int		stepY;
	int		walldis;
	int		is_wall;
	int		wallside;
	double	ppwall_dist;
	int		linehe;
	int		draw_start;
	int		draw_end;
}	t_dda;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_cub
{
	int		he;
	int		wi;
	void	*mlx;
	void	*win;
	t_op	ray;
	t_data	*img;
	t_dda	dda;
}	t_cub;


int		keyhook(int keycode, t_cub *cub);
int		exitcub(int keycode, t_cub *cub);
void	keycode_rotate(int keycode, t_cub *cub);
void	keycode_move(int keycode, t_cub *cub);
void	raytracing(t_cub	*cub);

void	get_sidedist(t_cub *cub, t_dda *dda);
void	get_disttowall(t_cub *cub, t_dda *dda);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_colors(t_cub *cub, t_dda *dda, int x);
void	dda_algo(t_cub	*cub, t_dda *dda, int x);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 13:50:15 by hdiot            ###   ########.fr       */
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

typedef struct s_map
{
	int		countno;
	int		countso;
	int		countwe;
	int		countea;
	int		countf;
	int		countc;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	char	orientation;
	int		x;
	int		y;
	int		j;
	int		**tab;
	int		rgbf[4];
	int		rgbc[4];
	int		longe;
	int		large;
}					t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_tex
{
	int		texx;
	int		texy;
	double	step;
	double	texpos;
	t_data	*s;
	t_data	*n;
	t_data	*e;
	t_data	*w;	
	int		*tcolor;
}	t_tex;

typedef struct s_op
{
	int		mapw;
	int		maph;
	int		screenw;
	int		screenh;
	int		texhe;
	int		texwi;
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
	int		stepx;
	int		stepy;
	int		walldis;
	int		is_wall;
	int		wallside;
	double	ppwall_dist;
	int		linehe;
	int		draw_start;
	int		draw_end;
}	t_dda;

typedef struct s_info
{
	int		fl[3];
	int		cel[3];
	double	pos_x;
	double	pos_y;
	char	orient;
}	t_info;

typedef struct s_cub
{
	int		he;
	int		wi;
	void	*mlx;
	void	*win;
	t_info	info;
	t_tex	text;
	t_op	ray;
	t_data	*img;
	t_dda	dda;
	t_map	data;
}	t_cub;

int		checkerr(char *file, int ac);
int		parsing(int ac, char **av, t_map *data);
int		ft_walltextno(char *crd, char *str, t_map *data, int i);
int		ft_walltextso(char *crd, char *str, t_map *data, int i);
int		ft_walltextwe(char *crd, char *str, t_map *data, int i);
int		ft_walltextea(char *crd, char *str, t_map *data, int i);
int		ft_walltextf(char *crd, char *str, t_map *data, int i);
int		ft_walltextc(char *crd, char *str, t_map *data, int i);
int		ft_checkalltext(t_map *data);
void	ft_freeall(t_map data);
t_map	ft_takecoord(t_map *data, char **str);
void	ft_printdata(t_map data, char **d);
int		ft_checkwall(char **map, int i, int j, int l);
t_map	ft_array(t_map *data);
void	ft_freechar(t_map data);
int		ft_checkcount(t_map *data);
void	ft_initrgb(t_map *data);

int		keyhook(int keycode, t_cub *cub);
void	recupposp(t_cub *cub, int x, int y, char pp);
void	exitcub(t_cub *cub);
void	keycode_rotate(int keycode, t_cub *cub);
void	keycode_move(int keycode, t_cub *cub);
void	move2(int keycode, t_cub *cub);
void	raytracing(t_cub	*cub);
void	orientation2(t_cub *cub);
double	init_pos(double pos);
void	orientation(t_cub *cub);
void	inittexture(t_cub *cub);
int		close_all(t_cub *cub);
void	recup_color_fl(t_cub *cub, int r, int g, int b);
void	recup_color_cel(t_cub *cub, int r, int g, int b);

int		calculatergb(int r, int g, int b);
void	get_sidedist(t_cub *cub, t_dda *dda);
void	get_disttowall(t_cub *cub, t_dda *dda);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_colors(t_cub *cub, t_dda *dda, int x, int j);
void	dda_algo(t_cub	*cub, t_dda *dda, int x);
void	get_texturecolor(t_cub *cub, t_dda *dda);
void	get_bittexture(t_cub *cub, t_dda *dda);
void	recupmapsize(t_cub *cub, int x, int y);

#endif
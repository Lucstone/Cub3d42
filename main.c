/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/05/30 12:33:09 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[24][24]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	init_op(t_cub *cub)
{
	cub->he = 480;
	cub->wi = 640;
	cub->ray.maph = 24;
	cub->ray.mapw = 24;
	cub->ray.screenh = 0;
	cub->ray.screenw = 0;
	cub->ray.pospx = 22;
	cub->ray.pospy = 12;
	cub->ray.dirpx = -1;
	cub->ray.dirpy = 0;
	cub->ray.planex = 0;
	cub->ray.planey = 0.66;
	cub->ray.rotspeed = 0.06;
	cub->ray.mvspeed = 0.2;
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->wi, cub->he, \
		"Piment y poak mon guele");
	cub->img = malloc(sizeof(t_data));
	if (!cub->img)
		exit(EXIT_FAILURE);
	cub->img->img = mlx_new_image(cub->mlx, cub->wi, cub->he);
	cub->img->addr = mlx_get_data_addr(cub->img->img, \
	&cub->img->bits_per_pixel, &cub->img->line_length, &cub->img->endian);
}

void	get_sidedist(t_cub *cub, t_dda *dda)
{
	if (cub->ray.r_dirx < 0)
	{
		dda->stepX = -1;
		dda->side_disx = (cub->ray.pospx - dda->mapx) * dda->delta_x;
	}
	else
	{
		dda->stepX = 1;
		dda->side_disx = (dda->mapx + 1 - cub->ray.pospx) * dda->delta_x;
	}
	if (cub->ray.r_diry < 0)
	{
		dda->stepY = -1;
		dda->side_disy = (cub->ray.pospy - dda->mapy) * dda->delta_y;
	}
	else
	{
		dda->stepY = 1;
		dda->side_disy = (dda->mapy + 1 - cub->ray.pospy) * dda->delta_y;
	}
}

void	get_disttowall(t_cub *cub, t_dda *dda)
{
	while (!dda->is_wall)
	{
		if (dda->side_disx < dda->side_disy)
		{
			dda->side_disx += dda->delta_x;
			dda->mapx += dda->stepX;
			dda->wallside = 0;
		}
		else
		{
			dda->side_disy += dda->delta_y;
			dda->mapy += dda->stepY;
			dda->wallside = 1;
		}
		if (worldMap[dda->mapx][dda->mapy] > 0)
			dda->is_wall = 1;
	}
	if (dda->wallside == 0)
		dda->ppwall_dist = /*(dda->mapx - cub->ray.pospx 
			+ (1 - dda->stepX) / 2) / cub->ray.r_dirx;*/dda->side_disx - dda->delta_x;
	else
		dda->ppwall_dist = /*(dda->mapy - cub->ray.pospy 
			+ (1 - dda->stepY) / 2) / cub->ray.r_diry;*/dda->side_disy - dda->delta_y;
	dda->linehe = (int)(cub->he / dda->ppwall_dist);
	dda->draw_start = -dda->linehe / 2 + cub->he / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = dda->linehe / 2 + cub->he / 2;
	if (dda->draw_end >= cub->he)
		dda->draw_end = cub->he - 1;
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_colors(t_cub *cub, t_dda *dda, int x)
{
	int	y;
	int	j;
	int	k;
	int	color;
	
	if (worldMap[dda->mapx][dda->mapy] == 1)
		color = 0xFF0000;
	if (worldMap[dda->mapx][dda->mapy] == 2)
		color = 0xFF00;
	if (worldMap[dda->mapx][dda->mapy] == 3)
		color = 0xFF000;
	if (worldMap[dda->mapx][dda->mapy] == 4)
		color = 0xFF0;
	if (dda->wallside == 1)
		color = color / 2;
	j = 0;
	y = dda->draw_start;
	while (j < y)
	{	
		ft_mlx_pixel_put(cub->img, x, j, 0x87CEEB);
		j++;
	}
	while (y < dda->draw_end)
	{	
		ft_mlx_pixel_put(cub->img, x, y, color);
		y++;
	}	
	k = y;
	while (k < cub->he)
	{	
		ft_mlx_pixel_put(cub->img, x, k, 0x8B4513);
		k++;
	}

}

void	dda_algo(t_cub	*cub, t_dda *dda, int x)
{
	
	dda->mapx = (int)cub->ray.pospx;
	dda->mapy = (int)cub->ray.pospy;
	dda->delta_x = fabs(1 / cub->ray.r_dirx);
	dda->delta_y = fabs(1 / cub->ray.r_diry);
	dda->is_wall = 0;
	get_sidedist(cub, dda);
	get_disttowall(cub, dda);
	get_colors(cub, dda, x);
}

void	raytracing(t_cub	*cub)
{
	int x;

	x = -1;
	while (++x < cub->wi)
	{
		cub->ray.camx = 2 * x / (double)cub->wi - 1;
		cub->ray.r_dirx = cub->ray.dirpx + cub->ray.planex * cub->ray.camx;
		cub->ray.r_diry = cub->ray.dirpy + cub->ray.planey * cub->ray.camx; //calcul du rayon de la camera
		dda_algo(cub, &cub->dda, x); //algo distance mur - joueur
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
}

void	keycode_move(int keycode, t_cub *cub)
{
	if (keycode == 122) // nord
	{	
		cub->ray.pospx += cub->ray.dirpx * cub->ray.mvspeed;
		cub->ray.pospy += cub->ray.dirpy * cub->ray.mvspeed;
	}
	if (keycode == 113) // ouest
	{	
		cub->ray.pospx -= cub->ray.dirpy * cub->ray.mvspeed;
		cub->ray.pospy += cub->ray.dirpx * cub->ray.mvspeed;
	}
	if (keycode == 115)	// sud
	{	
		cub->ray.pospx -= cub->ray.dirpx * cub->ray.mvspeed;		cub->ray.pospy += cub->ray.dirpy * cub->ray.mvspeed;
		cub->ray.pospy -= cub->ray.dirpy * cub->ray.mvspeed;

	}	
	if (keycode == 100)	// est
	{	
		cub->ray.pospx += cub->ray.dirpy * cub->ray.mvspeed;
		cub->ray.pospy -= cub->ray.dirpx * cub->ray.mvspeed;
	}
}

void	keycode_rotate(int keycode, t_cub *cub)
{
	double	olddirx;
	double	oldplanex;
	
	olddirx = cub->ray.dirpx;
	oldplanex = cub->ray.planex;
	if (keycode == 65363) // droite
	{
		cub->ray.dirpx = cub->ray.dirpx * cos(-cub->ray.rotspeed) - cub->ray.dirpy * sin(-cub->ray.rotspeed);
		cub->ray.dirpy = olddirx * sin(-cub->ray.rotspeed) + cub->ray.dirpy * cos(-cub->ray.rotspeed);
		cub->ray.planex = oldplanex * cos(-cub->ray.rotspeed) - cub->ray.planey * sin(-cub->ray.rotspeed);
		cub->ray.planey = oldplanex * sin(-cub->ray.rotspeed) + cub->ray.planey * cos(-cub->ray.rotspeed);
	}
	if (keycode == 65361) // gauche
	{
		cub->ray.dirpx = cub->ray.dirpx * cos(cub->ray.rotspeed) - cub->ray.dirpy * sin(cub->ray.rotspeed);
		cub->ray.dirpy = olddirx * sin(cub->ray.rotspeed) + cub->ray.dirpy * cos(cub->ray.rotspeed);
		cub->ray.planex = oldplanex * cos(cub->ray.rotspeed) - cub->ray.planey * sin(cub->ray.rotspeed);
		cub->ray.planey = oldplanex * sin(cub->ray.rotspeed) + cub->ray.planey * cos(cub->ray.rotspeed);
	}
}

int	exitcub(int keycode, t_cub *cub)
{
	(void)keycode;
	mlx_clear_window(cub->mlx, cub->win);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img->img);
	exit(0);
}

int	keyhook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		exitcub(keycode, cub);
	keycode_move(keycode, cub);
	keycode_rotate(keycode, cub);
	mlx_clear_window(cub->mlx, cub->win);
	raytracing(cub);
	return (0);
}

void	cub3d(void)
{
	t_cub	cub;

	init_op(&cub);
	raytracing(&cub);
	mlx_hook(cub.win, 2, 1L << 0, keyhook, &cub);
	//mlx_hook(cub.win, 17, 0, exitcub, &cub);
	mlx_loop(cub.mlx);
}

int main(void)
{
	cub3d();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/05/26 16:43:54 by hdiot            ###   ########.fr       */
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
	cub->ray.time = 0;
	cub->ray.oldtime = 0;
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

void	dda_algo(t_cub	*cub, int x)
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
	(void)x;

	mapx = cub->ray.pospx;
	mapy = cub->ray.pospy;
	delta_x = fabs(1 / cub->ray.r_dirx);
	delta_y = fabs(1 / cub->ray.r_diry);
	
	printf("deltaX %f\ndeltaY %f\n\n", delta_x, delta_y);
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
		//printf(" CamX %f\nRayonX %f\nRayonY %f\n-----------\n", cub->ray.camx, cub->ray.r_dirx, cub->ray.r_diry);
		dda_algo(cub, x); //algo distance mur - joueur
	}
}

void	cub3d(void)
{
	t_cub	cub;

	init_op(&cub);
	raytracing(&cub);
	mlx_loop(cub.mlx);
}

int main(void)
{
	cub3d();
	return (0);
}

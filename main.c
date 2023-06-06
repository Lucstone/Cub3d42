/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 12:30:20 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[24][24] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	init_op(t_cub *cub)
{
	cub->wi = 1080;
	cub->he = 920;
	recupmapsize(cub, 24, 24);
	cub->ray.texwi = 64;
	cub->ray.texhe = 64;
	orientation(cub);
	cub->ray.pospx = init_pos(cub->info.pos_x);
	cub->ray.pospy = init_pos(cub->info.pos_y);
	cub->ray.rotspeed = 0.06;
	cub->ray.mvspeed = 0.4;
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->wi, cub->he, \
		"Cub3D");
	cub->img = malloc(sizeof(t_data));
	if (!cub->img)
		exit(EXIT_FAILURE);
	cub->img->img = mlx_new_image(cub->mlx, cub->wi, cub->he);
	cub->img->addr = mlx_get_data_addr(cub->img->img, \
	&cub->img->bits_per_pixel, &cub->img->line_length, &cub->img->endian);
}

void	raytracing(t_cub	*cub)
{
	int	x;

	x = -1;
	while (++x < cub->wi)
	{
		cub->ray.camx = 2 * x / (double)cub->wi - 1;
		cub->ray.r_dirx = cub->ray.dirpx + cub->ray.planex * cub->ray.camx;
		cub->ray.r_diry = cub->ray.dirpy + cub->ray.planey * cub->ray.camx;
		dda_algo(cub, &cub->dda, x);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
}

void	parse(t_cub *cub)
{
	cub->info.orientation = 'W';
	cub->info.pos_x = 22;
	cub->info.pos_y = 12;
	cub->info.cel[0] = 135;
	cub->info.cel[1] = 206;
	cub->info.cel[2] = 235;
	cub->info.fl[0] = 165;
	cub->info.fl[1] = 42;
	cub->info.fl[2] = 42;
}

int	calculatergb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	cub3d(void)
{
	t_cub	cub;

	parse(&cub);
	init_op(&cub);
	inittexture(&cub);
	raytracing(&cub);
	mlx_hook(cub.win, 2, 1L << 0, keyhook, &cub);
	mlx_hook(cub.win, 17, 0, close_all, &cub);
	mlx_loop(cub.mlx);
}

int	main(void)
{
	cub3d();
	return (0);
}

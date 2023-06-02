/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/02 17:14:45 by hdiot            ###   ########.fr       */
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
	cub->wi = 640;
	cub->he = 480;
	cub->ray.maph = 24;
	cub->ray.mapw = 24;
	cub->ray.texwi = 64;
	cub->ray.texhe = 64;
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
	cub->text.e = malloc(sizeof(t_data));
	cub->text.s = malloc(sizeof(t_data));
	cub->text.n = malloc(sizeof(t_data));
	cub->text.w = malloc(sizeof(t_data));
	cub->img->img = mlx_new_image(cub->mlx, cub->wi, cub->he);
	cub->img->addr = mlx_get_data_addr(cub->img->img, \
	&cub->img->bits_per_pixel, &cub->img->line_length, &cub->img->endian);
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

int	close_all(t_cub *cub)
{
	exitcub(cub);
	return (0);
}

void	inittexture(t_cub *cub)
{
	cub->text.n->img = mlx_xpm_file_to_image(cub->mlx, "./bluestone.xpm", \
		&cub->ray.texwi, &cub->ray.texhe);
	cub->text.s->img = mlx_xpm_file_to_image(cub->mlx, "./wood.xpm", \
		&cub->ray.texwi, &cub->ray.texhe);
	cub->text.w->img = mlx_xpm_file_to_image(cub->mlx, "./greystone.xpm", \
		&cub->ray.texwi, &cub->ray.texhe);
	cub->text.e->img = mlx_xpm_file_to_image(cub->mlx, "./redbrick.xpm", \
		&cub->ray.texwi, &cub->ray.texhe);
	cub->text.n->addr = mlx_get_data_addr(cub->text.n->img, &cub->text.n->bits_per_pixel, \
		&cub->text.n->line_length, &cub->text.n->endian);
	cub->text.w->addr = mlx_get_data_addr(cub->text.w->img, &cub->text.w->bits_per_pixel, \
		&cub->text.w->line_length, &cub->text.w->endian);
	cub->text.e->addr = mlx_get_data_addr(cub->text.e->img, &cub->text.e->bits_per_pixel, \
		&cub->text.e->line_length, &cub->text.e->endian);
	cub->text.s->addr = mlx_get_data_addr(cub->text.s->img, &cub->text.s->bits_per_pixel, \
		&cub->text.s->line_length, &cub->text.s->endian);
	
}

void	cub3d(void)
{
	t_cub	cub;

	init_op(&cub);
	inittexture(&cub);
	raytracing(&cub);
	mlx_hook(cub.win, 2, 1L << 0, keyhook, &cub);
	mlx_hook(cub.win, 17, 0, close_all, &cub);
	mlx_loop(cub.mlx);
}

int main(void)
{
	cub3d();
	return (0);
}

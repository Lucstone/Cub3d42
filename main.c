/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 11:46:55 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_op(t_cub *cub)
{
	cub->wi = 640;
	cub->he = 480;
	recupmapsize(cub, cub->data.longe, cub->data.large);
	cub->ray.texwi = 64;
	cub->ray.texhe = 64;
	recupposp(cub, cub->data.x, cub->data.y, cub->data.orientation);
	orientation(cub);
	cub->ray.pospx = init_pos(cub->info.pos_x) + 0.2;
	cub->ray.pospy = init_pos(cub->info.pos_y) + 0.2;
	printf("pospy %f pospx %f\n", cub->ray.pospy, cub->ray.pospx);
	cub->ray.rotspeed = 0.12;
	cub->ray.mvspeed = 0.2;
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
	recup_color_cel(cub, cub->data.rgbc[0], cub->data.rgbc[1], \
		cub->data.rgbc[2]);
	recup_color_fl(cub, cub->data.rgbf[0], cub->data.rgbf[1], \
		cub->data.rgbf[2]);
}

void	cub3d(t_cub *cub)
{
	parse(cub);
	init_op(cub);
	inittexture(cub);
	raytracing(cub);
	mlx_hook(cub->win, 2, 1L << 0, keyhook, cub);
	mlx_hook(cub->win, 17, 0, close_all, cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (checkerr(av[1], ac) == 1)
		return (1);
	if (parsing(ac, av, &cub.data) == 1)
		return (1);
	cub3d(&cub);
	return (0);
}

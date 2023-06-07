/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:49:32 by hdiot             #+#    #+#             */
/*   Updated: 2023/06/07 11:58:23 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_bittexture(t_cub *cub, t_dda *dda)
{
	double	wallx;

	if (dda->wallside == 0)
		wallx = cub->ray.pospy + dda->ppwall_dist * cub->ray.r_diry;
	else
		wallx = cub->ray.pospx + dda->ppwall_dist * cub->ray.r_dirx;
	wallx -= floor(wallx);
	cub->text.texx = (int)(wallx * cub->ray.texwi);
	if (cub->dda.wallside == 0 && cub->ray.r_diry > 0)
		cub->text.texx = cub->ray.texwi - cub->text.texx - 1;
	if (cub->dda.wallside == 1 && cub->ray.r_diry < 0)
		cub->text.texx = cub->ray.texwi - cub->text.texx - 1;
	cub->text.step = 1.0 * cub->ray.texhe / dda->linehe;
	cub->text.texpos = (dda->draw_start - cub->he / 2 + dda->linehe / 2) \
		* cub->text.step;
}

void	get_texturecolor(t_cub *cub, t_dda *dda)
{
	if (cub->dda.wallside == 1 && (dda->mapy > cub->ray.pospy))
		cub->text.tcolor = (int *)cub->text.e->addr;
	else if (cub->dda.wallside == 1 && (dda->mapy < cub->ray.pospy))
		cub->text.tcolor = (int *)cub->text.w->addr;
	else if (cub->dda.wallside == 0 && (dda->mapx > cub->ray.pospx))
		cub->text.tcolor = (int *)cub->text.s->addr;
	else
		cub->text.tcolor = (int *)cub->text.n->addr;
}

void	initdatatexture(t_cub *cub)
{
	cub->text.w->img = mlx_xpm_file_to_image(cub->mlx, cub->data.we, \
		&cub->ray.texwi, &cub->ray.texhe);
	if (!cub->text.w->img)
		exitcub(cub);
	cub->text.e->img = mlx_xpm_file_to_image(cub->mlx, cub->data.ea, \
		&cub->ray.texwi, &cub->ray.texhe);
	if (!cub->text.e->img)
		exitcub(cub);
	cub->text.n->addr = mlx_get_data_addr(cub->text.n->img, \
		&cub->text.n->bits_per_pixel, \
		&cub->text.n->line_length, &cub->text.n->endian);
	cub->text.w->addr = mlx_get_data_addr(cub->text.w->img, \
		&cub->text.w->bits_per_pixel, \
		&cub->text.w->line_length, &cub->text.w->endian);
	cub->text.e->addr = mlx_get_data_addr(cub->text.e->img, \
		&cub->text.e->bits_per_pixel, \
		&cub->text.e->line_length, &cub->text.e->endian);
	cub->text.s->addr = mlx_get_data_addr(cub->text.s->img, \
		&cub->text.s->bits_per_pixel, \
		&cub->text.s->line_length, &cub->text.s->endian);
}

void	inittexture(t_cub *cub)
{
	cub->text.e = malloc(sizeof(t_data));
	if (!cub->text.e)
		perror("Malloc error\n");
	cub->text.s = malloc(sizeof(t_data));
	if (!cub->text.s)
		perror("Malloc error\n");
	cub->text.n = malloc(sizeof(t_data));
	if (!cub->text.n)
		perror("Malloc error\n");
	cub->text.w = malloc(sizeof(t_data));
	if (!cub->text.w)
		perror("Malloc error\n");
	cub->text.n->img = mlx_xpm_file_to_image(cub->mlx, cub->data.no, \
		&cub->ray.texwi, &cub->ray.texhe);
	if (!cub->text.n->img)
		exitcub(cub);
	cub->text.s->img = mlx_xpm_file_to_image(cub->mlx, cub->data.so, \
		&cub->ray.texwi, &cub->ray.texhe);
	if (!cub->text.s->img)
		exitcub(cub);
	initdatatexture(cub);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:38:29 by hdiot             #+#    #+#             */
/*   Updated: 2023/06/02 17:16:16 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	get_texturecolor(t_cub *cub, t_dda *dda)
{
	if (cub->dda.wallside == 1 && (dda->mapy > cub->ray.pospy))
		cub->text.tcolor = (int *)cub->text.s->addr;
	else if (cub->dda.wallside == 1 && (dda->mapy < cub->ray.pospy))
		cub->text.tcolor = (int *)cub->text.n->addr;
	else if (cub->dda.wallside == 0 && (dda->mapx > cub->ray.pospx))
		cub->text.tcolor = (int *)cub->text.e->addr;
	else 
		cub->text.tcolor = (int *)cub->text.w->addr;
}

void	get_colors(t_cub *cub, t_dda *dda, int x)
{
	int	y;
	int	j;
	int	k;

	j = 0;
	y = dda->draw_start;
	while (j < y)
	{	
		ft_mlx_pixel_put(cub->img, x, j, 0x87CEEB);
		j++;
	}
	while (y < dda->draw_end)
	{	
		cub->text.texy = (int)cub->text.texpos & (cub->ray.texhe - 1);
		cub->text.texpos += cub->text.step;
		ft_mlx_pixel_put(cub->img, x, y, cub->text.tcolor[cub->text.texy * cub->ray.texhe + cub->text.texx]);
		y++;
	}
	k = y;
	while (k < cub->he)
	{	
		ft_mlx_pixel_put(cub->img, x, k, 0x8B4513);
		k++;
	}
}

void	get_bittexture(t_cub *cub, t_dda *dda)
{
	double	wallx;
	
	if (dda->wallside == 0)
		wallx = cub->ray.pospy + dda->ppwall_dist * cub->ray.r_diry;
	else
	 	wallx = cub->ray.pospx + dda->ppwall_dist * cub->ray.r_dirx;
	wallx -= floor(wallx);
	cub->text.texx = (int)(wallx * cub->ray.texwi);
	if (cub->dda.wallside == 0 && cub->ray.r_dirx > 0)
		cub->text.texx = cub->ray.texwi - cub->text.texx - 1;
	if (cub->dda.wallside == 1 && cub->ray.r_dirx < 0)
		cub->text.texx = cub->ray.texwi - cub->text.texx - 1;
	cub->text.step = 1.0 * cub->ray.texhe / dda->linehe;
	cub->text.texpos = (dda->draw_start - cub->he / 2 + dda->linehe / 2) \
		* cub->text.step;
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
	get_bittexture(cub, dda);
	get_texturecolor(cub, dda);
	get_colors(cub, dda, x);
}

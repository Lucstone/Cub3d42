/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:38:29 by hdiot             #+#    #+#             */
/*   Updated: 2023/06/06 12:29:39 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sidedist(t_cub *cub, t_dda *dda)
{
	if (cub->ray.r_dirx < 0)
	{
		dda->stepx = -1;
		dda->side_disx = (cub->ray.pospx - dda->mapx) * dda->delta_x;
	}
	else
	{
		dda->stepx = 1;
		dda->side_disx = (dda->mapx + 1 - cub->ray.pospx) * dda->delta_x;
	}
	if (cub->ray.r_diry < 0)
	{
		dda->stepy = -1;
		dda->side_disy = (cub->ray.pospy - dda->mapy) * dda->delta_y;
	}
	else
	{
		dda->stepy = 1;
		dda->side_disy = (dda->mapy + 1 - cub->ray.pospy) * dda->delta_y;
	}
}

void	check_wall(t_cub *cub, t_dda *dda)
{
	if (dda->wallside == 0)
		dda->ppwall_dist = dda->side_disx - dda->delta_x;
	else
		dda->ppwall_dist = dda->side_disy - dda->delta_y;
	dda->linehe = (int)(cub->he / dda->ppwall_dist);
	dda->draw_start = -dda->linehe / 2 + cub->he / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = dda->linehe / 2 + cub->he / 2;
	if (dda->draw_end >= cub->he)
		dda->draw_end = cub->he - 1;
}

void	get_disttowall(t_cub *cub, t_dda *dda)
{
	while (!dda->is_wall)
	{
		if (dda->side_disx < dda->side_disy)
		{
			dda->side_disx += dda->delta_x;
			dda->mapx += dda->stepx;
			dda->wallside = 0;
		}
		else
		{
			dda->side_disy += dda->delta_y;
			dda->mapy += dda->stepy;
			dda->wallside = 1;
		}
		if (worldMap[dda->mapx][dda->mapy] == 1)
			dda->is_wall = 1;
	}
	check_wall(cub, dda);
}

void	get_colors(t_cub *cub, t_dda *dda, int x, int j)
{
	int	y;
	int	k;

	y = dda->draw_start;
	while (j < y)
	{	
		ft_mlx_pixel_put(cub->img, x, j, \
			calculatergb(cub->info.cel[0], cub->info.cel[1], cub->info.cel[2]));
		j++;
	}	
	while (y < dda->draw_end)
	{	
		cub->text.texy = (int)cub->text.texpos & (cub->ray.texhe - 1);
		cub->text.texpos += cub->text.step;
		ft_mlx_pixel_put(cub->img, x, y, cub->text.tcolor[cub->text.texy \
			* cub->ray.texhe + cub->text.texx]);
		y++;
	}
	k = y;
	while (k < cub->he)
	{	
		ft_mlx_pixel_put(cub->img, x, k, \
			calculatergb(cub->info.fl[0], cub->info.fl[1], cub->info.fl[2]));
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
	get_bittexture(cub, dda);
	get_texturecolor(cub, dda);
	get_colors(cub, dda, x, 0);
}

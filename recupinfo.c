/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:43:06 by hdiot             #+#    #+#             */
/*   Updated: 2023/06/06 10:19:30 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_all(t_cub *cub)
{
	exitcub(cub);
	return (0);
}

void	move2(int keycode, t_cub *cub)
{
	if (keycode == 1)
	{
		if (worldMap[(int)(cub->ray.pospx - cub->ray.dirpx \
			* (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx -= cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy \
			- cub->ray.dirpy * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy -= cub->ray.dirpy * cub->ray.mvspeed;
	}	
	if (keycode == 0)
	{
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy \
			- cub->ray.dirpx * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy -= cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)(cub->ray.pospx + cub->ray.dirpy \
			* (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx += cub->ray.dirpy * cub->ray.mvspeed;
	}
}

void	orientation2(t_cub *cub)
{
	if (cub->info.orientation == 'E')
	{
		cub->ray.dirpx = 1;
		cub->ray.dirpy = 0;
		cub->ray.planey = 0.66;
		cub->ray.planex = 0;
	}
	else if (cub->info.orientation == 'W')
	{
		cub->ray.dirpx = -1;
		cub->ray.dirpy = 0;
		cub->ray.planey = -0.66;
		cub->ray.planex = 0;
	}
}

void	orientation(t_cub *cub)
{
	if (cub->info.orientation == 'N')
	{
		cub->ray.dirpx = 0;
		cub->ray.dirpy = -1;
		cub->ray.planey = 0;
		cub->ray.planex = 0.66;
	}	
	else if (cub->info.orientation == 'S')
	{
		cub->ray.dirpx = 0;
		cub->ray.dirpy = 1;
		cub->ray.planey = 0;
		cub->ray.planex = -0.66;
	}
	else
		orientation2(cub);
}

double	init_pos(double pos)
{
	return (pos);
}

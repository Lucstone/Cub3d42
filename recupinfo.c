/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:43:06 by hdiot             #+#    #+#             */
/*   Updated: 2023/06/06 16:21:49 by hdiot            ###   ########.fr       */
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
	if (keycode == 2)
	{
		if (cub->data.tab[(int)(cub->ray.pospx - cub->ray.dirpx \
			* (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx -= cub->ray.dirpx * cub->ray.mvspeed;
		if (cub->data.tab[(int)cub->ray.pospx][(int)(cub->ray.pospy \
			- cub->ray.dirpy * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy -= cub->ray.dirpy * cub->ray.mvspeed;
	}	
	if (keycode == 13)
	{
		if (cub->data.tab[(int)cub->ray.pospx][(int)(cub->ray.pospy \
			- cub->ray.dirpx * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy -= cub->ray.dirpx * cub->ray.mvspeed;
		if (cub->data.tab[(int)(cub->ray.pospx + cub->ray.dirpy \
			* (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx += cub->ray.dirpy * cub->ray.mvspeed;
	}
}

void	orientation2(t_cub *cub)
{
	if (cub->info.orient == 'S')
	{
		cub->ray.dirpx = 1;
		cub->ray.dirpy = 0;
		cub->ray.planey = 0.66;
		cub->ray.planex = 0;
	}
	else if (cub->info.orient == 'N')
	{
		cub->ray.dirpx = -1;
		cub->ray.dirpy = 0;
		cub->ray.planey = -0.66;
		cub->ray.planex = 0;
	}
}

void	orientation(t_cub *cub)
{
	if (cub->info.orient == 'W')
	{
		cub->ray.dirpx = 0;
		cub->ray.dirpy = -1;
		cub->ray.planey = 0;
		cub->ray.planex = 0.66;
	}	
	else if (cub->info.orient == 'E')
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

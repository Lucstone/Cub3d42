/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:29:38 by hdiot             #+#    #+#             */
/*   Updated: 2023/06/03 08:15:30 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keycode_move(int keycode, t_cub *cub)
{
	if (keycode == 122)
	{
		if (worldMap[(int)(cub->ray.pospx + cub->ray.dirpx \
			* (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx += cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy \
			+ cub->ray.dirpy * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy += cub->ray.dirpy * cub->ray.mvspeed;
	}
	if (keycode == 100)
	{
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy \
			+ cub->ray.dirpx * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy += cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)(cub->ray.pospx - cub->ray.dirpy \
			* (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx -= cub->ray.dirpy * cub->ray.mvspeed;
	}
	move2(keycode, cub);
}

void	keycode_rotate2(int keycode, t_cub *cub, double olddirx, double oldpl)
{
	if (keycode == 65363)
	{
		cub->ray.dirpx = cub->ray.dirpx * cos(cub->ray.rotspeed) \
			- cub->ray.dirpy * sin(cub->ray.rotspeed);
		cub->ray.dirpy = olddirx * sin(cub->ray.rotspeed) \
			+ cub->ray.dirpy * cos(cub->ray.rotspeed);
		cub->ray.planex = oldpl * cos(cub->ray.rotspeed) \
			- cub->ray.planey * sin(cub->ray.rotspeed);
		cub->ray.planey = oldpl * sin(cub->ray.rotspeed) \
			+ cub->ray.planey * cos(cub->ray.rotspeed);
	}
}

void	keycode_rotate(int keycode, t_cub *cub)
{
	double	olddirx;
	double	oldplanex;

	olddirx = cub->ray.dirpx;
	oldplanex = cub->ray.planex;
	if (keycode == 65361)
	{
		cub->ray.dirpx = cub->ray.dirpx * cos(-cub->ray.rotspeed) \
			- cub->ray.dirpy * sin(-cub->ray.rotspeed);
		cub->ray.dirpy = olddirx * sin(-cub->ray.rotspeed) \
			+ cub->ray.dirpy * cos(-cub->ray.rotspeed);
		cub->ray.planex = oldplanex * cos(-cub->ray.rotspeed) \
			- cub->ray.planey * sin(-cub->ray.rotspeed);
		cub->ray.planey = oldplanex * sin(-cub->ray.rotspeed) \
			+ cub->ray.planey * cos(-cub->ray.rotspeed);
	}
	else
		keycode_rotate2(keycode, cub, olddirx, oldplanex);
}

void	exitcub(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img->img);
	mlx_destroy_window(cub->mlx, cub->win);
	free(cub->img);
	free(cub->mlx);
	exit(0);
}

int	keyhook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		exitcub(cub);
	keycode_move(keycode, cub);
	keycode_rotate(keycode, cub);
	mlx_clear_window(cub->mlx, cub->win);
	raytracing(cub);
	return (0);
}

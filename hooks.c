/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:29:38 by hdiot             #+#    #+#             */
/*   Updated: 2023/05/31 19:44:58 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keycode_move(int keycode, t_cub *cub)
{
	if (keycode == 122) // nord
	{
		if (worldMap[(int)(cub->ray.pospx + cub->ray.dirpx * (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx += cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy + cub->ray.dirpy * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy += cub->ray.dirpy * cub->ray.mvspeed;
	}
	if (keycode == 113) // ouest
	{
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy + cub->ray.dirpx * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy += cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)(cub->ray.pospx - cub->ray.dirpy * (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx -= cub->ray.dirpy * cub->ray.mvspeed;
	}
	if (keycode == 115)	// sud
	{
		if (worldMap[(int)(cub->ray.pospx - cub->ray.dirpx * (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx -= cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy - cub->ray.dirpy * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy -= cub->ray.dirpy * cub->ray.mvspeed;
	}	
	if (keycode == 100)	// est
	{
		if (worldMap[(int)cub->ray.pospx][(int)(cub->ray.pospy - cub->ray.dirpx * (cub->ray.mvspeed + 0.1))] == 0)
			cub->ray.pospy -= cub->ray.dirpx * cub->ray.mvspeed;
		if (worldMap[(int)(cub->ray.pospx + cub->ray.dirpy * (cub->ray.mvspeed + 0.1))][(int)cub->ray.pospy] == 0)
			cub->ray.pospx += cub->ray.dirpy * cub->ray.mvspeed;
	}
}

void	keycode_rotate(int keycode, t_cub *cub)
{
	double	olddirx;
	double	oldplanex;
	
	olddirx = cub->ray.dirpx;
	oldplanex = cub->ray.planex;
	if (keycode == 65363) // droite
	{
		cub->ray.dirpx = cub->ray.dirpx * cos(-cub->ray.rotspeed) - cub->ray.dirpy * sin(-cub->ray.rotspeed);
		cub->ray.dirpy = olddirx * sin(-cub->ray.rotspeed) + cub->ray.dirpy * cos(-cub->ray.rotspeed);
		cub->ray.planex = oldplanex * cos(-cub->ray.rotspeed) - cub->ray.planey * sin(-cub->ray.rotspeed);
		cub->ray.planey = oldplanex * sin(-cub->ray.rotspeed) + cub->ray.planey * cos(-cub->ray.rotspeed);
	}
	if (keycode == 65361) // gauche
	{
		cub->ray.dirpx = cub->ray.dirpx * cos(cub->ray.rotspeed) - cub->ray.dirpy * sin(cub->ray.rotspeed);
		cub->ray.dirpy = olddirx * sin(cub->ray.rotspeed) + cub->ray.dirpy * cos(cub->ray.rotspeed);
		cub->ray.planex = oldplanex * cos(cub->ray.rotspeed) - cub->ray.planey * sin(cub->ray.rotspeed);
		cub->ray.planey = oldplanex * sin(cub->ray.rotspeed) + cub->ray.planey * cos(cub->ray.rotspeed);
	}
}

void	exitcub(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->win);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img->img);
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
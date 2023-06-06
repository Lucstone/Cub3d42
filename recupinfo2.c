/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupinfo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:20:57 by hdiot             #+#    #+#             */
/*   Updated: 2023/06/06 12:33:50 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	recupmapsize(t_cub *cub, int x, int y)
{
	cub->ray.mapw = x;
	cub->ray.maph = y;
}

void	recup_color_fl(t_cub *cub, int r, int g, int b)
{
	cub->info.fl[0] = r;
	cub->info.fl[1] = g;
	cub->info.fl[2] = b;
}

void	recup_color_cel(t_cub *cub, int r, int g, int b)
{
	cub->info.cel[0] = r;
	cub->info.cel[1] = g;
	cub->info.cel[2] = b;
}
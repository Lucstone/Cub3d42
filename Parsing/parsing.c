/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:02:30 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 13:05:23 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parsing(int ac, char **av, t_map *data)
{
	(void) ac;
	ft_initdata(data);
	if (ft_checkmap(av[1], data) == 1)
		return (1);
	if (ft_checkwall(data->map, 0, 0, 0) == 1)
		return (ft_freewall(*data), 1);
	ft_takecoord(data, data->map);
	ft_initrgb(data, 0, 0, 0);
	ft_array(data, 0, 0, 0);
	return (0);
}

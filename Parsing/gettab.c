/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:26:57 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 10:25:47 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	ft_array(t_map *data, int i, int j, int len)
{
	data->tab = malloc(sizeof(int *) * (data->longe + 1));
	while ((data->longe) > i)
	{
		data->tab[i] = malloc(sizeof(int) * (data->large + 1));
		len = ft_strlen(data->map[i]);
		while (data->large > j)
		{
			if (j <= len && data->map[i][j] == '1')
				data->tab[i][j] = 1;
			else if (j <= len && data->map[i][j] == '0')
				data->tab[i][j] = 0;
			else if (j <= len && (data->map[i][j] == 'N'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'E'))
				data->tab[i][j] = 0;
			else if (j <= data->large)
				data->tab[i][j] = 5;
			j++;
		}
		j = 0;
		i++;
	}
	data->tab[i] = NULL;
	return (*data);
}

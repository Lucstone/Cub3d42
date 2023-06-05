/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:58:11 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/05 18:11:21 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	ft_array(t_map *data)
{
	int	longline;
	int	i;
	int	j;
	int len;

	
	data->j = 0;
	longline = 0;
	i = 0;
	while(data->map[data->j])
	{
		i = ft_strlen(data->map[data->j]);
		if (longline < i)
			longline = i;
		data->j++;
	}
	data->tab = malloc(sizeof(int *) * (data->j + 1));
	i = 0;
	j = 0;
	while(data->j > i)
	{
		data->tab[i] = malloc(sizeof(int) * (longline + 1));
		len = ft_strlen(data->map[i]);
		while((longline) > j)
		{
			if (j <= len && data->map[i][j] == '1')
				data->tab[i][j] = 1;
			else if (j <= len && data->map[i][j] == '0')
				data->tab[i][j] = 0;
			else if (j <= len && (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'W' || data->map[i][j] == 'E'))
				data->tab[i][j] = 0;
			else if (j <= longline)
				data->tab[i][j] = 5;
			//printf("%d",data->tab[i][j]);
			j++;
		}
		j = 0;
		i++;
		//printf("\n");
	}
	data->tab[i] = NULL;
	return (*data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datainit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:03:09 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 17:59:02 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_initdata(t_map *data)
{
	data->countno = 0;
	data->countso = 0;
	data->countea = 0;
	data->countwe = 0;
	data->countf = 0;
	data->countc = 0;
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->f = NULL;
	data->c = NULL;
	data->x = 0;
	data->y = 0;
	data->longe = 0;
	data->large = 0;
}

t_map	ft_takecoord(t_map *data, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == 'N' || str[i][j] == 'S'
					|| str[i][j] == 'E' || str[i][j] == 'W'))
			{
				data->x = i;
				data->y = j;
				data->orientation = str[i][j];
			}
			j++;
		}
		i++;
	}
	return (*data);
}

void	ft_initrgb(t_map *data, int i, int j, int k)
{
	char	**argf;
	char	**argc;

	argf = ft_split(data->f, ',');
	argc = ft_split(data->c, ',');
	while (argf[i])
	{
		data->rgbf[i] = ft_atoi(argf[i]);
		i++;
	}
	data->rgbf[i] = '\0';
	while (argc[j])
	{
		data->rgbc[j] = ft_atoi(argc[j]);
		j++;
	}
	data->rgbf[j] = '\0';
	while (k < 4)
	{
		free(argf[k]);
		free(argc[k]);
		k++;
	}
	free(argf);
	free(argc);
}

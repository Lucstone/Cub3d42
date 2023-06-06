/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:55:08 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 13:39:31 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	ft_checkwall(char **map, int i, int j, int l)
{
	int	len;

	i = 0;
	while (map[l])
		l++;
	while (map[i])
	{
		j = 0;
		len = ft_strlen(&map[i][j]) - 1;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (j == 0 || i == 0 || i == (l - 1) || len == j)
					return (printf("Error\nWalls not valid\n"), 1);
				if (map[i + 1][j] == 32 || map[i - 1][j] == 32
						|| map[i][j + 1] == 32 || map[i][j - 1] == 32)
					return (printf("Error\nWall not valid\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_initrgb(t_map *data)
{
	int	i;
	char **argf;
	char **argc;

	argf = ft_split(data->f, ',');
	argc = ft_split(data->c, ',');
	i = 0;
	while (argf[i])
	{
		data->rgbf[i] = ft_atoi(argf[i]);
		i++;
	}
	data->rgbf[i] = '\0';
	i = 0;
	while (argc[i])
	{
		data->rgbc[i] = ft_atoi(argc[i]);
		i++;
	}
	data->rgbf[i] = '\0';
	free(argf);
	free(argc);
}

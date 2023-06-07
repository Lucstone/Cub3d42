/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:22:29 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 17:29:27 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
				if ((map[i + 1][j] == 32 || map[i - 1][j] == 32
						|| map[i][j + 1] == 32 || map[i][j - 1] == 32))
					return (printf("Error\nWall not valid\n"), 1);
				if ((map[i + 1][j] == '\n' || map[i - 1][j] == '\n' 
						|| map[i][j + 1] == '\n'  || map[i][j - 1] == '\n'))
					return (printf("Error\nWall not valid\n"), 1);
				if ((map[i + 1][j] == '\0' || map[i - 1][j] == '\0' 
						|| map[i][j + 1] == '\0'  || map[i][j - 1] == '\0'))
					return (printf("Error\nWall not valid\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checkint(char *str, int i, int j, int l)
{
	char	**arg;

	arg = ft_split(str, ',');
	while (str[l])
	{
		if (str[l++] == ',')
			j++;
	}
	if (j != 2)
		return (ft_freeca(arg), printf("Error\nnot a valid color\n"), 1);
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (!(arg[i][j] >= '0' && arg[i][j] <= '9'))
				return (ft_freeca(arg), printf("Error\nnota a valid color\n"), 1);
			j++;
		}
		if (!(ft_atoi(arg[i]) >= 0 && ft_atoi(arg[i]) <= 255))
			return (ft_freeca(arg), printf("Error\nnot a valid color\n"), 1);
		i++;
	}
	return (ft_freeca(arg), 0);
}

int	ft_checkalltext(t_map *data)
{
	if (data->no && ft_checkopen(data->no) == 1)
		return (1);
	if (data->so && ft_checkopen(data->so) == 1)
		return (1);
	if (data->ea && ft_checkopen(data->ea) == 1)
		return (1);
	if (data->we && ft_checkopen(data->we) == 1)
		return (1);
	if (data->f && ft_checkint(data->f, 0, 0, 0) == 1)
		return (1);
	if (data->c && ft_checkint(data->c, 0, 0, 0) == 1)
		return (1);
	return (0);
}

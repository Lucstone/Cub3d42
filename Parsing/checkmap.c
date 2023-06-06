/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:55:08 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 10:47:16 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_checkopen(char *file)
{
	if (open(file, O_DIRECTORY) > 0)
		return (printf("Not a file it's a directory\n"), 1);
	if (open(file, O_RDONLY) < 0)
		return (printf("Error\nfile doesn't exist or no rights\n"), 1);
	return (0);
}

int	verifcub(char *file)
{
	if (ft_strncmp(&file[ft_strlen(file) - 4], ".cub", 4) == 0)
		return (0);
	printf("Error\nNot a .cub file\n");
	return (1);
}

int	checkerr(char *file, int ac)
{
	if (ac != 2)
		return (printf("wrong number of argument\n"), 1);
	if (ft_checkopen(file) == 1)
		return (1);
	if (verifcub(file) == 1)
		return (1);
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
		return (printf("Error\nnot a valid color\n"), 1);
	while (arg[i])
	{
		if (!(ft_atoi(arg[i]) >= 0 && ft_atoi(arg[i]) <= 255))
			return (free(arg), printf("Error\nnot a valid color\n"), 1);
		i++;
	}
	i = 0;
	while (arg[i])
		free(arg[i++]);
	return (free(arg), 0);
}

int	ft_checkalltext(t_map *data)
{
	if (ft_checkopen(data->no) == 1)
		return (1);
	if (ft_checkopen(data->so) == 1)
		return (1);
	if (ft_checkopen(data->ea) == 1)
		return (1);
	if (ft_checkopen(data->we) == 1)
		return (1);
	if (ft_checkint(data->f, 0, 0, 0) == 1)
		return (1);
	if (ft_checkint(data->c, 0, 0, 0) == 1)
		return (1);
	return (0);
}
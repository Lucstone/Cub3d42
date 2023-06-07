/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getchardata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:25:16 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 14:22:29 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_checkispartofmap(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_getcharsize(char *map, t_map *data, int k, int l)
{
	int		fd;
	char	*gnl;
	int		i;

	i = -1;
	fd = open(map, O_RDONLY);
	gnl = get_next_line(fd);
	while (k > ++i)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	i = 0;
	data->large = 0;
	while (gnl != NULL)
	{
		l = (int)ft_strlen(gnl);
		data->longe = ft_checkispartofmap(gnl) + data->longe;
		if (data->large < l)
			data->large = l;
		free(gnl);
		gnl = get_next_line(fd);
		i++;
	}
	free(gnl);
}

int	ft_checkmap(char *map, t_map *data)
{
	int		fd;
	char	*gnl;
	int		i;
	int		k;

	i = 0;
	k = 0;
	fd = open(map, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		if (recupsprites(data, gnl) == 0)
			break ;
		i = i + ft_get_texture(data, gnl);
		k++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	ft_getcharsize(map, data, k, 0);
	if (ft_checkcount(data) == 1 || ft_checkalltext(data) == 1 || i > 0)
		return (free(gnl), ft_putendl_fd("Error\nBad map", 2),
			ft_freechar(*data), 1);
	data->map = tabchar(data, gnl, fd, 0);
	return (0);
}

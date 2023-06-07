/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walltext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:26:22 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 19:51:58 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_walltextno(char *crd, char *str, t_map *data, int i)
{
	data->j = 0;
	if (data->countno < 1)
		data->no = malloc(sizeof(char *) * ft_strlen(str));
	while (data->j < 2)
	{
		if (str[i++] != crd[data->j++])
			return (-1);
	}
	if (str[i] != 32)
		return (-1);
	while (str[i] == 32)
		i++;
	data->j = 0;
	while (str[i] != 32 && str[i] != 10)
		data->no[data->j++] = str[i++];
	data->no[data->j] = 0;
	data->countno++;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_walltextea(char *crd, char *str, t_map *data, int i)
{
	data->j = 0;
	if (data->countea < 1)
		data->ea = malloc(sizeof(char *) * ft_strlen(str));
	while (data->j < 2)
	{
		if (str[i++] != crd[data->j++])
			return (-1);
	}
	if (str[i] != 32)
		return (-1);
	while (str[i] == 32)
		i++;
	data->j = 0;
	while (str[i] != 32 && str[i] != 10)
		data->ea[data->j++] = str[i++];
	data->ea[data->j] = 0;
	data->countea++;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_walltextwe(char *crd, char *str, t_map *data, int i)
{
	data->j = 0;
	if (data->countwe < 1)
		data->we = malloc(sizeof(char *) * ft_strlen(str));
	while (data->j < 2)
	{
		if (str[i++] != crd[data->j++])
			return (-1);
	}
	if (str[i] != 32)
		return (-1);
	while (str[i] == 32)
		i++;
	data->j = 0;
	while (str[i] != 32 && str[i] != 10)
		data->we[data->j++] = str[i++];
	data->we[data->j] = 0;
	data->countwe++;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_walltextso(char *crd, char *str, t_map *data, int i)
{
	data->j = 0;
	if (data->countso < 1)
		data->so = malloc(sizeof(char *) * ft_strlen(str));
	while (data->j < 2)
	{
		if (str[i++] != crd[data->j++])
			return (-1);
	}
	if (str[i] != 32)
		return (-1);
	while (str[i] == 32)
		i++;
	data->j = 0;
	while (str[i] != 32 && str[i] != 10)
		data->so[data->j++] = str[i++];
	data->so[data->j] = 0;
	data->countso++;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
			return (-1);
		i++;
	}
	return (0);
}

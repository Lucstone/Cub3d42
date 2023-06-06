/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walltext2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:09:20 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 11:23:36 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_walltextf(char *crd, char *str, t_map *data, int i)
{
	data->j = 0;
	data->f = malloc(sizeof(char *) * ft_strlen(str));
	while (data->j < 1)
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
		data->f[data->j++] = str[i++];
	data->f[data->j] = 0;
	data->countf++;
	/*if (data->countf > 1)
		return (printf("Error\nInvalid\n"), -1);*/
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_walltextc(char *crd, char *str, t_map *data, int i)
{
	data->j = 0;
	data->c = malloc(sizeof(char *) * ft_strlen(str));
	while (data->j < 1)
	{
		if (str[i++] != crd[data->j++])
			return (-1);
	}
	if (str[i] != 32)
		return (-1);
	while (str[i] == 32 || str[i] == 9)
		i++;
	data->j = 0;
	while (str[i] != 32 && str[i] != 10)
		data->c[data->j++] = str[i++];
	data->c[data->j] = 0;
	data->countc++;
	/*if (data->countc > 1)
		return (printf("Error\nInvalid\n"), -1);*/
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_checkcount(t_map *data)
{
	if (data->countno > 1)
		return (1);
	if (data->countso > 1)
		return (1);
	if (data->countwe > 1)
		return (1);
	if (data->countea > 1)
		return (1);
	if (data->countf > 1)
		return (1);
	if (data->countc > 1)
		return (1);
	return (0);
}

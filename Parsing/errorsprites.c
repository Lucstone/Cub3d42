/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorsprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:53:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 19:56:55 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	recupsprites(t_map *data, char *str)
{
	int	i;

	i = 0;
	while ((str[i] == 32 || str[i] == 10))
		i++;
	if (data->countno == 1 && data->countso == 1 && data->countea == 1
		&& data->countwe == 1 && data->countf == 1 && data->countc == 1)
	{
		if (str[i] == '1')
			return (0);
	}
	return (1);
}

int	ft_get_texture(t_map *data, char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == 'N' && ft_walltextno("NO", str, data, i) == -1)
		return (1);
	else if (str[i] == 'S' && ft_walltextso("SO", str, data, i) == -1)
		return (1);
	else if (str[i] == 'W' && ft_walltextwe("WE", str, data, i) == -1)
		return (1);
	else if (str[i] == 'E' && ft_walltextea("EA", str, data, i) == -1)
		return (1);
	else if (str[i] == 'F' && ft_walltextf("F", str, data, i) == -1)
		return (1);
	else if (str[i] == 'C' && ft_walltextc("C", str, data, i) == -1)
		return (1);
	else if (ft_strncmp("\n", str, 1) && (str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'W' && str[i] != 'E' && str[i] != 'F'
			&& str[i] != 'C'))
		return (1);
	return (0);
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

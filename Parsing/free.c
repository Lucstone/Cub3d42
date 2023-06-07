/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:05 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 17:45:57 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_freechar(t_map data)
{
	if (data.no)
		free(data.no);
	if (data.so)
		free(data.so);
	if (data.we)
		free(data.we);
	if (data.ea)
		free(data.ea);
	if (data.f)
		free(data.f);
	if (data.c)
		free(data.c);
}

void	ft_freeall(t_map data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.map[i])
		free(data.map[i++]);
	free(data.map[i]);
	free(data.map);
	while (j < i)
		free(data.tab[j++]);
	free(data.tab);
	free(data.no);
	free(data.so);
	free(data.we);
	free(data.f);
	free(data.c);
	free(data.ea);
}

void	ft_freeca(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab[i]);
	free(tab);
}

void	ft_freewall(t_map data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.map[i])
	{
		free(data.map[i]);
		i++;
	}
	free(data.map[i]);
	free(data.map);
	free(data.no);
	free(data.so);
	free(data.we);
	free(data.f);
	free(data.c);
	free(data.ea);
}

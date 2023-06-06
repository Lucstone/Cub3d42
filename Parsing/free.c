/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:39:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 13:37:25 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_freeall(t_map data)
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

void	ft_printdata(t_map data, char **d)
{
	printf("y = %d\n", data.y);
	printf("x = %d\n", data.x);
	printf("orientation = %c\n", data.orientation);
	printf("xpmNO = %s\n", data.no);
	printf("xpmSO = %s\n", data.so);
	printf("xpmWE = %s\n", data.we);
	printf("xpmEA = %s\n", data.ea);
	printf("xpmF = %s\n", data.f);
	printf("xpmC = %s\n", data.c);
	int i = 0;
	int longline = 0;
	int l = 0;
	while (d[i])
	{
		printf("%s\n", d[i]);
		l = ft_strlen(d[i]);
		if (longline < l)
			longline = l;
		i++;
	}
	printf("%d\n", i);
	data.longe = longline;
	data.large = i;
	printf("data.longe = %d\n", data.longe);
	printf("data.large = %d\n", data.large);
	int j = 0;
	l = 0;
	while(l < i)
	{
		while((longline) > j)
		{
			printf("%d",data.tab[l][j]);
			j++;
		}
		j = 0;
		printf("\n");
		l++;
	}
	i = 0;
	while (i < 3)
	{
		printf("argf : %d; argc : %d\n", data.rgbf[i], data.rgbc[i]);
		i++;
	}
}

void	ft_freechar(t_map data)
{
	free(data.no);
	free(data.so);
	free(data.we);
	free(data.f);
	free(data.c);
	free(data.ea);
}
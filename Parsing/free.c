/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:39:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/05 18:18:16 by lnaidu           ###   ########.fr       */
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
		//printf("%s\n", d[i]);
		l = ft_strlen(d[i]);
		if (longline < l)
			longline = l;
		i++;
	}
	printf("%d\n", i);
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
}
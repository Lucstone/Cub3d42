/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:06:19 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 18:38:18 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	ft_printdata(t_map data, char **d)
{
	(void) d;
	printf("large = %d\n", data.large);
	printf("longe = %d\n", data.longe);
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
	//printf("%d\n", i);
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

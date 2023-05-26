/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/05/26 17:20:29 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initdata(t_map *data)
{
	data->countNO = 0;
	data->countS0 = 0;
	data->countEA = 0;
	data->countWE = 0;
	data->countF = 0;
	data->countC = 0;
	data->x = 0;
	data->y = 0;
}

int	ft_checkmap(char *map, t_map *data)
{
	int	fd;
	char *gnl;


	fd = open(map, O_RDONLY);
	gnl = get_next_line(fd);
	return (0);
}

int main(int ac, char **av)
{
	if (checkerr(av[1], ac) == 1)
		return(1);
	printf("valid map\n");	
	return(0);
}
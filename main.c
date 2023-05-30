/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:10 by lnaidu            #+#    #+#             */
/*   Updated: 2023/05/30 20:12:01 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initdata(t_map *data)
{
	data->countno = 0;
	data->countso = 0;
	data->countea = 0;
	data->countwe = 0;
	data->countf = 0;
	data->countc = 0;
	data->x = 18;
	data->y = 0;
}

int	ft_get_texture(t_map *data, char *str)
{
	int	i;

	i = 0;
	while ((str[i] == 32 || str[i] == 9))
		i++;
	if (str[i] == 'N' && ft_walltextno("NO", str, data, i) == -1)
		return (printf("Error\nWrong NO texture coordinates\n"), 1);
	else if (str[i] == 'S' && ft_walltextso("SO", str, data, i) == -1)
		return (printf("Error\nWrong SO texture coordinates\n"), 1);
	else if (str[i] == 'W' && ft_walltextwe("WE", str, data, i) == -1)
		return (printf("Error\nWrong WE texture coordinates\n"), 1);
	else if (str[i] == 'E' && ft_walltextea("EA", str, data, i) == -1)
		return (printf("Error\nWrong EA texture coordinates\n"), 1);
	else if (str[i] == 'F' && ft_walltextf("F", str, data, i) == -1)
		return (printf("Error\nWrong F texture coordinates\n"), 1);
	else if (str[i] == 'C' && ft_walltextc("C", str, data, i) == -1)
		return (printf("Error\nWrong C texture coordinates\n"), 1);
	else if (ft_strncmp("\n", str, 1) && (str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'W' && str[i] != 'E' && str[i] != 'F'
			&& str[i] != 'C' && str[i] != '1'))
		return (printf("Error\nNOT a good caractere\n"), 1);
	return (0);
}

int	recupmap(t_map *data, char *str)
{
	int	i;

	i = 0;
	while ((str[i] == 32 || str[i] == 9 || str[i] == 10))
		i++;
	if (data->countno == 1 && data->countso == 1 && data->countea == 1
		&& data->countwe == 1 && data->countf == 1 && data->countc == 1)
	{
		if (str[i] == '1')
		{
			while (str[i])
			{
				if ((str[i] == 32 || str[i] == 9
						|| str[i] == '1' || str[i] == 10))
					i++;
			}
			return (0);
		}
	}
	return (1);
}

int	ft_checkmap(char *map, t_map *data)
{
	int		fd;
	char	*gnl;

	fd = open(map, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		if (recupmap(data, gnl) == 0)
			break ;
		if (ft_get_texture(data, gnl) == 1)
			return (1);
		gnl = get_next_line(fd);
	}
	printf("salutss%s\n", gnl);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	data;

	if (checkerr(av[1], ac) == 1)
		return (1);
	ft_initdata(&data);
	if (ft_checkmap(av[1], &data) == 1)
		return (1);
	printf("x = %d\n", data.x);
	printf("NO = %s\n", data.no);
	printf("SO = %s\n", data.so);
	printf("WE = %s\n", data.we);
	printf("EA = %s\n", data.ea);
	printf("F = %s\n", data.f);
	printf("C = %s\n", data.c);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:30:36 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 11:30:56 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_checkvalidmap(int j, char *str, size_t k)
{
	if (str[0] == 32)
	{
		while (str[k])
		{
			if (str[k] == 32 || str[k] == '\n')
				k++;
			else
				break ;
		}
		if (k == ft_strlen(str))
			return (1);
	}
	if ((!(str[j] == 32 || str[j] == '0' || str[j] == '1' || str[j] == 'N'
				|| str[j] == 'S' || str[j] == 'E' || str[j] == 'W'
				|| str[j] == 10)) || str[0] == 10)
		return (1);
	return (0);
}

char	**tabchar(t_map *data, char *s, int fd, int l)
{
	int		i;
	int		j;

	i = 0;
	data->map = malloc(sizeof(char *) * (data->longe + 1));
	while (i < data->longe && s)
	{
		j = -1;
		while (s[++j])
		{
			if (ft_checkvalidmap(j, s, 0) == 1 || (s[j] == 'N'
					|| s[j] == 'S' || s[j] == 'E' || s[j] == 'W'))
				l++;
		}
		data->map[i] = ft_strtrim(s, "\n");
		free(s);
		s = get_next_line(fd);
		i++;
	}
	free (s);
	if (l != 1)
		printf("Error\nmap not valid\n");
	if (l != 1)
		exit (1);
	return (data->map[i] = NULL, data->map);
}

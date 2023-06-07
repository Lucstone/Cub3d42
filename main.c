/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:16:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/06 16:00:34 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_map	data;

	if (checkerr(av[1], ac) == 1)
		return (1);
	if (parsing(ac, av, &data) == 1)
		return (1);
	ft_freeall(data);
	return (0);
}

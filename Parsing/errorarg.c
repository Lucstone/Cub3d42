/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:04:33 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 14:22:05 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_checkopen(char *file)
{
	if (open(file, O_DIRECTORY) > 0)
		return (ft_putendl_fd("Error\nNot a file it's a directory", 2), 1);
	if (open(file, O_RDONLY) < 0)
		return (ft_putendl_fd("Error\nDoesn't exist or no rights", 2), 1);
	return (0);
}

int	verifcub(char *file)
{
	if (ft_strncmp(&file[ft_strlen(file) - 4], ".cub", 4) == 0)
		return (0);
	ft_putendl_fd("Error\nNot a .cub file", 2);
	return (1);
}

int	checkerr(char *file, int ac)
{
	if (ac != 2)
		return (ft_putendl_fd("Error\nwrong number of argument", 2), 1);
	if (ft_checkopen(file) == 1)
		return (1);
	if (verifcub(file) == 1)
		return (1);
	return (0);
}

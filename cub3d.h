/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdiot <hdiot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/05/26 16:40:29 by hdiot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./Libft/srclib/libft.h"
# include "./Libft/gnl/get_next_line.h"
# include <errno.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct s_op
{
	int		mapw;
	int		maph;
	int		screenw;
	int		screenh;
	double	camx;
	double	pospx;
	double	pospy;
	double	dirpx;
	double	dirpy;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	r_dirx;
	double	r_diry;
}	t_op;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_cub
{
	int	he;
	int	wi;
	void	*mlx;
	void	*win;
	t_op	ray;
	t_data	*img;
}	t_cub;

#endif

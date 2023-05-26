/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/05/26 17:10:21 by lnaidu           ###   ########.fr       */
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

typedef	struct s_map
{
	int		countNO;
	int		countS0;
	int		countWE;
	int		countEA;
	int		countF;
	int		countC;
	char	*NO;
	char	*S0;
	char 	*WE;
	char 	*EA;
	char	*F;
	char	*C;
	char	**map;
	int		x;
	int		y;
}				t_map;

int checkerr(char *file, int ac);
#endif
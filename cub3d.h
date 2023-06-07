/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:31:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/06/07 11:20:51 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./Libft/srclib/libft.h"
# include "./Libft/gnl/get_next_line.h"
# include <errno.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct s_map
{
	int		countno;
	int		countso;
	int		countwe;
	int		countea;
	int		countf;
	int		countc;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	char	orientation;
	int		x;
	int		y;
	int		j;
	int		**tab;
	int		rgbf[4];
	int		rgbc[4];
	int		longe;
	int		large;
}					t_map;

int		checkerr(char *file, int ac);
int		ft_walltextno(char *crd, char *str, t_map *data, int i);
int		ft_walltextso(char *crd, char *str, t_map *data, int i);
int		ft_walltextwe(char *crd, char *str, t_map *data, int i);
int		ft_walltextea(char *crd, char *str, t_map *data, int i);
int		ft_walltextf(char *crd, char *str, t_map *data, int i);
int		ft_walltextc(char *crd, char *str, t_map *data, int i);
int		ft_checkalltext(t_map *data);
void	ft_freeall(t_map data);
t_map	ft_takecoord(t_map *data, char **str);
void	ft_printdata(t_map data, char **d);
int		ft_checkwall(char **map, int i, int j, int l);
void	ft_freechar(t_map data);
int		ft_checkcount(t_map *data);
void	ft_initrgb(t_map *data, int i, int j, int k);
int		parsing(int ac, char **av, t_map *data);
int		recupsprites(t_map *data, char *str);
void	ft_freeca(char **tab);
int		ft_checkopen(char *file);
t_map	ft_array(t_map *data, int i, int j, int len);
char	**arraymap(t_map *data, char *str, int fd);
int		ft_get_texture(t_map *data, char *str);
void	ft_initdata(t_map *data);
int		ft_checkmap(char *map, t_map *data);
void	ft_freewall(t_map data);
void	ft_getcharsize(char *map, t_map *data, int k, int l);
char	**tabchar(t_map *data, char *str, int fd, int l);

#endif
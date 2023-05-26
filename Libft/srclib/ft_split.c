/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:57:55 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/24 15:09:24 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, char c)
{
	size_t	i;
	size_t	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			nbr++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (nbr);
}

static void	*clear_table(char **tab, size_t i)
{
	while (i -- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	**execute(char const *s, char c, size_t len, char **taille)
{
	size_t	start;
	int		i;

	i = 0;
	while (s[len])
	{
		if (s[len] && s[len] == c)
			len ++;
		else
		{
			start = len;
			while (s[len] && s[len] != c)
				len++;
			taille[i] = ft_substr(s, start, (len - start));
			if (!taille[i])
				return (clear_table(taille, i));
			i++;
		}
	}
	taille[ft_count(s, c)] = NULL;
	return (taille);
}

char	**ft_split(char const *s, char c)
{
	size_t		len;
	char		**taille;

	len = 0;
	if (!s)
		return (NULL);
	taille = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (taille == 0 || !s)
		return (NULL);
	if (ft_count(s, c) == 0)
	{
		taille[0] = 0;
		return (taille);
	}
	return (execute(s, c, len, taille));
}

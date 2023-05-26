/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:59:24 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 10:51:26 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchrgnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*str;
	size_t	taille;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	taille = ft_strlengnl(s1) + ft_strlengnl(s2);
	str = malloc(sizeof(char) * taille + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

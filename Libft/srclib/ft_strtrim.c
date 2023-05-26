/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:34:24 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/14 10:42:44 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset1(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (charset1(s1[start], set) == 0)
		start++;
	end = ft_strlen(s1);
	while (charset1(s1[end - 1], set) == 0 && end > start)
		end--;
	str = ft_substr(s1, start, (end - start));
	return (str);
}

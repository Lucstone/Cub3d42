/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:37:19 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/13 16:59:04 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;
	size_t	j;

	if ((!dst || !src) && size == 0)
		return (0);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (lendst >= size)
		return (lensrc + size);
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (lendst + lensrc);
}

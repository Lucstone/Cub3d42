/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:22:08 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/15 10:52:02 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	b = 0;
	if (size > 0)
	{
		while (src[b] && b < (size - 1))
		{
			dst[b] = src[b];
			b++;
		}
		dst[b] = 0;
	}
	a = ft_strlen(src);
	return (a);
}

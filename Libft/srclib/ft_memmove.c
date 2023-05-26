/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:30:38 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/15 10:19:37 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*src2;
	char		*dst2;

	src2 = (const char *)src;
	dst2 = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i--)
			dst2[i] = src2[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	return (dst);
}

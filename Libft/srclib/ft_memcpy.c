/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:30 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/24 15:09:01 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst2;
	const char		*src2;
	size_t			i;

	i = 0;
	src2 = (const char *)src;
	dst2 = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:34:38 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/24 15:09:09 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b2;

	i = 0;
	b2 = (unsigned char *)b;
	while (i < len)
	{
		b2[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

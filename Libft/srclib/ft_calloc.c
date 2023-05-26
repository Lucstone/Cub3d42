/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:06:02 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/18 15:13:01 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	taille;

	if ((unsigned int)count * (unsigned int)size == 0 && count && size)
		return (NULL);
	if (count != 0 && size >= SIZE_MAX / count)
		return (NULL);
	taille = count * size;
	str = malloc (sizeof(void) * (taille));
	if (!str)
		return (NULL);
	ft_bzero(str, taille);
	return (str);
}

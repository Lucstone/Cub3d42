/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:36:42 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/24 15:08:28 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenght(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -1 * n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*a;
	unsigned long	j;
	size_t			len;

	len = ft_lenght(n);
	if (n < 0)
		j = ((long)n * -1);
	else
		j = (long)n;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (a != NULL)
	{
		a[len] = '\0';
		len--;
		if (n < 0)
			a[0] = '-';
		else if (n == 0)
			a[0] = '0';
		while (j > 0)
		{
			a[len--] = (char)(j % 10 + '0');
			j = j / 10;
		}
	}
	return (a);
}

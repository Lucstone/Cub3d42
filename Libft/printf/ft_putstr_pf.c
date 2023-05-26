/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:25:57 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 10:45:20 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s, int fd)
{
	int		i;
	char	*n;

	n = "(null)";
	i = 0;
	if (s == NULL)
	{
		ft_putstr_pf(n, 1);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_pf(s[i], fd);
		i++;
	}
	return (i);
}

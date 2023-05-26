/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:19:20 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 10:48:45 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_char_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base(long nbr, char *base)
{
	int		counter;
	long	i;
	char	end[16];

	counter = 0;
	i = 0;
	if (nbr == 0)
		counter += ft_putchar_pf('0', 1);
	if (!(ft_char_base(base)) && !((int)ft_strlenpf(base) < 2))
	{
		if (nbr < 0)
		{
			counter += ft_putchar_pf('-', 1);
			nbr = -nbr;
		}
		while (nbr > 0)
		{
			end[i++] = base[nbr % ft_strlenpf(base)];
			nbr /= ft_strlenpf(base);
		}
		while (end[--i])
			counter += ft_putchar_pf(end[i], 1);
	}
	return (counter);
}
/*
int main ()
{
    int i;
    char    *base = "0123456789";

    i = -2147483648;
    ft_putnbr_base (i, base);
	printf("%d", ft_putnbr_base (i, base));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:53:11 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 12:43:55 by lnaidu           ###   ########.fr       */
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

int	ft_putnbr_size(unsigned long long nbr, char *base)
{
	int					counter;
	unsigned long long	i;
	char				end[16];

	counter = 0;
	i = 0;
	counter += ft_putstr_pf("0x", 1);
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
    char    *base = "0123456789abcdef";
    void *  ptr = &i;

    i = -1;
    ft_putnbr_size (ptr, base);
	printf("%p", ft_putnbr_size (ptr, base));
}*/

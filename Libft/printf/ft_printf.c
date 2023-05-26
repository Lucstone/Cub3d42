/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:22:24 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 12:32:53 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list args, const char params)
{
	int	len;

	len = 0;
	if (params == 'c')
		len += ft_putchar_pf(va_arg(args, int), 1);
	else if (params == 's')
		len += ft_putstr_pf(va_arg(args, char *), 1);
	else if (params == 'p')
		len += ft_putnbr_size(va_arg(args, unsigned long long),
				"0123456789abcdef");
	else if (params == 'd')
		len += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (params == 'i')
		len += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (params == 'u')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (params == 'x')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (params == 'X')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (params == '%')
		len += ft_pourcentage();
	else
		len += ft_putchar_pf(params, 1) + 1;
	return (len);
}

int	ft_printf(const char *param, ...)
{
	int		i;
	va_list	args;
	int		count;
	char	*str;

	i = 0;
	str = (char *)param;
	va_start (args, param);
	count = ft_strlenpf(str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parse(args, str[i + 1]);
			i++;
			count = count - 2;
		}
		else
			ft_putchar_pf(str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main ()
{
	char	*i = "bonjour";
	ft_printf("%d\n", ft_printf("cspdiuxX%"));
	printf("%d\n", printf("cspdiuxX%"));
	return (0);
}
*/
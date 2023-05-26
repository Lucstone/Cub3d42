/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:23:15 by lnaidu            #+#    #+#             */
/*   Updated: 2022/12/05 10:44:22 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *param, ...);
int		ft_putchar_pf(int c, int fd);
int		ft_putstr_pf(char *s, int fd);
size_t	ft_strlenpf(const char *s);
int		ft_putnbr_base(long nbr, char *base);
int		ft_putnbr_size(unsigned long long nbr, char *base);
int		ft_pourcentage(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:22:45 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/14 17:49:28 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_lstsize(lst);
	j = 0;
	while (i > j)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
		j++;
	}
	return (lst);
}

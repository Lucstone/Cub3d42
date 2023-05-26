/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:16:33 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/14 17:41:26 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tamp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tamp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = tamp;
	}
}

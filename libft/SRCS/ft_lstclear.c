/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 09:54:34 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 20:07:05 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elt;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		elt = (*lst)->next;
		(*del)((*lst)->content);
		ft_lstmemdel((void **)lst);
		*lst = elt;
	}
	*lst = NULL;
}

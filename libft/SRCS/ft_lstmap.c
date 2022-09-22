/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:29:02 by agardett          #+#    #+#             */
/*   Updated: 2022/05/07 12:12:03 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*elt;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		elt = ft_lstnew((*f)(lst->content));
		if (!elt)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, elt);
		lst = lst->next;
	}
	return (first);
}
/*
void	* addOne(void *p)
{
	void	*r = malloc(sizeof(int));

	*(int *)r = *(int *)p + 1;
	return (r);
}

int	main(void)
{
	int	tab[] = {0,1,2,3};
	t_list	*l = ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	t_list	*m = ft_lstmap(l, addOne, free);
	t_list	*tmp = l;
	for (int i = 0; i < 4; ++i)
	{
		printf("%d \n",*(int *)tmp->content);
		tmp = tmp->next;
	}
	tmp = m;
	for (int i = 0; i < 4; ++i)
	{
		printf("%d \n",*(int *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:25 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 20:12:13 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	if (!s || !n)
		return ;
	str = (char *)s;
	i = -1;
	while (++i < n)
		*(char *)(str + i) = 0;
}

/*
int	main(void)
{
	char tab[16] = "AAAAAAAAAAAAAAA\0"//;
	char tab2[16] = "AAAAAAAAAAAAAAA\0";
	int	i;
	i = 0;

	while (i < 15)
	{
		ft_bzero(tab,i);
		bzero(tab2,i);
		printf("\n%s  %s\n", (tab2 + i), (tab + i));
		i++;
	}
	return (0);
}
*/

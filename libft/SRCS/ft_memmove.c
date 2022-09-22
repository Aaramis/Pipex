/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:06:50 by agardett          #+#    #+#             */
/*   Updated: 2022/05/08 16:24:18 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			*(char *)(dest + i) = *(char *)(src + i);
	}
	else
		while (n-- > 0)
			*(char *)(dest + n) = *(char *)(src + n);
	return (dest);
}

/*
int	main(void)
{
	char tab[4];
	char tab1[4];
	char tab2[10] = "abcdefghij";
	char tab3[1] = "\0";
	size_t	i;

	i = 0;
	while (i < 12)
	{
		bzero(tab, 4);
		bzero(tab1, 4);
		memmove(tab, tab2, i);
		ft_memmove(tab1, tab2, i);
		memmove(tab3, tab3, 0);
		memmove(tab3, tab3, 0);
		printf("%s %s\n", tab, tab1);
		i++;
	}
	return (0);
}
*/

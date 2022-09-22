/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:47:29 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 19:57:02 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = c;
	return (s);
}

/*
int	main(void)
{
	char tab[100];
	char tab2[100];
	int	i;
	i = 0;
	
	while (i < 100)
	{
		ft_memset(tab2, 'A', i);
		memset(tab, 'A', i);
//		printf("%c %c \n", tab2[i - 1], tab[i - 1]);
//		if (tab2[i - 1] != 'A')
//			printf("1\n");
	//	ft_memset(tab2, 'A', i);
		if (tab[i- 1] != tab2[i - 1])
			printf("1\n");
		i++;
	}
	return (0);
}
*/

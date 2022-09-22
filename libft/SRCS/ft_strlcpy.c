/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:52:07 by agardett          #+#    #+#             */
/*   Updated: 2022/05/03 19:09:13 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((i + 1 < size) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*
int	main(void)
{
	char src[] = "coucou";
	char dest[10];
	char dest2[10];
	
	memset(dest, 'A', 10);
	memset(dest2, 'A', 10);
//	printf("%ld	%c\n", strlcpy(dest, src, 0), dest[0]);
	printf("%ld	%c    %d\n", ft_strlcpy(dest2, src, 0), dest2[0], showLeaks());
	return (0);
}
*/

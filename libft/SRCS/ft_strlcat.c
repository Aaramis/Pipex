/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:42:26 by agardett          #+#    #+#             */
/*   Updated: 2022/05/04 20:59:57 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(dest);
	i = 0;
	if (j + 1 < size)
	{
		while ((j + i + 1 < size) && src[i])
		{
			dest[j + i] = src[i];
			i++;
		}
		dest[j + i] = '\0';
	}
	i = ft_strlen(src);
	if (j >= size)
		return (size + i);
	return (j + i);
}

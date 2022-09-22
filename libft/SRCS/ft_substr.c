/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:17:27 by agardett          #+#    #+#             */
/*   Updated: 2022/05/08 16:13:04 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	taille;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start < size)
	{
		taille = ft_strlen(s) - start;
		if (len > taille)
			str = (char *)malloc(sizeof(*str) * (taille + 1));
		else
			str = (char *)malloc(sizeof(*str) * (len + 1));
	}
	else
		str = (char *)malloc(sizeof(*str) * 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && start < size)
		str[i++] = s[start++];
	*(char *)(str + i) = 0;
	return (str);
}

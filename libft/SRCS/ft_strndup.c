/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:40:00 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 19:59:35 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, unsigned int i)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	while (i + 1)
	{
		*(str + i) = *(s + i);
		i--;
	}
	return (str);
}

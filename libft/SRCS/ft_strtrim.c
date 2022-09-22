/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:09:51 by agardett          #+#    #+#             */
/*   Updated: 2022/05/04 21:41:33 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;
	char			*str;

	if (!s1)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strrchr(set, s1[len]))
		len--;
	str = ft_substr(s1, start, len - start + 1);
	if (!str)
		return (NULL);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:31:52 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 18:28:35 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero_gnl(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = 0;
}

char	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*str;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	ft_bzero_gnl((void *)str, (nmemb * size));
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest || !s1 || !s2)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[size] = 0;
	free(s1);
	return (dest);
}

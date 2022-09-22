/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:59:03 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 20:04:01 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	nb_wd;
	int	i;

	i = 0;
	nb_wd = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			nb_wd++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb_wd);
}

static char	*ft_strcpy(char *dest, const char *src, size_t n)
{
	ft_bzero((void *)dest, n);
	if (ft_strlen(src) < n)
		ft_memcpy(dest, src, ft_strlen(src));
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

static char	*ft_insert_wd(char **s, char c)
{
	char	*str;
	size_t	len;

	while (**s == c && **s)
		(*s)++;
	len = 0;
	while ((*s)[len] != c && (*s)[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, *s, len);
	str[len] = 0;
	(*s) += len;
	return (str);
}

static char	**freetab(char **str, size_t i)
{
	while (i)
	{
		i--;
		free(str[i]);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		nb_wd;
	char	**tab;
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	nb_wd = ft_countword(str, c);
	tab = malloc(sizeof(char *) * (nb_wd + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nb_wd)
	{
		tab[i] = ft_insert_wd(&str, c);
		if (tab[i] == NULL)
			return (freetab(tab, i));
		i++;
	}
	tab[nb_wd] = 0;
	return (tab);
}

/*
int	main(void)
{
	int	i;
	char **ptab;

	i = 0;
	ptab = ft_split("   tripouille  42  ", ' ');
	while (i < 3)
	{
		printf("%s \n", ptab[i]);
		i++;
	}	
	return (0);
}
*/

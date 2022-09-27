/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:14:36 by agardett          #+#    #+#             */
/*   Updated: 2022/05/03 19:32:23 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strpchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return (i);
	return (-1);
}
/*
int main()
{
	char s[] =  "tripouille";
	printf("%s\n", ft_strchr(s, 't' + 256));
	printf("%d\n", 'a' + 256);
return(0);
}
*/

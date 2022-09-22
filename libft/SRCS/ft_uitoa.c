/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:02:22 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 19:22:55 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_len((unsigned int)n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

/*
int	main(void)
{
	//printf("%d \n",-000123);
	printf("%s \n", ft_itoa(-2147483648));
	printf("%s \n", ft_itoa(-12300));
	printf("%s \n", ft_itoa(-00123));
	printf("%s \n", ft_itoa(-00123));
	printf("%s \n", ft_itoa(-0000123));
	return (0);
}
*/

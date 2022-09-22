/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:57:56 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 17:37:15 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_abs(int n)
{
	if (n < 0)
		return ((-n));
	else
		return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	len = ft_len(n);
	str = (char *)malloc(sizeof(*str) *(len + 1));
	if (!str)
		return (NULL);
	i = 0;
	str[len] = 0;
	if (n < 0)
		str[i++] = '-';
	while (i < len)
		str[i++] = '0';
	while (n)
	{
		str[--len] = ft_abs(n % 10) + '0';
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

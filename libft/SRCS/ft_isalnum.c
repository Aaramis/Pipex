/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:42:02 by agardett          #+#    #+#             */
/*   Updated: 2022/05/03 13:47:50 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123));
}

/*
int	main(void)
{
	printf("%d	%d\n", ft_isalnum('a'), isalnum('a'));
	printf("%d	%d\n", ft_isalnum('A'), isalnum('A'));
	printf("%d	%d\n", ft_isalnum('0'), isalnum('0'));
	printf("%d	%d\n", ft_isalnum('9'), isalnum('9'));
	printf("%d	%d\n", ft_isalnum(93), isalnum(93));
	printf("%d	%d\n", ft_isalnum(126), isalnum(126));
	printf("%d	%d\n", ft_isalnum(20), isalnum(20));
	printf("%d	%d\n", ft_isalnum(64), isalnum(64));
	printf("%d	%d\n", ft_isalnum(91), isalnum(91));
	printf("%d	%d\n", ft_isalnum(96), isalnum(96));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:24:59 by agardett          #+#    #+#             */
/*   Updated: 2022/05/03 13:33:52 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha( int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

/*
int	main(void)
{
	printf("%d    %d\n", ft_isalpha('a'), isalpha('a'));
	printf("%d    %d\n", ft_isalpha('0'), isalpha('0'));
	printf("%d    %d\n", ft_isalpha('A'), isalpha('A'));
	printf("%d    %d\n", ft_isalpha('z'), isalpha('z'));
	printf("%d    %d\n", ft_isalpha(92), isalpha(92));
	return (0);
}
*/

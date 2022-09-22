/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:35:13 by agardett          #+#    #+#             */
/*   Updated: 2022/05/03 13:40:54 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

/*
int	main(void)
{
	printf("%d	%d\n", ft_isdigit('0'), isdigit('0'));
	printf("%d	%d\n", ft_isdigit('9'), isdigit('9'));
	printf("%d	%d\n", ft_isdigit('a'), isdigit('a'));
	printf("%d	%d\n", ft_isdigit('!'), isdigit('!'));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:21:50 by agardett          #+#    #+#             */
/*   Updated: 2022/05/03 14:34:48 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}

/*
int	main(void)
{
	printf("%d	%d\n",ft_isascii(54),isascii(54));
	printf("%d	%d\n",ft_isascii(0),isascii(0));
	printf("%d	%d\n",ft_isascii(127),isascii(127));
	printf("%d	%d\n",ft_isascii(128),isascii(128));
	return (0);
}
*/

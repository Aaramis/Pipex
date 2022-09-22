/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:36:11 by agardett          #+#    #+#             */
/*   Updated: 2022/05/03 14:39:23 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c > 31 && c < 127);
}

/*
int	main(void)
{
	printf("%d	%d\n",ft_isprint(31),isprint(31));
	printf("%d	%d\n",ft_isprint(32),isprint(32));
	printf("%d	%d\n",ft_isprint(127),isprint(127));
	printf("%d	%d\n",ft_isprint(126),isprint(126));
	return (0);
}
*/

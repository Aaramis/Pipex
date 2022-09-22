/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:41:33 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 19:58:13 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
int	main(void)
{
	printf("%ld	%ld\n",strlen("test"), ft_strlen("test"));
	printf("%ld	%ld\n",strlen(""), ft_strlen(""));
	printf("%ld	%ld\n",strlen("test0546"), ft_strlen("test0546"));
	return (0);
}
*/

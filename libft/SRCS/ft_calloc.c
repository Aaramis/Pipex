/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:12:47 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 20:10:37 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_overflow(size_t a, size_t b)
{
	size_t	sizetmax;
	size_t	sizetmin;

	sizetmax = SIZE_MAX;
	sizetmin = 0;
	if (b && a && a > (sizetmax / b))
		return (1);
	else if (b && a && a < (sizetmin / b))
		return (1);
	else
		return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (check_overflow(nmemb, size))
		return (NULL);
	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, (nmemb * size));
	return (str);
}

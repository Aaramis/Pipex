/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:44:48 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 20:00:17 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	value;
	int	neg;
	int	i;

	if (!nptr)
		return (0);
	value = 0;
	i = 0;
	neg = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		i++;
		neg = -1;
	}
	if (nptr[i] == '+' && neg == 1)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr)
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (value * neg);
}

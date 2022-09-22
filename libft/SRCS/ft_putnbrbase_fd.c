/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:02:41 by agardett          #+#    #+#             */
/*   Updated: 2022/05/13 18:50:18 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrbase_fd(intptr_t n, char *base, int fd, int ret)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (!len_base)
		return (ret);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ret++;
	}
	if (n >= len_base)
	{
		ret = ft_putnbrbase_fd((n / len_base), base, fd, ret);
		ret = ft_putnbrbase_fd((n % len_base), base, fd, ret);
	}
	else
	{
		ft_putchar_fd(base[n], fd);
		return (++ret);
	}
	return (ret);
}
/*
int	main(void)
{
	ft_putnbrbase_fd(0,"0123456789abcdefg", 1, 0);
	write(1," ",1);	
	ft_putnbrbase_fd(16,"0123456789abcdefg", 1, 0);
	write(1," ",1);	
	ft_putnbrbase_fd(17,"0123456789abcdefg", 1, 0);
	write(1," ",1);	
	ft_putnbrbase_fd(18,"0123456789abcdefg", 1, 0);
	write(1," ",1);	
}
*/

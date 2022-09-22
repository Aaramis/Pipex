/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:56:25 by agardett          #+#    #+#             */
/*   Updated: 2022/05/20 12:58:25 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intptr_t	ft_pow(int nb, int n)
{
	intptr_t	ptr;

	ptr = 1;
	while (n--)
		ptr = ptr * nb;
	return (ptr);
}

int	ft_printf_p(intptr_t ptr, int fd)
{
	int	ret;

	ret = 0;
	if (ptr == ft_pow(2, 63))
	{
		ret += ft_printf_s("0x", fd);
		ret += ft_printf_s("8000000000000000", fd);
	}
	else if (ptr < 0 && ptr)
	{
		ret += ft_printf_s("0x", fd);
		ret = ft_putnbrbase_fd(15, "0123456789abcdef", fd, ret);
		ptr = -LONG_MAX * ft_pow(16, 15) + ptr ;
		ret = ft_putnbrbase_fd(ptr, "0123456789abcdef", fd, ret);
	}
	else if (ptr)
	{
		ret += ft_printf_s("0x", fd);
		ret = ft_putnbrbase_fd(ptr, "0123456789abcdef", fd, ret);
	}
	else
		ret += ft_printf_s("(nil)", fd);
	return (ret);
}

/*
int	ft_printf_p(long long ptr,int fd)
{
	int	ret;
	
	ret = 0;
	if (ptr < 0 && ptr)
	{
		ret += ft_printf_s("0x", fd);
		ret = ft_putnbrbase_fd((LONG_MAX/16), "0123456789abcdef", fd, ret);
		ptr = LONG_MAX * 16 + ptr + 16 ;
		ret = ft_putnbrbase_fd(ptr, "0123456789abcdef", fd, ret);
	}
	else if (ptr)
	{
		ret += ft_printf_s("0x", fd);
		ret = ft_putnbrbase_fd(ptr, "0123456789abcdef", fd, ret);
	}
	else 
		ret += ft_printf_s("(nil)", fd);
	return (ret);
}
*/

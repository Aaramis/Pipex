/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:58:03 by agardett          #+#    #+#             */
/*   Updated: 2022/05/20 12:56:08 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_printf_x(int n, char c, int fd)
{
	long int	nbr;
	int			ret;

	ret = 0;
	nbr = (long int)n;
	if (nbr < 0)
		nbr = LONG_MAX + nbr + 1;
	if (c == 'x')
		ret += ft_putnbrbase_fd(nbr, "0123456789abcdef", fd, ret);
	else
		ret += ft_putnbrbase_fd(nbr, "0123456789ABCDEF", fd, ret);
	return (ret);
}

int	ft_printf_d(int n, int fd)
{
	char	*str;
	int		ret;

	ret = 0;
	str = ft_itoa(n);
	if (!str)
		return (ret);
	ret += ft_printf_s(str, fd);
	free(str);
	return (ret);
}

int	ft_printf_s(char *str, int fd)
{
	if (!str)
	{	
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	else
		ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	ft_printf_u(va_list str, int fd)
{
	unsigned int	n;
	char			*nbr;
	int				ret;

	ret = 0;
	n = va_arg(str, unsigned int);
	if (!n)
		ret += write(1, "0", fd);
	else
	{
		nbr = ft_uitoa(n);
		if (!nbr)
			return (0);
		ret += ft_printf_s(nbr, fd);
		free (nbr);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:00:00 by agardett          #+#    #+#             */
/*   Updated: 2022/05/20 12:54:32 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *format, int i, va_list str)
{
	int	ret;

	ret = 0;
	if (format[i + 1] == 'c')
		ret += ft_printf_c(va_arg(str, int), 1);
	else if (format[i + 1] == 's')
		ret += ft_printf_s(va_arg(str, char *), 1);
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		ret += ft_printf_d(va_arg(str, int), 1);
	else if (format[i + 1] == 'u')
		ret += ft_printf_u(str, 1);
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		ret += ft_printf_x(va_arg(str, int), format[i + 1], 1);
	else if (format[i + 1] == '%')
		ret += ft_printf_c(format[i + 1], 1);
	else if (format[i + 1] == 'p')
		ret += ft_printf_p(va_arg(str, long long), 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	str;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	va_start(str, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += ft_printf_arg(format, i, str);
			i ++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			ret++;
		}
		i++;
	}
	va_end(str);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:25:58 by agardett          #+#    #+#             */
/*   Updated: 2022/05/20 14:30:40 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX 4294967295
# define U_LONG_MAX 18446744073709551615

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_printf_arg(const char *format, int i, va_list str);
int	ft_printf_u(va_list str, int fd);
int	ft_printf_s(char *str, int fd);
int	ft_printf_x(int n, char c, int fd);
int	ft_printf_c(char c, int fd);
int	ft_printf_d(int n, int fd);
int	ft_printf_p(intptr_t ptr, int fd);

#endif

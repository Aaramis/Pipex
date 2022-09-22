/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:31:52 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 18:28:35 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_buff(int fd, char *buff_f)
{
	int		re;
	char	*buff_i;

	buff_i = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_i)
		return (NULL);
	re = 1;
	while (re != 0 && !(ft_strchr_gnl((buff_f), '\n')))
	{
		re = read(fd, buff_i, BUFFER_SIZE);
		if (re == -1)
		{
			free (buff_i);
			return (NULL);
		}
		buff_i[re] = 0;
		if (!buff_f)
			buff_f = ft_calloc_gnl(1, 1);
		buff_f = ft_strjoin_gnl(buff_f, buff_i);
	}
	free (buff_i);
	return (buff_f);
}

char	*ft_findline(char *buff_f)
{
	char	*str;
	int		i;

	i = 0;
	if (!buff_f[i])
		return (NULL);
	while (buff_f[i] && buff_f[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buff_f[i] && buff_f[i] != '\n')
	{
		str[i] = buff_f[i];
		i++;
	}
	if (buff_f[i] == '\n')
	{
		str[i] = buff_f[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_new_buff(char *buff_f)
{
	char	*str;
	int		j;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen_gnl(buff_f);
	while (buff_f[i] && buff_f[i] != '\n')
		i++;
	if (!buff_f[i])
	{
		free (buff_f);
		return (NULL);
	}
	str = malloc(sizeof(char) * (size - i + 1));
	if (!str)
	{
		return (NULL);
	}
	j = 0;
	while (buff_f[i++])
		str[j++] = buff_f[i];
	str[j] = 0;
	free(buff_f);
	return (str);
}

int	get_next_line(int fd, char **str)
{
	static char	*buff_f[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff_f[fd] = ft_fill_buff(fd, buff_f[fd]);
	if (!buff_f[fd])
		return (0);
	(*str) = ft_findline(buff_f[fd]);
	buff_f[fd] = ft_new_buff(buff_f[fd]);
	return (1);
}

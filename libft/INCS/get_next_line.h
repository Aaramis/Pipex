/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:31:52 by agardett          #+#    #+#             */
/*   Updated: 2022/09/10 18:28:35 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 2048

int		get_next_line(int fd, char **str);
char	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strchr_gnl(const char *s, int c);
int		ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_findline(char *buff_f);
void	ft_bzero_gnl(void *s, size_t n);

#endif

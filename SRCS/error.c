/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:36:22 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:36:25 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *msg_err)
{
	write(2, msg_err, ft_strlen(msg_err));
	return (1);
}

int	msg_error(char *msg_err)
{
	perror(msg_err);
	exit (1);
}

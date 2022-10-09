/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:26:12 by agardett          #+#    #+#             */
/*   Updated: 2022/10/02 13:26:20 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipexb	*check_argv(char *str)
{
	t_pipexb *pip;

	pip = malloc(sizeof(*pip));
	if (!pip)
		msg_error_b(ERR_MALLOC, NULL);
	if (str && !ft_strncmp("here_doc", str, 9))
	{
		pip->hd = 1;
		pip->argc_min = 6;
		return (pip);
	}
	else 
	{
		pip->hd = 0;
		pip->argc_min = 5;
		return (pip);
	}
}

void	parsing_hd(char *argv, t_pipexb pip)
{

	
}

void	get_infile(char **argv, t_pipexb pip)
{
	if (pip->hd)
		//parsing
	else
		pip->infile = open(argv[1], O_RDONLY);
	if (!pip->infile)
		msg_error(ERR_INFILE, pip);
}
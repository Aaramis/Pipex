/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:59:28 by agardett          #+#    #+#             */
/*   Updated: 2023/03/05 11:59:30 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg_err)
{
	char	*tmp;

	tmp = ft_strjoin("\033[31m", msg_err);
	perror(tmp);
	free(tmp);
	exit(EXIT_FAILURE);
}

void	free_pipex(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->cmds_paths)
	{
		while (pipex->cmds_paths[++i])
			free(pipex->cmds_paths[i]);
		free(pipex->cmds_paths);
	}
	i = -1;
	if (pipex->cmds_args)
	{
		while (pipex->cmds_args[++i])
			free(pipex->cmds_args[i]);
		free(pipex->cmds_args);
	}
	if (pipex->cmd)
		free(pipex->cmd);
}

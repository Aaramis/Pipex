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

int	ft_fork(t_pipex pipex, char **argv, char **envp)
{
	pipex.pid = fork();
	if (pipex.pid == 0)
		child(&pipex, argv, envp);
	else
		parent(&pipex, argv, envp);
	return (pipex.pid);
}

void	close_pipes(t_pipex *pipex)
{
	if (close(pipex->fd[0]) < 0 || close(pipex->fd[1]) < 0)
			error(ERR_FILE);
}

int	is_executable(t_pipex *pipex)
{
	if (ft_strchr(pipex->cmds_args[0], '/'))
		return (access(pipex->cmds_args[0], 0));
	return (1);
}

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

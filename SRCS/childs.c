/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:37:45 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:37:47 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg_err, t_pipex *pipex)
{
	char	*tmp;

	if (pipex)
	{
		if (pipex->fd)
		{
			close(pipex->fd[1]);
			close(pipex->fd[0]);
		}
	}
	tmp = ft_strjoin("\033[31m", msg_err);
	perror(tmp);
	free(tmp);
	exit(EXIT_FAILURE);
}

char	*find_path(t_pipex *pipex, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	pipex->cmds_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (pipex->cmds_paths[i])
	{
		tmp = ft_strjoin(pipex->cmds_paths[i], "/");
		pipex->path = ft_strjoin(tmp, pipex->cmds_args[0]);
		free(tmp);
		if (access(pipex->path, 0) == 0)
			return (pipex->path);
		free(pipex->path);
		i++;
	}
	i = -1;
	while (pipex->cmds_paths[++i])
		free(pipex->cmds_paths[i]);
	free(pipex->cmds_paths);
	return (NULL);
}

void	execute(t_pipex *pipex, char *argv, char **envp)
{
	int	i;

	i = -1;
	pipex->cmds_args = ft_split(argv, ' ');
	pipex->cmd = find_path(pipex, envp);
	if (!pipex->cmd)
	{
		while (pipex->cmds_args[++i])
			free(pipex->cmds_args[i]);
		free(pipex->cmds_args);
		error(ERR_INPUT, pipex);
	}
	if (execve(pipex->cmd, pipex->cmds_args, envp) == -1)
		error(ERR_CMD, pipex);
}

void	child_process(t_pipex *pipex, char **argv, char **envp)
{
	pipex->infile = open(argv[1], O_RDONLY, 0777);
	if (pipex->infile == -1)
		error(ERR_INF, pipex);
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[0]);
	execute(pipex, argv[2], envp);
}

void	parent_process(t_pipex *pipex, char **argv, char **envp)
{
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
		error(ERR_OUT, pipex);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->fd[1]);
	execute(pipex, argv[3], envp);
}

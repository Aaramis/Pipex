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

char	*cmd_path(t_pipex *pipex, char **envp, int i)
{
	char	*tmp;

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

char	*find_path(t_pipex *pipex, char **envp)
{
	int		i;

	if (!is_executable(pipex))
		return (pipex->cmds_args[0]);
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0 && envp[i])
		i++;
	if (!envp[i])
		error(ERR_PATH);
	return (cmd_path(pipex, envp, i));
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
		error(ERR_CMD);
	}
	if (execve(pipex->cmd, pipex->cmds_args, envp) == -1)
	{
		free_pipex(pipex);
		error(ERR_CMD);
	}
}

void	child_process(t_pipex *pipex, char **argv, char **envp)
{
// 	pid_t	pid;
	
// 	pid = fork();
// 	if (pid == -1)
// 		error(ERR_FORK);
	// else if (pid == 0)
	// {
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		error(ERR_INF);
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[0]);
	execute(pipex, argv[2], envp);
	// }
}

void	parent_process(t_pipex *pipex, char **argv, char **envp)
{
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		error(ERR_OUT);
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->fd[1]);
	execute(pipex, argv[3], envp);
}

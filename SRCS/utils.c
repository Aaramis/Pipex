/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:42:26 by agardett          #+#    #+#             */
/*   Updated: 2022/09/29 20:59:57 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*get_path(char **envp)
{
	t_pipex	*pip;

	pip = malloc(sizeof(*pip));
	if (!pip)
		return (NULL);
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!envp)
		return (NULL);
	pip->paths = ft_split((*envp + 5), ':');
	if (!pip->paths)
		return (NULL);
	return (pip);
}

char	*get_cmd(t_pipex *pip, char *argv)
{
	int		i;
	char	*cmd;
	char	*fcmd;

	pip->cmds = ft_split(argv, ' ');
	i = -1;
	while (pip->paths[++i])
	{
		cmd = ft_strjoin(pip->paths[i], "/");
		fcmd = ft_strjoin(cmd, pip->cmds[0]);
		free(cmd);
		if (!access(fcmd, 0))
			return (fcmd);
		free (fcmd);
	}
	return (NULL);
}

void	parent_process(t_pipex *pip, char **argv, char **envp)
{
	if (dup2(pip->end[0], 0) < 0)
		msg_error(ERR_DUP, pip);
	close(pip->end[1]);
	if (dup2(pip->outfile, 1) < 0)
		msg_error(ERR_DUP, pip);
	pip->cmd = get_cmd(pip, argv[3]);
	if (!pip->cmd)
		msg_error(ERR_CMD, pip);
	execve(pip->cmd, pip->cmds, envp);
}

void	child_process(t_pipex *pip, char **argv, char **envp)
{
	if (dup2(pip->end[1], 1) < 0)
		msg_error(ERR_DUP, pip);
	close(pip->end[0]);
	if (dup2(pip->infile, 0) < 0)
		msg_error(ERR_DUP, pip);
	pip->cmd = get_cmd(pip, argv[2]);
	if (!pip->cmd)
		msg_error(ERR_CMD, pip);
	execve(pip->cmd, pip->cmds, envp);
}

void	pipex(t_pipex *pip, char **argv, char **envp)
{
	if (pipe(pip->end))
		msg_error(ERR_PIPE, pip);
	pip->parent = fork();
	if (pip->parent < 0)
		msg_error(ERR_FORK, pip);
	if (!pip->parent)
		parent_process(pip, argv, envp);
	else
		child_process(pip, argv, envp);
	close(pip->end[0]);
	close(pip->end[1]);
	waitpid(pip->parent, NULL, 0);
	close(pip->infile);
	close(pip->outfile);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:26:12 by agardett          #+#    #+#             */
/*   Updated: 2022/10/02 13:26:20 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipex	*get_path_b(char **envp)
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
	return (pip);
}

char	*get_cmd_b(t_pipex *pip, char *argv)
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

void	parent_process_b(t_pipex *pip, char **argv, char **envp)
{
	if (dup2(pip->end[0], 0) < 0)
		msg_error_b(ERR_DUP, pip);
	close(pip->end[1]);
	if (dup2(pip->outfile, 1) < 0)
		msg_error_b(ERR_DUP, pip);
	pip->cmd = get_cmd_b(pip, argv[3]);
	if (!pip->cmd)
		msg_error_b(ERR_CMD, pip);
	execve(pip->cmd, pip->cmds, envp);
}

void	child_process_b(t_pipex *pip, char **argv, char **envp)
{
	if (dup2(pip->end[1], 1) < 0)
		msg_error_b(ERR_DUP, pip);
	close(pip->end[0]);
	if (dup2(pip->infile, 0) < 0)
		msg_error_b(ERR_DUP, pip);
	pip->cmd = get_cmd_b(pip, argv[2]);
	if (!pip->cmd)
		msg_error_b(ERR_CMD, pip);
	execve(pip->cmd, pip->cmds, envp);
}

void	pipex_b(t_pipex *pip, char **argv, char **envp)
{
	if (pipe(pip->end))
		msg_error_b(ERR_PIPE, pip);
	pip->parent = fork();
	if (pip->parent < 0)
		msg_error_b(ERR_FORK, pip);
	if (!pip->parent)
		parent_process_b(pip, argv, envp);
	else
		child_process_b(pip, argv, envp);
	close(pip->end[0]);
	close(pip->end[1]);
	waitpid(pip->parent, NULL, 0);
	close(pip->infile);
	close(pip->outfile);
}

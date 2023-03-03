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

char	*find_cmd(char **cmds_paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*cmds_paths)
	{
		tmp = ft_strjoin(*cmds_paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(command, 0))
			return (command);
		free(command);
		cmds_paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tb[1], 1);
	close(pipex.tb[0]);
	dup2(pipex.infile, 0);
	pipex.cmds_args = ft_split(argv[2], ' ');
	pipex.cmd = find_cmd(pipex.cmds_paths, pipex.cmds_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmds_args, envp);
}

void	second_child(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tb[0], 0);
	close(pipex.tb[1]);
	dup2(pipex.outfile, 1);
	pipex.cmds_args = ft_split(argv[2], ' ');
	pipex.cmd = find_cmd(pipex.cmds_paths, pipex.cmds_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmds_args, envp);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmds_args[i])
	{
		free(pipex->cmds_args[i]);
		i++;
	}
	free(pipex->cmds_args);
	free(pipex->cmd);
}

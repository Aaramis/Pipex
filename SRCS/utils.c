/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:52:55 by agardett          #+#    #+#             */
/*   Updated: 2022/10/25 17:52:58 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "pipex.h"

char	*get_cmd(t_pipexb *pip, char *argv)
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

void	dup_pipe(int first, int second, t_pipexb *pip)
{
	if (dup2(first, 0) < 0)
		msg_error(ERR_DUP, pip);
	if (dup2(second, 1) < 0)
		msg_error(ERR_DUP, pip);
}

void	child_process(t_pipexb *pip, char **argv, char **envp)
{
	int	i;

	pip->parent = fork();
	if (!pip->parent)
	{
		if (!pip->ind)
			dup_pipe(pip->infile, pip->end[1], pip);
		else if (pip->ind == pip->nb_cmd - 1)
			dup_pipe(pip->end[2 * pip->ind - 2], pip->outfile, pip);
		else
			dup_pipe(pip->end[2 * pip->ind - 2], \
				pip->end[2 * pip->ind + 1], pip);
		i = -1;
		while (++i < pip->nb_pipe)
			close(pip->end[i]);
		pip->cmd = get_cmd(pip, argv[2 + pip->ind]);
		if (!pip->cmd)
			msg_error(ERR_CMD, pip);
		execve(pip->cmd, pip->cmds, envp);
	}
}

void	init_pipe(t_pipexb *pip)
{
	int	i;

	i = -1;
	while (++i < (pip->nb_cmd - 1))
	{
		if (pipe(pip->end + 2 * i) < 0)
			msg_error(ERR_PIPE, pip);
	}
}

void	pipex(t_pipexb *pip, int argc, char **argv, char **envp)
{
	int	i;

	pip->nb_cmd = argc - 3;
	pip->nb_pipe = 2 * (pip->nb_cmd - 1);
	pip->end = (int *)malloc(sizeof(int) * pip->nb_pipe);
	if (!pip->end)
		msg_error(ERR_PIPE, pip);
	init_pipe(pip);
	pip->ind = -1;
	while (++(pip->ind) < pip->nb_cmd)
		child_process(pip, argv, envp);
	i = -1;
	while (++i < pip->nb_pipe)
		close(pip->end[i]);
	waitpid(-1, NULL, 0);
	close(pip->infile);
	close(pip->outfile);
}
*/
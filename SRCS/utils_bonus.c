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

void	get_path_b(char **envp,t_pipexb *pip)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!envp)
		return ;
	pip->paths = ft_split((*envp + 5), ':');
	if (!pip->paths)
		msg_error_b(ERR_MALLOC, pip);
}

char	*get_cmd_b(t_pipexb *pip, char *argv)
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
		msg_error_b(ERR_DUP, pip);
	if (dup2(second, 1) < 0)
		msg_error_b(ERR_DUP, pip);
}

void	child_process_b(t_pipexb *pip, char **argv, char **envp)
{
	int	i;

	pip->parent = fork();
	if (!pip->parent)
	{
		if (!pip->index)
			dup_pipe(pip->infile, pip->end[1], pip);
		else if (pip->index == pip->nb_cmd - 1)
			dup_pipe(pip->end[2* pip->index - 2], pip->outfile, pip);
		else
			dup_pipe(pip->end[2 * pip->index - 2], pip->end[2 * pip->index + 1], pip);
		i = -1;
		while (++i < pip->nb_pipe)
			close(pip->end[i]);
		pip->cmd = get_cmd_b(pip, argv[2 + pip->index]); // Case here_doc
		if (!pip->cmd)
			msg_error_b(ERR_CMD, pip);
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
			msg_error_b(ERR_PIPE, pip);
	}
}

void	pipex_b(t_pipexb *pip,int argc, char **argv, char **envp)
{
	int	i;
	pip->nb_cmd = argc - 3;
	pip->nb_pipe = 2 * (pip->nb_cmd - 1);
	pip->end = (int *)malloc(sizeof(int) * pip->nb_pipe);
	if (!pip->end)
		msg_error_b(ERR_PIPE, pip);
	init_pipe(pip);
	pip->index = -1;
	while (++(pip->index) < pip->nb_cmd)
		child_process_b(pip, argv, envp);
	i = -1;
	while (++i < pip->nb_pipe)
		close(pip->end[i]);
	waitpid(-1, NULL, 0);
	close(pip->infile);
	close(pip->outfile);
}

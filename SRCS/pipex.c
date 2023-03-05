/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:34:42 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:34:44 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	// if (!(*envp))
	// 	error(ERR_ENVP);
	if (argc == 5)
	{
		if (pipe(pipex.fd) == -1)
			error(ERR_PIPE);
		pipex.path = find_path(envp);
		pipex.cmds_paths = ft_split(pipex.path, ':');
		if (ft_fork(pipex, argv, envp) < 0)
			error(ERR_FORK);
		close_pipes(&pipex);
		waitpid(pipex.pid, &status, 0);
		free_pipex(&pipex);
	}
	error(ERR_INPUT);
}

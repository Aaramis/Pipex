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

	if (!(*envp))
		error(ERR_ENVP);
	else if (argc == 5)
	{
		if (pipe(pipex.fd) == -1)
			error(ERR_PIPE);
		pipex.pid = fork();
		if (pipex.pid == -1)
			error(ERR_FORK);
		if (pipex.pid == 0)
			child_process(&pipex, argv, envp);
		wait(&pipex.pid);
		parent_process(&pipex, argv, envp);
		free_pipex(&pipex);
		if (close(pipex.infile) < 0 || close(pipex.outfile) < 0)
			error(ERR_FILE);
		return (0);
	}
	error(ERR_INPUT);
}

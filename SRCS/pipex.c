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
		error(ERR_ENVP, NULL);
	else if (argc == 5)
	{
		if (pipe(pipex.fd) == -1)
			error(ERR_PIPE, NULL);
		pipex.pid = fork();
		if (pipex.pid == -1)
			error(ERR_FORK, &pipex);
		if (pipex.pid == 0)
			child_process(&pipex, argv, envp);
		waitpid(pipex.pid, NULL, 0);
		parent_process(&pipex, argv, envp);
		if (close(pipex.infile) < 0 || close(pipex.outfile) < 0)
			error(ERR_FILE, &pipex);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}

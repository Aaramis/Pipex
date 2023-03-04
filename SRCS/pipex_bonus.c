/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:24:27 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:24:29 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (!(*envp))
		error(ERR_ENVP, NULL);
	else if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			pipex.idx = 3;
			pipex.outfile = open_file(argv[argc - 1], 0);
			here_doc(&pipex, argv[2], argc);
		}
		else
		{
			pipex.idx = 2;
			pipex.outfile = open_file(argv[argc - 1], 1);
			pipex.infile = open_file(argv[1], 2);
			dup2(pipex.infile, STDIN_FILENO);
		}
		while (pipex.idx < argc - 2)
			bonus_process(&pipex, argv[(pipex.idx)++], envp);
		dup2(pipex.outfile, STDOUT_FILENO);
		execute(&pipex, argv[argc - 2], envp);
	}
	usage();
}

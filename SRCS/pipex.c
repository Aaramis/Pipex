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

char	*get_paths(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pip(t_pipex *pipex)
{
	close(pipex->tb[0]);
	close(pipex->tb[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg(ERR_INPUT));
	if (!(*envp))
		return (msg_error(ERR_ENVP));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(ERR_INF);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		msg_error(ERR_OUT);
	if (pipe(pipex.tb) < 0)
		msg_error(ERR_PIPE);
	pipex.paths = get_paths(envp);
	pipex.cmds_paths = ft_split(pipex.paths, ':');
	pipex.pd1 = fork();
	if (pipex.pd1 == 0)
		first_child(pipex, argv, envp);
	pipex.pd2 = fork();
	if (pipex.pd2 == 0)
		second_child(pipex, argv, envp);
	close_pip(&pipex);
	waitpid(pipex.pd1, NULL, 0);
	waitpid(pipex.pd2, NULL, 0);
}

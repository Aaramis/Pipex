/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:23:14 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:23:26 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	usage(void)
// {
// 	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
// 	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
// 	ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> <cmd> <...> <file>\n", 1);
// 	exit(EXIT_SUCCESS);
// }

// void	bonus_process(t_pipex *pipex, char *argv, char **envp)
// {
// 	if (pipe(pipex->fd) == -1)
// 		error(ERR_PIPE);
// 	pipex->pid = fork();
// 	if (pipex->pid == -1)
// 		error(ERR_FORK);
// 	if (pipex->pid == 0)
// 	{
// 		close(pipex->fd[0]);
// 		dup2(pipex->fd[1], STDOUT_FILENO);
// 		execute(pipex, argv, envp);
// 	}
// 	else
// 	{
// 		close(pipex->fd[1]);
// 		dup2(pipex->fd[0], STDIN_FILENO);
// 		// waitpid(pipex->pid, NULL, 0);
// 		wait(&pipex->pid);
// 	}
// }

// int	open_file(char *argv, int i)
// {
// 	int	file;

// 	file = 0;
// 	if (i == 0)
// 		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
// 	else if (i == 1)
// 		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	else if (i == 2)
// 		file = open(argv, O_RDONLY, 0777);
// 	if (file == -1)
// 		error(ERR_INPUT);
// 	return (file);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:24:11 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:24:14 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	read_term(t_pipex *pipex, char *limiter)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(pipex->fd[1], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(t_pipex *pipex, char *limiter, int argc)
{
	if (argc < 6)
		usage();
	if (pipe(pipex->fd) == -1)
		error(ERR_PIPE, NULL);
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		close(pipex->fd[0]);
		read_term(pipex, limiter);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

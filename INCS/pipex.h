/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:53:03 by agardett          #+#    #+#             */
/*   Updated: 2022/10/25 17:53:05 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <errno.h>
# include <sys/wait.h>

# define ERR_ENVP "Error Environment"
# define ERR_PIPE "Error Pipe"
# define ERR_FORK "Error Fork"
# define ERR_FILE "Error file closing"
# define ERR_CMD "Command not found\n"
# define ERR_INPUT "Error Inputs"
# define ERR_INF "Error Infile"
# define ERR_OUT "Error Outfile"
# define ERR_MALLOC "Error malloc"
# define ERR_PATH "Error PATH"

typedef struct s_pipex
{
	pid_t	pid;
	char	*path;
	char	**cmds_paths;
	char	**cmds_args;
	char	*cmd;
	int		infile;
	int		outfile;
	int		fd[2];
	int		idx;
	int		here_doc;
}	t_pipex;

//childs
char	*cmd_path(t_pipex *pipex, char **envp, int i);
void	parent_process(t_pipex *pipex, char **argv, char **envp);
void	child_process(t_pipex *pipex, char **argv, char **envp);
void	execute(t_pipex *pipex, char *argv, char **envp);
char	*find_path(t_pipex *pipex, char **envp);

//error
void	error(char *msg_err);
void	free_pipex(t_pipex *pipex);
int		is_executable(t_pipex *pipex);

#endif

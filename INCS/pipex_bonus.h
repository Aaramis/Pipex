/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:25:41 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:25:46 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <errno.h>
# include <sys/wait.h>

# define ERR_INPUT "Error Inputs"
# define ERR_INFILE "Error Infile"
# define ERR_OUTFILE "Error Outfile"
# define ERR_PIPE "Error Pipe"
# define ERR_ENVP "Error Environment"
# define ERR_CMD "Command not found\n"
# define ERR_HEREDOC "Error Here Doc"

typedef struct s_ppxd
{
	char	*env_path;
	char	*cmd;
	char	**cmd_paths;
	char	**cmd_args;
	int		infile;
	int		outfile;
	int		here_doc;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		idx;
	int		*pipe;
	pid_t	pid;
}	t_ppxb;

//child_bonus
char	*get_cmd(char **paths, char *cmd);
void	sub_dup2(int zero, int first);
void	child(t_ppxb p, char **argv, char **envp);

// error_bonus
int		msg(char *err);
void	msg_pipe(char *arg);
int		msg_error(char *err);

// files_bonus
char	*find_path(char **envp);
void	get_infile(char **argv, t_ppxb *pipex);
void	get_outfile(char *argv, t_ppxb *pipex);

// free_bonus
void	parent_free(t_ppxb *pipex);
void	child_free(t_ppxb *pipex);
void	pipe_free(t_ppxb *pipex);

// pipex_bonus
void	creat_pipes(t_ppxb *pipex);
void	close_pipes(t_ppxb *pipex);

// hoc
int		args_in(char *arg, t_ppxb *pipex);
void	here_doc(char *argv, t_ppxb *pipex);

#endif

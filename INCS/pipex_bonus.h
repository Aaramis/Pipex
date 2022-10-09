/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:25:25 by agardett          #+#    #+#             */
/*   Updated: 2022/10/02 13:37:05 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <errno.h>
# include <sys/wait.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_FORK "Fork"
# define ERR_DUP "Dup2"
# define ERR_CMD "Command not found\n"
# define ERR_MALLOC "Error Malloc\n"

typedef struct s_pipexb
{
	char	**paths;
	char	**cmds;
	char	*cmd;
	int		infile;
	int		outfile;
	int		nb_cmd;
	int		nb_pipe;
	int		index;
	int		*end;
	int		hd;
	int		argc_min;
	pid_t	parent;
}	t_pipexb;

//utils
char	*get_cmd_b(t_pipexb *pip, char *argv);
void	child_process_b(t_pipexb *pip, char **argv, char **envp);
void	init_pipe(t_pipexb *pip);
void	pipex_b(t_pipexb *pip,int argc, char **argv, char **envp);
void	dup_pipe(int first, int second, t_pipexb *pip);
void	get_path_b(char **envp,t_pipexb *pip);

//heredoc
t_pipexb	*check_argv(char *str);
void get_infile(char **argv, t_pipexb pip);

//main
void	msg_error_b(char *str, t_pipexb *pip);
void	free_tab_b(char **tab);

#endif

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

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_FORK "Fork"
# define ERR_DUP "Dup2"
# define ERR_CMD "Command not found\n"
# define ERR_MALLOC "Error Malloc\n"
# define ERR_ENVP "Error Environment\n"

// # define malloc(x) xmalloc(x)

typedef struct s_pipexb
{
	char	**paths;
	char	**cmds;
	char	*cmd;
	int		infile;
	int		outfile;
	int		nb_cmd;
	int		nb_pipe;
	int		ind;
	int		*end;
	int		argc_min;
	pid_t	parent;
}	t_pipexb;

//utils
char		*get_cmd(t_pipexb *pip, char *argv);
void		child_process(t_pipexb *pip, char **argv, char **envp);
void		init_pipe(t_pipexb *pip);
void		pipex(t_pipexb *pip, int argc, char **argv, char **envp);
void		dup_pipe(int first, int second, t_pipexb *pip);

//main
void		get_path(char **envp, t_pipexb *pip);
t_pipexb	*init_pip(void);
void		msg_error(char *str, t_pipexb *pip);
void		free_tab(char **tab);

#endif

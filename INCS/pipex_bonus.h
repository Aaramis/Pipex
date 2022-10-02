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

typedef struct s_pipex
{
	char	**paths;
	char	**cmds;
	char	*cmd;
	int		infile;
	int		outfile;
	int		end[2];
	pid_t	parent;
}	t_pipex;

//utils
t_pipex	*get_path_b(char **envp);
char	*get_cmd_b(t_pipex *pip, char *argv);
void	child_process_b(t_pipex *pip, char **argv, char **envp);
void	parent_process_b(t_pipex *pip, char **argv, char **envp);
void	pipex_b(t_pipex *pip, char **argv, char **envp);

//main
void	msg_error_b(char *str, t_pipex *pip);
void	free_tab_b(char **tab);

#endif

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <errno.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_FORK "Fork"
# define ERR_DUP "Dup2"
# define ERR_CMD "Command not found\n"
# define ERR_MALLOC "Error Malloc\n"

typedef struct	s_pipex
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
t_pipex	*get_path(char **envp);
char	*get_cmd(t_pipex *pip, char *argv);
void	child_process(t_pipex *pip, char **argv, char **envp);
void	parent_process(t_pipex *pip, char **argv, char **envp);
void	pipex(t_pipex *pip, char **argv, char **envp);

//main
void	msg_error(char *str, t_pipex *pip);
void	free_tab(char **tab);

#endif

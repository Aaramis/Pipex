#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <errno.h>

typedef struct	s_pipex
{
	char	**cmd_paths;
}	t_pipex;

t_pipex	*get_path(char **envp);
void	child_process(int f1, char *cmd1);
void	parent_process(int f2, char *cmd2);
void	free_tab(char **tab);
void	pipex(int f1, int f2, char **argv, char **envp);

#endif

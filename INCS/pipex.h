#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

char	*get_path(char *cmd, char **envp);
void	child_process(int f1, char *cmd1);
void	parent_process(int f2, char *cmd2);
void	pipex(int f1, int f2, char **argv, char **envp);

#endif

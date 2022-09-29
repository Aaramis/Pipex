//
//	Header
//

#include "pipex.h"

t_pipex	*get_path(char **envp) 
{
	t_pipex	*pip;

	pip = malloc(sizeof(* pip));
	if (!pip)
		return NULL;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!envp)
		return NULL;
	pip->paths = ft_split((*envp + 5), ':');
	return (pip);
}

void	parent_process(int f2, char *cmd2)
{
//	if (dup2(f2, STDOUT) < 0)
//		return (perror("Dup2 :"));
	close(f2);
	(void)f2;
	(void)cmd2;
}

void	child_process(int f1, char *cmd1)
{
//	if (dup2(f1, STDIN) < 0)
//		return (perror("Dup2 :"));
	
	(void)f1;
	(void)cmd1;
}

void	pipex(t_pipex *pip, char **argv, char **envp)
{
	if (pipe(pip->end))
		msg_error(ERR_PIPE, pip);
	pip->parent = fork();
	if (pip->parent <  0)
		msg_error(ERR_FORK, pip);
	if (!pip->parent)
		ft_printf("A \n");
		//parent(f1, get_path(argv[3], envp));
	else
		ft_printf("%d \n", pip->parent);
		//child (f2, get_path(argv[4], envp));
	(void)argv;
	(void)envp;
}

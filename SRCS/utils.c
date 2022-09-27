//
//	Header
//

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
//	char	*path;
//	char	*dir;
//	size_t		i;

//	i = 0;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!envp)
		return (cmd);
	return (*envp + 5);
	/*
	path = envp[i] + 5;
	while (path && ft_strpchr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strpchr(path, ':'));
		path += ft_strpchr(path, ':') + 1;
	}
	*/
//	(void)cmd;
//	return (dir);
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

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int	end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent <  0)
		return (perror("Fork: "));
	if (!parent)
		ft_printf("A \n");
		//child_process(f1, get_path(argv[3], envp));
	else
		ft_printf("B \n");
		//parent_process(f2, get_path(argv[4], envp));
	(void)f1;
	(void)f2;
	(void)argv;
	(void)envp;
}

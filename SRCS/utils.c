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

char	*get_cmd(t_pipex *pip, char **argv)
{
	int		i;
	char	*cmd;
	char	*fcmd;

	pip->cmds = ft_split(argv[2], ' ');
	i = -1;
	while (pip->paths[++i])
	{
		cmd = ft_strjoin(pip->paths[i], "/");
		fcmd = ft_strjoin(cmd, pip->cmds[0]);
		free(cmd);
		if (!access(fcmd, 0))
			return (fcmd);
		free (fcmd);
	}
	return (NULL);
}

void	parent_process(int f2, char *cmd2)
{
//	if (dup2(f2, STDOUT) < 0)
//		return (perror("Dup2 :"));
	close(f2);
	(void)f2;
	(void)cmd2;
}

void	child_process(t_pipex *pip, char **argv)
{
//	if (dup2(f1, STDIN) < 0)
//		return (perror("Dup2 :"));

//	dup2(pip->end[1], 1);
//	close(pip->end[0]);
//	dup2(pip->infile, 0);
	pip->cmd = get_cmd(pip, argv);
	if (!pip->cmd)
		msg_error(ERR_CMD, pip);
	ft_printf("%s", pip->cmd);

	(void)pip;	
	(void)argv;
}

void	pipex(t_pipex *pip, char **argv, char **envp)
{
	if (pipe(pip->end))
		msg_error(ERR_PIPE, pip);
	pip->parent = fork();
	if (pip->parent <  0)
		msg_error(ERR_FORK, pip);
	if (!pip->parent)
		ft_printf("");
		//parent(f1, get_path(argv[3], envp));
	else
	{		
		ft_printf("B \n");
		child_process(pip, argv);
	}
		//child (f2, get_path(argv[4], envp));
	(void)argv;
	(void)envp;
}

//
//	Header
//

#include "pipex.h"

void	msg_error(char *str, t_pipex *pip)
{
	if (pip)
	{
		if (pip->paths)
			free_tab(pip->paths);
	free(pip);	
	}
	perror(str);
	exit (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i > -1)
		free(tab[i--]);
	free(tab);
}

int	main(int argc, char **argv, char **envp)
{
	int i;
	char *cmd;
	t_pipex	*pip;

	i = 0;
	if (argc != 5)
		msg_error(ERR_INPUT, NULL);
	pip = get_path(envp);
	if (!pip)
		msg_error(ERR_MALLOC, pip);
	pip->infile = open(argv[1], O_RDONLY);
	if (!pip->infile)
		msg_error(ERR_INFILE, pip);
	pip->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (!pip->outfile)
		msg_error(ERR_OUTFILE, pip);
		
	while (pip->paths[++i])
	{
		cmd = ft_strjoin(pip->paths[i], argv[2]);
		ft_printf("%s\n", cmd);
		free(cmd);
	}
	// pipex(pip->infile, pip->outfile, argv, envp);
	free_tab(pip->paths);
	free(pip);
	// pipex(1, 2, argv, envp);
	(void)argc;
	(void)argv;
	(void)envp;
	return (0);
}

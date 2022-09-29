//
//	Header
//

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	ft_printf("%d\n", i);
	while (i > -1)
		free(tab[i--]);
	free(tab);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;
	t_pipex	*pip;

	if (argc == 5)
	{
		pip = get_path(envp);
		if (!pip)
			return (-1);
		ft_printf("%s\n", pip->cmd_paths[0]);
		f1 = open(argv[1], O_RDONLY);
		f2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (f1 < 0 || f2 < 0)
			return (-1);
		// pipex(f1, f2, argv, envp);
		free_tab(pip->cmd_paths);
		free(pip);
		// pipex(1, 2, argv, envp);
	}
	(void)argc;
	(void)f1;
	(void)f2;
	(void)argv;
	(void)envp;
	return (0);
}

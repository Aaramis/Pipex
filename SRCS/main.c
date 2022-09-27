//
//	Header
//

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;
	t_pipex	*pip;

	if (argc == 5)
	{
		pip = malloc(sizeof(* pip));
		if (!pip)
			return (0);
		pip->path = get_path(argv[3], envp);
		pip->cmd_paths = ft_split(pip->path, ':');
		ft_printf("%s \n  %s\n", pip->path, pip->cmd_paths[0]);
		f1 = open(argv[1], O_RDONLY);
		f2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (f1 < 0 || f2 < 0)
			return (-1);
		pipex(f1, f2, argv, envp);
		pipex(1, 2, argv, envp);
	}
	(void)argc;
	(void)f1;
	(void)f2;
	(void)argv;
	(void)envp;
	return (0);
}

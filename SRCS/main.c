/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:42:26 by agardett          #+#    #+#             */
/*   Updated: 2022/09/29 20:59:57 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *str, t_pipex *pip)
{
	if (pip)
	{
		if (pip->paths)
			free_tab(pip->paths);
		if (pip->cmds)
			free_tab(pip->cmds);
		if (pip->cmd)
			free(pip->cmd);
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
	t_pipex	*pip;

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
//	ft_printf("%d %d %s\n", pip->infile, pip->outfile, pip->paths[0]);
	pipex(pip, argv, envp);
	free_tab(pip->paths);
	free(pip);
	return (0);
}

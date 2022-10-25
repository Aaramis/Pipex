/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:52:39 by agardett          #+#    #+#             */
/*   Updated: 2022/10/25 17:52:45 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(char **envp, t_pipexb *pip)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!envp)
		return ;
	pip->paths = ft_split((*envp + 5), ':');
	if (!pip->paths)
		msg_error(ERR_MALLOC, pip);
}

t_pipexb	*init_pip(void)
{
	t_pipexb	*pip;

	pip = malloc(sizeof(*pip));
	if (!pip)
		msg_error(ERR_MALLOC, NULL);
	pip->paths = NULL;
	pip->cmds = NULL;
	pip->cmd = NULL;
	pip->end = NULL;
	pip->infile = 0;
	pip->outfile = 0;
	pip->argc_min = 5;
	return (pip);
}

void	msg_error(char *str, t_pipexb *pip)
{
	if (pip->argc_min)
	{
		if (pip->paths)
			free_tab(pip->paths);
		if (pip->cmds)
			free_tab(pip->cmds);
		if (pip->cmd)
			free(pip->cmd);
		if (pip->end)
			free(pip->end);
		if (pip->infile)
			close(pip->infile);
		if (pip->outfile)
			close(pip->outfile);
		free(pip);
	}
	if (str)
	{
		perror(str);
		exit (1);
	}
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
	t_pipexb	*pip;

	if (!envp)
		msg_error(ERR_ENVP, NULL);
	pip = init_pip();
	if (argc < pip->argc_min)
		msg_error(ERR_INPUT, pip);
	get_path(envp, pip);
	pip->infile = open(argv[1], O_RDONLY);
	if (!pip->infile)
		msg_error(ERR_INFILE, pip);
	pip->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (!pip->outfile)
		msg_error(ERR_OUTFILE, pip);
	pipex(pip, argc, argv, envp);
	msg_error(NULL, pip);
	return (0);
}

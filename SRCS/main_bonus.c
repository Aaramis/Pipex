/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:25:48 by agardett          #+#    #+#             */
/*   Updated: 2022/10/02 13:26:03 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	msg_error_b(char *str, t_pipexb *pip)
{
	if (pip->argc_min)
	{
		if (pip->paths)
			free_tab_b(pip->paths);
		if (pip->cmds)
			free_tab_b(pip->cmds);
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

void	free_tab_b(char **tab)
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
		msg_error_b(ERR_ENVP, NULL);
	pip = check_argv(argv[1]);
	printf("%d %d	%d\n", pip->argc_min, argc, argc < pip->argc_min);
	if (argc < pip->argc_min)
	  	msg_error_b(ERR_INPUT, pip);
	get_path_b(envp, pip);
	pip->infile = open(argv[1], O_RDONLY);
	if (!pip->infile)
		msg_error_b(ERR_INFILE, pip);
	pip->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (!pip->outfile)
		msg_error_b(ERR_OUTFILE, pip);
	pipex_b(pip, argc, argv, envp);
	msg_error_b(NULL, pip);
	return (0);
}

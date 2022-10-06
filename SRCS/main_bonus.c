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
	if (pip)
	{
		if (pip->paths)
			free_tab_b(pip->paths);
		if (pip->cmds)
			free_tab_b(pip->cmds);
		if (pip->cmd)
			free(pip->cmd);
		if (pip->end)
			free(pip->end);
		free(pip);
		if (pip->infile)
			close(pip->infile);
		if (pip->outfile)
			close(pip->outfile);
	}
	perror(str);
	exit (1);
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

	if (argc < 5)
		msg_error_b(ERR_INPUT, NULL);
	pip = get_path_b(envp);
	if (!pip)
		msg_error_b(ERR_MALLOC, pip);
	pip->infile = open(argv[1], O_RDONLY);
	if (!pip->infile)
		msg_error_b(ERR_INFILE, pip);
	pip->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (!pip->outfile)
		msg_error_b(ERR_OUTFILE, pip);
//	ft_printf("%d %d %s\n", pip->infile, pip->outfile, pip->paths[0]);
	pipex_b(pip, argc, argv, envp);
	free_tab_b(pip->paths);
	free(pip);
	return (0);
}

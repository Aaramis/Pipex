/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:20:57 by agardett          #+#    #+#             */
/*   Updated: 2022/10/25 16:21:02 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipexb	*init_pip(void)
{
	t_pipexb *pip;

	pip = malloc(sizeof(*pip));
	if (!pip)
		msg_error_b(ERR_MALLOC, NULL);
	pip->paths = NULL;
	pip->cmds = NULL;
	pip->cmd = NULL;
	pip->end = NULL;
	pip->infile = 0;
	pip->outfile = 0;
	return (pip);
}

t_pipexb	*check_argv(char *str)
{
	t_pipexb *pip;

	pip = init_pip();
	if (str && !ft_strncmp("here_doc", str, 9))
	{
		pip->hd = 1;
		pip->argc_min = 6;
		return (pip);
	}
	else 
	{
		pip->hd = 0;
		pip->argc_min = 5;
		return (pip);
	}
}

// void	parsing_hd(char *end, t_pipexb pip)
// {
// 	int		file;
// 	char	*buf;

// 	while (1)
// 	{
// 		write(1,"heredoc> ",9);
// 		if (get_next_line(0, &buf) == 0)
// 			msg_error(ERR_MALLOC, pip);
// 		if (!ft_strncmp(end, buf, ft_strlen_gnl(end) + 1);
// 			break;
// 		//add buf to c_hd;
// 	}
	
// }

// void	get_infile(char **argv, t_pipexb pip)
// {
// 	if (pip->hd)
// 		//parsing
// 	else
// 		pip->infile = open(argv[1], O_RDONLY);
// 	if (!pip->infile)
// 		msg_error(ERR_INFILE, pip);
// }

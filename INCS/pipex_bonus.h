/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:25:41 by agardett          #+#    #+#             */
/*   Updated: 2023/03/03 10:25:46 by agardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

//child_bonus
void	bonus_process(t_pipex *pipex, char *argv, char **envp);
int		open_file(char *argv, int i);
char	*find_path_bonus(t_pipex *pipex, char **envp);
void	usage(void);

// hoc
void	here_doc(t_pipex	*pipex, char *limiter, int argc);
// void	here_doc(char *argv, t_pipex *pipex);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:49:21 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/16 11:29:08 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <wait.h>

typedef struct s_pipex
{
	int		pid;
	int		pipefd[2];
	char	*argv2;
	char	*argv3;
	char	**envp;
	char	**cmd1;
	char	**cmd2;
	char	*infile;
	char	*outfile;
	char	**path;
}	t_pipex;

void	cmd(t_pipex *data, int file, char *file_name, char **cmd);
void	get_path(t_pipex *data);
int		parsing(char **cmd);
void	pipex(t_pipex *data);

#endif

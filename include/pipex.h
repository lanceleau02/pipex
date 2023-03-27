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
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	**path;
}	t_pipex;

int		check_absolute_path(char *cmd);
int		open_files(char *file, int code);
int		parsing(char **cmd);
void	exec_cmd(t_pipex *data, char **cmd);
void	make_dup2(t_pipex *data, int fd, int code);
void	pipex(t_pipex *data);

#endif

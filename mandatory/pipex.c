/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:39:31 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/17 14:51:16 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_path(t_pipex *data)
{
	int		i;
	char	*full_path;

	full_path = NULL;
	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
			full_path = ft_strdup(&data->envp[i][5]);
		i++;
	}
	if (full_path != NULL)
	{
		data->path = ft_split(full_path, ':');
		free(full_path);
		full_path = NULL;
	}
}

static void	cmd(t_pipex *data, int file, char *file_name, char **cmd)
{
	int		fd;
	int		pid;

	fd = open_files(file_name, file);
	if (fd == -1 || parsing(cmd) == 1)
		return ;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		make_dup2(data, fd, file);
		exec_cmd(data, cmd);
		exit(0);
	}
	close(fd);
}

void	pipex(t_pipex *data)
{
	get_path(data);
	if (pipe(data->pipefd) == -1)
	{
		perror("pipe");
		return ;
	}
	cmd(data, 0, data->infile, data->cmd1);
	close(data->pipefd[1]);
	cmd(data, 1, data->outfile, data->cmd2);
	close(data->pipefd[0]);
}

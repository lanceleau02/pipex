/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:21:51 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/16 11:37:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(t_pipex *data)
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

static int	open_files(char *file, int code)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		if (code == 1)
		{
			ft_putstr_fd(file, 2);
			ft_putstr_fd(": Is a directory\n", 2);
			return (-1);
		}
	}
	fd = 0;
	if (code == 0)
		fd = open(file, O_RDONLY);
	else if (code == 1)
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	return (fd);
}

static void	make_dup2(t_pipex *data, int fd, int code)
{
	dup2(fd, code);
	if (code == 0)
		dup2(data->pipefd[1], 1);
	else if (code == 1)
		dup2(data->pipefd[0], 0);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	close(fd);
}

static void	exec_cmd(t_pipex *data, char **cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = 0;
	if (check_absolute_path(cmd[0]) == 1)
		cmd_path = ft_strdup(cmd[0]);
	else
	{
		while (data && data->path && data->path[i])
		{
			tmp = ft_strjoin(data->path[i], "/");
			cmd_path = ft_strjoin(tmp, cmd[0]);
			free(tmp);
			if (ft_str_is_blank(cmd_path) == 1 && access(cmd_path, X_OK) == 0)
				break ;
			free(cmd_path);
			cmd_path = NULL;
			i++;
		}
	}
	if (ft_str_is_blank(cmd_path) == 1 && access(cmd_path, X_OK) == 0)
		execve(cmd_path, cmd, data->envp);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	close(0);
	close(1);
	ft_free_taboftab(data->path);
	ft_free_taboftab(data->cmd1);
	ft_free_taboftab(data->cmd2);
}

void	cmd(t_pipex *data, int file, char *file_name, char **cmd)
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

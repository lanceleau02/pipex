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

	i = 0;
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
			full_path = ft_strdup(&data->envp[i][5]);
		i++;
	}
	data->path = ft_split(full_path, ':');
	free(full_path);
}

/*static int	open_files(char *file, int code)
{
	int	fd;

	if (code == 0)
		fd = open(data->infile, O_RDONLY);
	else if (code == 1)
		fd = open(data->outfile, O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	return (fd);
}*/

void	cmd(t_pipex *data, int file, int cmd)
{
	int		fd;
	int		pid;
	int		i;
	char	*pathname;
	
	pathname = NULL;
	if (file == 0)
	{
		fd = open(data->infile, O_RDONLY);
		if (fd == -1)
		{
			perror("infile");
			return ;
		}
	}
	else if (file == 1)
	{
		fd = open(data->outfile, O_CREAT | O_RDWR | O_TRUNC, 0664);
		if (fd == -1)
		{
			perror("outfile");
			return ;
		}
	}
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (file == 0)
		{
			if (dup2(fd, 0) == -1 || dup2(data->pipefd[1], 1) == -1)
			{
				if (fd > -1)
					close(fd);
			}
		}
		else if (file == 1)
		{
			if (dup2(data->pipefd[0], 0) == -1 || dup2(fd, 1) == -1)
			{
				if (fd > -1)
					close(fd);
			}
		}
		close(fd);
		close(data->pipefd[0]);
		close(data->pipefd[1]);
		if (cmd == 0)
		{
			i = 0;
			while (data->path[i])
			{
				pathname = ft_strjoin(ft_strjoin(data->path[i], "/"), data->cmd1[0]);
				if (access(pathname, X_OK) == 0)
					break ;
				i++;
			}
			execve(pathname, data->cmd1, data->envp);
			perror(data->cmd1[0]);
		}
		else if (cmd == 1)
		{
			i = 0;
			while (data->path[i])
			{
				pathname = ft_strjoin(ft_strjoin(data->path[i], "/"), data->cmd2[0]);
				if (access(pathname, X_OK) == 0)
					break ;
				i++;
			}
			execve(pathname, data->cmd2, data->envp);
			perror(data->cmd2[0]);
		}
		free(pathname);
		exit(0);
	}
	close(fd);
}

/*void	cmd1(t_pipex *data)
{
	int		infile_fd;
	int		pid;
	int		i;
	char	*pathname;

	infile_fd = open(data->infile, O_RDONLY);
	if (infile_fd == -1)
	{
		perror("infile");
		return ;
	}
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (dup2(infile_fd, 0) == -1 || dup2(data->pipefd[1], 1) == -1)
		{
			if (infile_fd > -1)
				close(infile_fd);
			close(*data->pipefd);
		}
		close(infile_fd);
		close(*data->pipefd);
		i = 0;
		while (data->path[i])
		{
			pathname = ft_strjoin(ft_strjoin(data->path[i], "/"), data->cmd1[0]);
			if (access(pathname, X_OK) == 0)
				break ;
			i++;
		}
		execve(pathname, data->cmd1, data->envp);
		perror(data->cmd1[0]);
		free(pathname);
		exit(0);
	}
}

void	cmd2(t_pipex *data)
{
	int		outfile_fd;
	int		pid;
	int		i;
	char	*pathname;

	outfile_fd = open(data->outfile, O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (outfile_fd == -1)
	{
		perror("outfile");
		return ;
	}
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (dup2(data->pipefd[0], 0) == -1 || dup2(outfile_fd, 1) == -1)
		{
			if (outfile_fd > -1)
				close(outfile_fd);
			close(*data->pipefd);
		}
		close(outfile_fd);
		close(*data->pipefd);
		i = 0;
		pathname = ft_strjoin(ft_strjoin(data->path[i], "/"), data->cmd2[0]);
//		while (data->path[i])
//		{
//			pathname = ft_strjoin(ft_strjoin(data->path[i], "/"), data->cmd2[0]);
//			if (access(pathname, X_OK) == 0)
//				break ;
//			i++;
//		}
		execve(pathname, data->cmd2, data->envp);
		perror(data->cmd2[0]);
		free(pathname);
		exit(0);
	}
}*/

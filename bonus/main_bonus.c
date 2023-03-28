/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:18:51 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/28 13:18:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	main(int argc, char **argv)
{
	int		infile_fd;
	int		outfile_fd;
	int		nb_cmd;
	int		i;
	int		pipefd[2];
	int		pid;

	get_path(data);
	infile_fd = open_files(argv[1], 0);
	outfile_fd = open_files(argv[argc], 1);
	i = 0;
	nb_cmd = argc - 3;
	while (i < nb_cmd)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit (1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (i == nb_cmd - 1)
				dup2(outfile_fd, 0);
			else
				dup2(pipefd[1], 1);
			dup2(infile_fd, 0);
			close(pipefd[0]);
			close(pipefd[1]);
			close(infile_fd);
		}
		i++;
	}
}

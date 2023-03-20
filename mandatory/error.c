/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:12:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/17 17:16:19 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_files(t_pipex *data)
{
	/*if (access(data->infile, F_OK) == -1 && access(data->outfile, F_OK) == -1)
		return (1);*/
	if (access(data->infile, F_OK) == -1)
		return (2);
	/*else if (access(data->outfile, F_OK) == -1)
		return (3);*/
	else if (access(data->infile, R_OK) == -1
		&& access(data->outfile, W_OK) == -1)
		return (4);
	else if (access(data->infile, R_OK) == -1)
		return (5);
	else if (access(data->outfile, W_OK) == -1)
		return (6);
	/*else if (open(data->outfile, 1755) == -1)
		return (7);*/
	return (0);
}

static void	print_error(char *word, int code)
{
	if (code == 1)
	{
		ft_putstr_fd(word, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (code == 2)
	{
		ft_putstr_fd(word, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (code == 3)
	{
		ft_putstr_fd(word, 2);
		ft_putstr_fd(": Is a directory\n", 2);
	}
	else if (code == 4)
	{
		ft_putstr_fd(word, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

int	handle_error(t_pipex *data)
{
	if (check_files(data) == 1) // Existence of files
	{
		print_error(data->infile, 1);
		print_error(data->outfile, 1);
	}
	else if (check_files(data) == 2)
		print_error(data->infile, 1);
	else if (check_files(data) == 3)
		print_error(data->outfile, 1);
	else if (check_files(data) == 4) // Permissions of files
	{
		print_error(data->infile, 2);
		print_error(data->outfile, 2);
	}
	else if (check_files(data) == 5)
		print_error(data->infile, 2);
	else if (check_files(data) == 6)
		print_error(data->outfile, 2);
	else if (check_files(data) == 7) // Type of file
		print_error(data->outfile, 3);
	return (-1);
}

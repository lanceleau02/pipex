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

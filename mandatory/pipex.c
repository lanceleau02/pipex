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
	//handle_error(data);
	get_path(data);
	if (pipe(data->pipefd) == -1)
		perror("pipe");
	cmd1(data);
	cmd2(data);
}

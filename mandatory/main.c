/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:48:55 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/15 14:58:51 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	struct_init(t_pipex *data, char **argv, char **envp)
{
	data->pid = 0;
	data->pipefd[0] = 0;
	data->pipefd[1] = 0;
	data->argv2 = argv[2];
	data->argv3 = argv[3];
	data->envp = envp;
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	data->infile = argv[1];
	data->outfile = argv[4];
	data->path = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	struct_init(&data, argv, envp);
	pipex(&data);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	ft_free_taboftab(data.cmd1);
	ft_free_taboftab(data.cmd2);
	ft_free_taboftab(data.path);
	return (0);
}

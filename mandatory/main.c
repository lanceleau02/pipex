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
	data->envp = envp;
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	data->infile = argv[1];
	data->outfile = argv[4];
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
	{
		write(2, "Error\n>> Too few arguments.\n", 28);
		return (1);
	}
	struct_init(&data, argv, envp);
	pipex(&data);
	return (0);
}

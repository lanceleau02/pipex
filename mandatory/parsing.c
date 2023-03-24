/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:22:23 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/24 10:22:23 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (ft_str_is_blank(cmd[i]) == 0)
		{
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd(":command not found\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	parsing(char **cmd)
{
	if (check_cmd(cmd) == 1)
		return (1);
	return (0);
}

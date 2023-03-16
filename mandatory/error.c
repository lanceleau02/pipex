/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:12:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/03/16 11:06:47 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(t_pipex *data, int code)
{
	if (code == 1)
	{
		ft_putstr_fd(data->infile, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	return (1);
}

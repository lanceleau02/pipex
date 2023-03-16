/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:34:25 by laprieur          #+#    #+#             */
/*   Updated: 2022/10/12 14:10:45 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_definewordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	ft_definewordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') \
		|| (s[0] != c && i == 0))
			wordcount++;
		i++;
	}
	return (wordcount);
}

static void	ft_mfree(char **new_s, int position)
{
	int	i;

	i = 0;
	while (i <= position)
	{
		free(new_s[i]);
		new_s[i] = NULL;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**new_s;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	new_s = malloc(sizeof(char *) * (ft_definewordcount(s, c) + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i != 0 && s[i - 1] == c && s[i] != c))
		{
			new_s[j] = ft_substr(s, i, ft_definewordlen(&s[i], c));
			if (new_s[j] == NULL)
				ft_mfree(new_s, j);
			j++;
		}
		i++;
	}
	new_s[j] = NULL;
	return (new_s);
}

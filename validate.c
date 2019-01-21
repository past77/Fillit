/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:37:39 by ppolozhe          #+#    #+#             */
/*   Updated: 2018/11/30 18:58:38 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if buffer contains nothing except 3 characters.
*/

int		ft_3chars(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
** Check if new lines are in their places. Count new line and # characters.
*/

int		ft_hash_nl(char *str)
{
	int i;
	int hash;
	int	nl;

	i = 0;
	hash = 0;
	nl = 0;
	if ((str[4] != '\n' || str[9] != '\n' || str[14] != '\n'
		|| str[19] != '\n' || (str[20] != '\n' && str[20] != '\0')))
		return (0);
	while (i < 21)
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '\n')
			nl++;
		i++;
	}
	if (hash == 4 && (nl == 5 || nl == 4))
		return (1);
	return (0);
}

/*
** Check if the figure is a valid tetrimino by counting connections
** between # symols. It should have only 6 or 8 (square) connections.
*/

int		ft_neighbors(char *buf)
{
	int i;
	int con;

	i = 0;
	con = 0;
	while (buf[i])
	{
		if ((buf[i] == '.' || buf[i] == '#' || buf[i] == '\n'))
		{
			if (buf[i] == '#' && buf[i - 1] == '#')
				con++;
			if (buf[i] == '#' && buf[i + 1] == '#')
				con++;
			if (buf[i] == '#' && buf[i - 5] == '#')
				con++;
			if (buf[i] == '#' && buf[i + 5] == '#')
				con++;
		}
		i++;
		if (con == 6 || con == 8)
			return (1);
	}
	return (0);
}

/*
** If all three checks passed, the figure is valid.
*/

int		ft_validate(char *str)
{
	if ((ft_3chars(str) && ft_hash_nl(str) && ft_neighbors(str)))
		return (1);
	return (0);
}

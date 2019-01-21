/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:46:26 by ppolozhe          #+#    #+#             */
/*   Updated: 2018/12/17 18:03:04 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		delete_map(char **map)
{
	int		y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void		print_map(char **map)
{
	int		i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** The smallest possible square should have at least the area
** n = number_of_tetriminos * 4. So, we find the closest to n number
** which have integer square root.
*/

int			init_map_size(int tet_num)
{
	int		m_size;
	int		n;

	n = tet_num * 4;
	while (!(ft_sqrt(n)))
		n++;
	m_size = ft_sqrt(n);
	return (m_size);
}

/*
** call is used for extending map every time the solution is not found.
** It's sent from print_solution function.
*/

char		**create_map(int tet_num, int call)
{
	int		i;
	int		j;
	int		m_size;
	char	**map;

	m_size = init_map_size(tet_num) + call;
	if (!(map = (char **)malloc(sizeof(char *) * m_size + 1)))
		return (NULL);
	i = 0;
	while (m_size > i)
	{
		if (!(map[i] = (char *)malloc(sizeof(char *) * m_size + 1)))
			return (NULL);
		j = 0;
		while (j < m_size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}

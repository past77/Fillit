/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_on_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:19:33 by dstepane          #+#    #+#             */
/*   Updated: 2018/12/17 18:18:30 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		remove_tetri(char **map, char alpha)
{
	int		row;
	int		col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == alpha)
				map[row][col] = '.';
			col++;
		}
		row++;
	}
}

/*
** Works the same way as recon_place, but writes tetrimino on map.
*/

void		place_tetri(char **map, t_etlst *tet, int rw, int cl)
{
	int		arr[5];

	ft_memset(arr, 0, (5 * sizeof(int)));
	arr[3] = 0;
	while (arr[0] < 4)
	{
		arr[4] = 0;
		while (arr[4] < 4)
		{
			if (tet->tetri[arr[0]][arr[4]] != '.')
			{
				if (arr[3] > 0)
				{
					cl += (arr[4] - arr[1]);
					rw += (arr[0] - arr[2]);
				}
				arr[3]++;
				map[rw][cl] = tet->tetri[arr[0]][arr[4]];
				arr[1] = arr[4];
				arr[2] = arr[0];
			}
			arr[4]++;
		}
		arr[0]++;
	}
}

/*
** Checks if there is space for all 4 blocks of a tetri.
** We used array to replace 5 variables and satisfy 25 lines restriction.
** arr = {y == [0], x1 == [1], y1 == [2], f == [3], x == [4]};
*/

int			recon_place(char **map, t_etlst *tet, int rw, int cl)
{
	int		arr[5];

	ft_memset(arr, 0, (5 * sizeof(int)));
	while (arr[0] < 4)
	{
		arr[4] = 0;
		while (arr[4] < 4)
		{
			if (tet->tetri[arr[0]][arr[4]] != '.')
			{
				if (arr[3]++ > 0)
				{
					cl += (arr[4] - arr[1]);
					rw += (arr[0] - arr[2]);
				}
				if (!(map[rw]) || map[rw][cl] != '.')
					return (0);
				arr[1] = arr[4];
				arr[2] = arr[0];
			}
			arr[4]++;
		}
		arr[0]++;
	}
	return (1);
}

/*
** Scans the map for a free space for current tetrimino and
** writes the coordinates for the first block into
** the corresponding list structure.
*/

int			find_place(char **map, t_etlst *cur, int row, int col)
{
	while (!recon_place(map, cur, row, col))
	{
		col++;
		if (!map[row][col] && map[row])
		{
			col = 0;
			row++;
		}
		if (!(map[row]))
			break ;
	}
	if (recon_place(map, cur, row, col))
	{
		cur->row = row;
		cur->col = col;
		return (1);
	}
	return (0);
}

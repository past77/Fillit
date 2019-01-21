/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:08:03 by dstepane          #+#    #+#             */
/*   Updated: 2018/12/17 17:08:05 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks if the last tetrimino is on map. We assume that solution is done then.
*/

int			check_solution(char **map, t_etlst *tetris)
{
	t_etlst	*cur;
	int		y;
	int		x;

	cur = tetris;
	y = 0;
	while (cur->next)
		cur = cur->next;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == cur->alpha)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Small appendix for satisfying 25 lines restriction.
*/

void		solve2(char **map, t_etlst *cur)
{
	cur->next->row = 0;
	cur->next->col = 0;
	remove_tetri(map, cur->alpha);
}

/*
** Backtracking solver that works with the coordinates that are memorized
** in each tetrimino's list structure.
*/

void		solve(char **map, t_etlst *cur)
{
	while (cur)
	{
		if (find_place(map, cur, cur->row, cur->col))
			place_tetri(map, cur, cur->row, cur->col);
		else if (cur->prev)
		{
			cur = cur->prev;
			solve2(map, cur);
			if (map[cur->row][++cur->col])
				continue ;
			else if (map[++cur->row])
			{
				cur->col = 0;
				continue ;
			}
		}
		else
		{
			cur->row = 0;
			cur->col = 0;
			return ;
		}
		cur = cur->next;
	}
}

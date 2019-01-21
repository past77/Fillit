/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:43:03 by dstepane          #+#    #+#             */
/*   Updated: 2018/12/17 17:58:35 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Count number of tetriminos, send this number to initial map creator.
** Try to solve. If solution is not found, extend map size by 1
** and repeat until solution reached. Print solution, free memory.
*/

void	print_solution(t_etlst *tetris, char alpha)
{
	char	**map;
	int		tet_num;
	int		call;

	tet_num = alpha - 64;
	call = 0;
	solve(map = create_map(tet_num, call), tetris);
	while (!check_solution(map, tetris))
	{
		delete_map(map);
		call++;
		map = create_map(tet_num, call);
		solve(map, tetris);
	}
	print_map(map);
	delete_map(map);
	tetlst_del(&tetris);
}

/*
** Read tetriminos to buffer one by one, send them to validation. Write them to
** linked lists. '\0' helps us to check for extra or not-in-place new lines.
*/

void	read_file(int fd)
{
	char		*buf;
	int			ret;
	t_etlst		*tetris;
	char		alpha;

	buf = ft_strnew(21);
	alpha = '@';
	while ((ret = read(fd, buf, 21)))
	{
		if (!(ft_validate(buf)))
		{
			tetlst_del(&tetris);
			error();
		}
		else
		{
			tetlst_add(&tetris, tetlst_new(buf, ++alpha));
			buf[ret] = '\0';
		}
	}
	if (ret < 0 || alpha == '@' || alpha > 'Z' || buf[20] != '\0')
		error();
	free(buf);
	print_solution(tetris, alpha);
}

void	error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		main(int argc, char const *argv[])
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("USAGE: ./fillit [input_file]\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Can't open the file.\n");
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	close(fd);
	return (0);
}

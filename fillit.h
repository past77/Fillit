/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:45:46 by dstepane          #+#    #+#             */
/*   Updated: 2018/11/30 15:45:47 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct			s_tetlst
{
	char				**tetri;
	char				alpha;
	int					row;
	int					col;
	struct s_tetlst		*next;
	struct s_tetlst		*prev;
}						t_etlst;

void					error(void);
void					read_file(int fd);
void					print_solution(t_etlst *tetris, char alpha);

t_etlst					*tetlst_new(char *buf, char alpha);
void					tetlst_add(t_etlst **head, t_etlst *new);
void					tetlst_del(t_etlst **head);
void					del_tetri(char **tetri);

int						ft_validate(char *str);
int						ft_3chars(char *str);
int						ft_hash_nl(char *str);
int						ft_neighbors(char *buf);

int						init_map_size(int tet_num);
char					**create_map(int tet_num, int call);
void					print_map(char **map);
void					delete_map(char **map);

void					solve(char **map, t_etlst *cur);
void					solve2(char **map, t_etlst *cur);
int						find_place(char **map, t_etlst *cur, int row, int col);
int						recon_place(char **map, t_etlst *tet, int rw, int cl);
void					place_tetri(char **map, t_etlst *tet, int rw, int cl);
void					remove_tetri(char **map, char alpha);
int						check_solution(char **map, t_etlst *tetris);

#endif

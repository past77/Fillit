/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri-lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstepane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:05:54 by dstepane          #+#    #+#             */
/*   Updated: 2018/12/17 18:18:56 by dstepane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_tetri(char **tetri)
{
	int i;

	if (!tetri)
		return ;
	i = 0;
	while (tetri[i])
	{
		free(tetri[i]);
		i++;
	}
	free(tetri);
}

void		tetlst_del(t_etlst **head)
{
	t_etlst	*cur;
	t_etlst	*nxt;

	if (!head)
		return ;
	cur = *head;
	while (cur)
	{
		nxt = cur->next;
		del_tetri(cur->tetri);
		if (cur->prev)
			cur->prev = NULL;
		if (cur->next)
			cur->next = NULL;
		free(cur);
		cur = nxt;
	}
	*head = NULL;
}

void		tetlst_add(t_etlst **head, t_etlst *new)
{
	t_etlst	*cur;

	if (!new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->prev = cur;
}

/*
** Each tetrimino is written to a two-way linked list, along with its
** coordinates (rows and columns), and a letter. # is converted to
** corresponding char. Then tetrimino in a string form is converted
** to strings array with ft_split.
*/

t_etlst		*tetlst_new(char *buf, char alpha)
{
	t_etlst	*newlink;
	int		i;

	if (!buf || !alpha)
		return (NULL);
	if (!(newlink = (t_etlst *)malloc(sizeof(t_etlst))))
		return (NULL);
	i = 0;
	while (i < 22)
	{
		if (buf[i] == '#')
			buf[i] = alpha;
		i++;
	}
	newlink->tetri = ft_strsplit((const char *)buf, '\n');
	newlink->alpha = alpha;
	newlink->row = 0;
	newlink->col = 0;
	newlink->prev = NULL;
	newlink->next = NULL;
	return (newlink);
}

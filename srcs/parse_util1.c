/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:28:18 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 20:27:30 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "store_map.h"

#include <stdio.h>

int		map_dimension(char **map)
{
	int		i;

	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}

int		check_segment(char **map, int line, int x, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if ((map[line][i + x] == 'o') || (map[line][i + x] == '\0'))
			return (0);
		i++;
	}
	return (1);
}

int		check_column(char **map, int line, int x, int n)
{
	int		i;

	i = 0;
	if (line + n <= map_dimension(map))
	{
		while (i < n)
		{
			if (!check_segment(map, line, x, n) || map[line] == 0)
				return (0);
			line++;
			i++;
		}
		return (1);
	}
	return (0);
}

void	check_line(char **map, int line, t_cursor init_pos, t_list **list)
{
	int		n;
	int		x;

	x = init_pos.x;
	x = init_pos.x;
	n = 0;
	while (map[line][x])
	{
		n = 1;
		if (map[line][x] != 'o')
		{
			while (map[line][x + n - 1] != 'o' && map[line][x + n - 1])
			{
				if (check_column(map, line, x, n))
					insert(list, x, line, n);
				n++;
			}
		}
		x++;
	}
}

void	process(char **map, t_list **list)
{
	t_cursor	init_pos;
	int			line;

	line = 0;
	init_pos.x = 0;
	init_pos.y = 0;
	while (map[line] != 0)
	{
		init_pos.x = 0;
		init_pos.y = line;
		check_line(map, line, init_pos, list);
		line++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:27:00 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 20:36:53 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "store_map.h"

int		empty_file(char *path)
{
	if (map_height(path) == 0 || map_width(path) == 0)
	{
		ft_putstr("map_error -> EMPTY_FILE\n");
		return (1);
	}
	return (0);
}

int		valid_line_widths(char **map)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	while (map[0][n])
		n++;
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		if (j != n)
			return (0);
		i++;
	}
	return (1);
}

int		valid_symbols(char **map)
{
	int		i;
	int		j;
	char	empty;
	char	obstruct;

	empty = '.';
	obstruct = 'o';
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != obstruct && map[i][j] != empty)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		map_validation(char **map)
{
	if (!valid_line_widths(map))
	{
		ft_putstr("map_error -> NON_REGULAR_MAP\n");
		return (0);
	}
	if (!valid_symbols(map))
	{
		ft_putstr("map error -> FORBIDDEN_SYMBOLS\n");
		return (0);
	}
	return (1);
}

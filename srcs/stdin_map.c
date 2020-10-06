/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:29:25 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/06 15:31:48 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*buffer_input(void)
{
	char	ch;
	char	*buffer;
	int		i;

	i = 0;
	if (!(buffer = malloc(sizeof(char) * 1000000)))
		return (NULL);
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		buffer[i] = ch;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

int		height_input(char *buf)
{
	int		height;
	int		i;

	height = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			height++;
		i++;
	}
	return (height);
}

int		width_input(char *buf)
{
	int		width;

	width = 0;
	while (buf[width] != '\n')
		width++;
	return (width);
}

char	**map_input_generator(char *buf, char **map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(map = malloc(sizeof(char*) * (height_input(buf) + 1))))
		return (NULL);
	while (i < height_input(buf))
	{
		if (!(map[i] = malloc(sizeof(char) * (width_input(buf) + 1))))
			map[i] = NULL;
		j = 0;
		while (j < width_input(buf))
		{
			map[i][j] = buf[k];
			k++;
			j++;
		}
		map[i][j] = '\0';
		k++;
		i++;
	}
	map[i] = 0;
	return (map);
}

char	**map_input(void)
{
	char	*buf;
	char	**map;

	map = NULL;
	buf = buffer_input();
	map = map_input_generator(buf, map);
	free(buf);
	return (map);
}

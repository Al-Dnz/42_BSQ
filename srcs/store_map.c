/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:28:26 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 20:10:27 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		map_height(char *path)
{
	char	buffer[10000];
	int		fd;
	int		byte_read;
	int		n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	n = 0;
	while ((byte_read = read(fd, buffer, 1)) > 0)
	{
		if (*buffer == '\n')
			n++;
	}
	close(fd);
	return (n);
}

int		map_width(char *path)
{
	char	buffer[10000];
	int		fd;
	int		byte_read;
	int		n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	n = 0;
	while (((byte_read = read(fd, buffer, 1)) > 0) && (*buffer != '\n'))
		n++;
	close(fd);
	return (n);
}

char	**array_generator(char *path)
{
	char	**arr;
	int		i;
	int		j;

	if ((arr = malloc(sizeof(char*) * (map_height(path) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < map_height(path))
	{
		if ((arr[i] = malloc(sizeof(char) * (map_width(path) + 1))) == NULL)
			return (NULL);
		j = 0;
		while (j < map_width(path))
		{
			arr[i][j] = 'x';
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

void	fill_array(char **arr, char *path)
{
	int		fd;
	char	buffer[10000];
	int		byte_read;
	int		i;
	int		j;

	if ((fd = open(path, O_RDONLY)) < 0)
		return ;
	i = 0;
	j = 0;
	while ((byte_read = read(fd, buffer, 1)) > 0)
	{
		if (*buffer == '\n')
		{
			arr[i][j] = '\0';
			i++;
			j = 0;
		}
		else
			arr[i][j++] = *buffer;
	}
	close(fd);
	arr[i] = 0;
}

void	free_map(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

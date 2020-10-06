/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:28:01 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/06 15:32:47 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "store_map.h"
#include "displayer.h"
#include "list.h"
#include "parser.h"
#include "map_validation.h"
#include "map_input.h"

int	run_input(void)
{
	char		**map;
	t_list		*li;

	li = NULL;
	map = NULL;
	map = map_input();
	if (map_validation(map) == 0)
	{
		free_list(li);
		free_map(map);
		return (0);
	}
	write(1, "\n", 1);
	process(map, &li);
	print_soluce(map, find_bsq(li));
	free_list(li);
	free_map(map);
	return (1);
}

int	run_file(char *path)
{
	char		**map;
	t_list		*li;

	li = NULL;
	if (empty_file(path))
		return (0);
	map = array_generator(path);
	fill_array(map, path);
	if (map_validation(map) == 0)
	{
		free_list(li);
		free_map(map);
		return (0);
	}
	process(map, &li);
	print_soluce(map, find_bsq(li));
	free_list(li);
	free_map(map);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
	{
		run_input();
		return (1);
	}
	while (i < argc)
	{
		run_file(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

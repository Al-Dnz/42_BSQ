/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:28:01 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 20:37:41 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "store_map.h"
#include "displayer.h"
#include "list.h"
#include "parser.h"
#include "map_validation.h"

int	main(void)
{
	char		**map;
	static char	*path = "maps/map_example2";
	t_list		*li;

	li = NULL;
	if (empty_file(path))
		return (0);
	map = array_generator(path);
	fill_array(map, path);
	if (map_validation(map) == 0)
		return (0);
	process(map, &li);
	print_soluce(map, find_bsq(li));
	free_list(li);
	free_map(map);
	return (1);
}

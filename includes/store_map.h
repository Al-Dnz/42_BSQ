/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:29:22 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 19:50:27 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_MAP_H
# define STORE_MAP_H

int		map_height(char *path);
int		map_width(char *path);
char	**array_generator(char *path);
void	fill_array(char **arr, char *path);
void	free_map(char **arr);

#endif

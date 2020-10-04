/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:26:50 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 19:48:12 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

int	empty_file(char *path);
int	valid_line_widths(char **map);
int	valid_symbols(char **map);
int	map_validation(char **map);

#endif

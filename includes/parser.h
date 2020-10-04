/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:29:14 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 18:41:09 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "list.h"

typedef struct	s_cursor
{
	int			x;
	int			y;
}				t_cursor;

int				map_dimension(char **map);
int				check_segment(char **map, int line, int init_pos, int n);
int				check_column(char **map, int line, int init_pos, int n);
void			process(char **map, t_list **list);
void			check_line(char **map, int line,
	t_cursor init_pos, t_list **list);

#endif

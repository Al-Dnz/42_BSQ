/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:32:19 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/06 15:32:20 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INPUT_H
# define MAP_INPUT_H

char	*buffer_input(void);
int		width_input(char *buf);
int		height_input(char *buf);
char	**map_input_generator(char *buf);
char	**map_input(void);

#endif

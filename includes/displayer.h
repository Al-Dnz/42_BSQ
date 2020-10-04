/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:28:50 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 19:54:52 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYER_H
# define DISPLAYER_H

# include <unistd.h>
# include "list.h"

void	display_map(char **arr);
void	print_soluce(char **map, t_list *bsq_params);
void	display_list(t_list *li);
void	display_item(t_list *li);

#endif

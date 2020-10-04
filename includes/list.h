/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:28:55 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 19:55:12 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	int				x;
	int				y;
	int				n;
}				t_list;

t_list			*create_list(int x, int y, int n);
void			insert(t_list **li, int x, int y, int n);
t_list			*find_bsq(t_list *li);
void			free_list(t_list *li);

#endif

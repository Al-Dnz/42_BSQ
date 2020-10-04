/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:27:45 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/04 19:57:53 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "strings.h"

t_list	*create_list(int x, int y, int n)
{
	t_list	*li;

	if ((li = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	li->x = x;
	li->y = y;
	li->n = n;
	li->next = NULL;
	return (li);
}

void	insert(t_list **li, int x, int y, int n)
{
	if (!(*li))
		(*li) = create_list(x, y, n);
	else
		insert(&((*li)->next), x, y, n);
}

t_list	*find_bsq(t_list *li)
{
	t_list	*res;
	int		n;

	res = NULL;
	n = 0;
	while (li)
	{
		if (li->n > n)
		{
			res = li;
			n = li->n;
		}
		li = li->next;
	}
	return (res);
}

void	free_list(t_list *li)
{
	t_list	*removed;

	if (li == NULL)
		return ;
	removed = li->next;
	free(li);
	free_list(removed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:27:37 by adenhez           #+#    #+#             */
/*   Updated: 2020/10/06 15:22:00 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"
#include "strings.h"

void	display_map(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 2);
		i++;
	}
}

void	print_soluce(char **map, t_list *bsq_li)
{
	int	i;
	int	j;

	i = 0;
	if (bsq_li != NULL)
	{
		while (i < bsq_li->n)
		{
			j = 0;
			while (j < bsq_li->n)
			{
				map[i + bsq_li->y][j + bsq_li->x] = 'x';
				j++;
			}
			i++;
		}
	}
	display_map(map);
}

void	display_list(t_list *li)
{
	while (li)
	{
		ft_putstr("x[");
		ft_putnbr(li->x);
		ft_putstr("]y[");
		ft_putnbr(li->y);
		ft_putstr("]n[");
		ft_putnbr(li->n);
		ft_putstr("]\n");
		li = li->next;
	}
	write(1, "[-NULL-]\n", 9);
}

void	display_item(t_list *li)
{
	ft_putstr("BSQ => ");
	ft_putstr("x[");
	ft_putnbr(li->x);
	ft_putstr("]y[");
	ft_putnbr(li->y);
	ft_putstr("]n[");
	ft_putnbr(li->n);
	ft_putstr("]\n");
	li = li->next;
}

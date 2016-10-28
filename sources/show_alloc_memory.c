/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:11:29 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:01:45 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	print_header(t_header *tmp)
{
	ft_putchar('[');
	if (tmp->is_free)
		ft_putstr_color("V", GREEN);
	else
		ft_putstr_color("X", RED);
	ft_putstr("] ");
	ft_putpointer(tmp->mem);
	ft_putstr(" - ");
	ft_putpointer(tmp->mem + tmp->size);
	ft_putstr(" : ");
	ft_putnbr(tmp->size);
	ft_putstr(" octets\n");
}

static int	print_page_memory(char *page, t_header *list)
{
	t_header	*tmp;
	int			total;

	total = 0;
	tmp = list;
	ft_putstr_color(page, RED);
	ft_putpointer(list);
	ft_putchar('\n');
	while (tmp)
	{
		print_header(tmp);
		total += tmp->size + sizeof(t_header);
		tmp = tmp->next;
	}
	ft_putstr("\nTotal: ");
	ft_putnbr(total);
	ft_putchar('\n');
	return (total);
}

void		show_alloc_mem(void)
{
	int	total;

	pthread_mutex_lock(&g_malloc_lock);
	total = print_page_memory("TINY ", g_mems_list.tiny);
	total += print_page_memory("SMALL ", g_mems_list.small);
	total += print_page_memory("LARGE ", g_mems_list.large);
	ft_putendl_color("-----------------------------------------", GREEN);
	pthread_mutex_unlock(&g_malloc_lock);
}

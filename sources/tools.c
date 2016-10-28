/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:37:04 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 17:22:27 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		set_pages_size(void)
{
	int		page_size;
	size_t	max;

	page_size = getpagesize();
	max = sizeof(t_header) * 100;
	TINY_SIZE = page_size * 6;
	SMALL_SIZE = page_size * 9;
}

int				get_page(size_t size)
{
	if (!TINY_SIZE || !SMALL_SIZE)
		set_pages_size();
	size += (sizeof(t_header) * 2) + 1;
	if (size <= TINY_SIZE)
		return (TINY);
	else if (size > TINY_SIZE && size <= SMALL_SIZE)
		return (SMALL);
	else
		return (LARGE);
}

t_header		**get_memory_list(int page)
{
	if (page == TINY)
		return (&g_mems_list.tiny);
	else if (page == SMALL)
		return (&g_mems_list.small);
	else
		return (&g_mems_list.large);
}

int				is_mem_between(void *ptr, void *start, void *end)
{
	if (ptr >= start && ptr <= end)
		return (1);
	else
		return (0);
}

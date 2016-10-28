/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:59:02 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:10:18 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static size_t		is_all_page_are_free(t_header *start, t_header *end)
{
	t_header	*tmp;
	size_t		len;
	t_header	*to_end;

	tmp = start;
	len = 1;
	to_end = (!end) ? end : end->next;
	while (tmp && tmp != to_end)
	{
		if (tmp->is_free == 0)
			return (0);
		len += tmp->size + sizeof(t_header);
		tmp = tmp->next;
	}
	return (len - 1);
}

static void			free_memory(t_header **page, t_block *block)
{
	size_t		size;
	int			ret;

	(block->selected)->is_free = 1;
	size = is_all_page_are_free(block->end, block->start);
	if (size > 0 && ((block->start)->next != NULL || size > SMALL_SIZE))
	{
		(block->prev)->next = (block->start)->next;
		if (*page == block->end)
		{
			*page = (block->start)->next;
		}
		ret = munmap(block->start, size);
		if (ret == -1)
			ft_putendl_color("MUNMAP ERROR", RED);
	}
}

void				free(void *ptr)
{
	t_block block;

	pthread_mutex_lock(&g_malloc_lock);
	if (find_ptr_in_page(ptr, &block))
	{
		free_memory(block.page, &block);
	}
	pthread_mutex_unlock(&g_malloc_lock);
}

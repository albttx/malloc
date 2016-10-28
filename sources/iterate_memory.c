/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 17:19:44 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 15:24:34 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_header		*get_ptr(void *ptr, t_header *end, t_header *start)
{
	t_header *tmp;

	tmp = end;
	while (tmp && tmp != start)
	{
		if (is_mem_between(ptr, (void *)tmp, tmp->mem + tmp->size))
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp && is_mem_between(ptr, (void *)tmp, tmp->mem + tmp->size))
		return (tmp);
	return (NULL);
}

static t_header		*get_start_page(t_header *start)
{
	t_header *tmp;

	tmp = start;
	while (tmp->next)
	{
		if (tmp->next && ((void *)tmp -
					((tmp->next)->mem + (tmp->next)->size)) != 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

static t_block		*get_memory_page(void *p, t_header **page, t_block *block)
{
	block->start = NULL;
	block->end = *page;
	block->prev = *page;
	while (block->end)
	{
		block->start = get_start_page(block->end);
		if (is_mem_between(p, ((void *)block->start),
					(block->end)->mem + (block->end)->size))
		{
			return (block);
		}
		block->prev = block->start;
		block->end = (!block->start) ? NULL : (block->start)->next;
	}
	block->start = NULL;
	block->end = NULL;
	block->prev = NULL;
	return (NULL);
}

t_block				*find_ptr_in_page(void *ptr, t_block *block)
{
	t_header	**mem_arr[4];
	int			i;

	i = 0;
	mem_arr[0] = &(g_mems_list.tiny);
	mem_arr[1] = &(g_mems_list.small);
	mem_arr[2] = &(g_mems_list.large);
	mem_arr[3] = NULL;
	while (mem_arr[i])
	{
		if (get_memory_page(ptr, mem_arr[i], block) != NULL)
		{
			block->selected = get_ptr(ptr, block->end, block->start);
			block->page = mem_arr[i];
			return (block);
		}
		i++;
	}
	return (NULL);
}

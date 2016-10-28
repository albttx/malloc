/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 11:49:23 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:20:19 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#define SIZE_LEFT (long long)(new->size - size - sizeof(t_header))

static t_header	*is_available_memory(t_header **list, size_t size)
{
	t_header	*tmp;
	t_header	*new;

	tmp = *list;
	new = NULL;
	while (tmp)
	{
		if (tmp->is_free == 1 && tmp->size >= size)
			if (!new || (new && new->size > tmp->size))
				new = tmp;
		tmp = tmp->next;
	}
	return (new);
}

t_header		*find_free_memory_space(t_header **list, size_t size, int page)
{
	t_header	*tmp;
	t_header	*new;

	new = is_available_memory(list, size);
	if (new)
	{
		if (SIZE_LEFT > 0 && (page == TINY || page == SMALL))
		{
			tmp = new;
			new = set_header(new->mem + size, SIZE_LEFT);
			new->next = tmp;
			tmp->size = size;
			if (*list == tmp)
				*list = new;
			return (tmp);
		}
		return (new);
	}
	return (NULL);
}

void			insert_header_in_page(t_header **list, t_header *block)
{
	block->next = *list;
	*list = block;
}

t_header		*set_header(t_header *block, size_t size)
{
	t_header	*new;

	new = block;
	new->mem = (void *)new + sizeof(t_header);
	new->size = size;
	new->is_free = 1;
	new->next = NULL;
	return (new);
}

t_header		*create_block(size_t size)
{
	t_header	*block;

	block = mmap(0, size, FLAG_PROT, FLAG_MAP, -1, 0);
	block->mem = block + 1;
	block->size = size - sizeof(t_header);
	block->is_free = 0;
	block->next = NULL;
	return (block);
}

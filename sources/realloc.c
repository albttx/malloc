/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 20:32:58 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:15:30 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void		*get_memory(void *mem, size_t size)
{
	t_block		block;
	void		*ret;

	ret = NULL;
	if (find_ptr_in_page(mem, &block))
	{
		if ((block.selected)->is_free == 1)
			return (NULL);
		if ((block.selected)->size > size)
			return ((block.selected)->mem);
		ret = malloc(size);
		if (ret)
		{
			ft_memcpy(ret, mem, size);
			free(mem);
		}
	}
	return (ret);
}

void			*realloc(void *mem, size_t size)
{
	void	*ret;

	pthread_mutex_lock(&g_malloc_lock);
	if (!mem || !size)
		ret = malloc(size);
	else
		ret = get_memory(mem, size);
	pthread_mutex_unlock(&g_malloc_lock);
	return (ret);
}

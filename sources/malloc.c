/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 22:51:48 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:09:06 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		ft_putstr_fd(RED, -1);
		ft_putendl_fd("MALLOC ERROR RETURN NULL", -1);
		ft_putstr_fd(DEFAULT, -1);
		return (NULL);
	}
	ft_bzero(ret, size);
	return (ret);
}

void	*malloc(size_t size)
{
	t_header	*block;

	pthread_mutex_lock(&g_malloc_lock);
	if (size <= 0)
		return (NULL);
	block = handle_sizes(size);
	pthread_mutex_unlock(&g_malloc_lock);
	return (block->mem);
}

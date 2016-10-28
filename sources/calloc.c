/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:17:59 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 17:22:49 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*handle_case(size_t num, size_t nsize)
{
	size_t	size;
	void	*ret;

	if (!num || !nsize)
		return (NULL);
	size = num * nsize;
	if (nsize != size / num)
		return (NULL);
	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_memset(ret, 0, size);
	return (ret);
}

void		*calloc(size_t num, size_t nsize)
{
	void	*ret;

	pthread_mutex_lock(&g_malloc_lock);
	ret = handle_case(num, nsize);
	pthread_mutex_unlock(&g_malloc_lock);
	return (ret);
}

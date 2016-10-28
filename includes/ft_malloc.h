/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:46:31 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:09:50 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "libft.h"
# include <sys/mman.h>
# include <pthread.h>

# define TINY 1
# define SMALL 2
# define LARGE 3

# define TINY_SIZE g_mems_list.tiny_size_max
# define SMALL_SIZE g_mems_list.small_size_max

# define FLAG_PROT PROT_READ | PROT_WRITE
# define FLAG_MAP MAP_ANON | MAP_PRIVATE

typedef struct		s_header
{
	void			*mem;
	size_t			size;
	int				is_free;
	struct s_header	*next;
}					t_header;

typedef struct		s_mem_list
{
	t_header		*tiny;
	t_header		*small;
	t_header		*large;

	size_t			tiny_size_max;
	size_t			small_size_max;
}					t_mem_list;

typedef struct		s_block
{
	t_header		*start;
	t_header		*end;
	t_header		*prev;
	t_header		*selected;

	t_header		**page;
}					t_block;

t_mem_list			g_mems_list;
pthread_mutex_t		g_malloc_lock;

void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);
void				*calloc(size_t num, size_t nsize);

void				show_alloc_mem(void);

void				*ft_malloc(size_t size);
t_header			*handle_sizes(size_t size);

t_block				*find_ptr_in_page(void *ptr, t_block *block);

int					get_page(size_t size);
t_header			**get_memory_list(int page);
int					is_mem_between(void *ptr, void *start, void *end);

t_header			*create_block(size_t size);
t_header			*set_header(t_header *block, size_t size);
void				insert_header_in_page(t_header **list, t_header *block);
t_header			*find_free_memory_space(t_header **l, size_t s, int p);

#endif

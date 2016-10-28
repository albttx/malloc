/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:28:26 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 17:53:13 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void simple_test(int *arr)
{
	int i = 0;
	void **mem = NULL;
	
	while (arr[i] != 0)
		i++;
	mem = malloc(sizeof(void *) * (i + 2));
	mem[i] = NULL;
	i=0;
	show_alloc_mem();
	while (arr[i] != 0)
	{
		mem[i] = malloc(arr[i]);
		mem[i] = ft_memset(mem[i], 'x', arr[i]);
		/*mem[i][arr[i]] = '\0';*/
		i++;
	}
	show_alloc_mem();
	puts("=============================\n=============================");
	free(mem[4]);
	free(mem[2]);
	free(mem[1]);
	free(mem[3]);
	free(mem[0]);
	free(mem);
}

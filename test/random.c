/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-batt <ale-batt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 14:52:48 by ale-batt          #+#    #+#             */
/*   Updated: 2016/10/26 18:19:26 by ale-batt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"
#include <fcntl.h>
#include <time.h>

void rand_test(int len, int x_max)
{
	char **tab;
	int i = 0;
	int rdm;

	tab = (char **)malloc(sizeof(char *) * (len + 1));
	tab[len] = NULL;
	srand(time(NULL));
	while (i < len)
	{
		rdm = (rand() % x_max) + 1;
		tab[i] = (char *)malloc(sizeof(char) * (rdm + 1));
		if (!tab[i])
			ft_putendl_color("MALLOC RETURN NULL ERROR", RED);
		tab[i] = ft_memset(tab[i], 'x', rdm);
		tab[i][0] -= 32;
		tab[i][rdm - 1] = '|';
		tab[i][rdm] = '\0';
		i++;
	}
	i = 0;
	show_alloc_mem();
	while (tab[i])
	{
		free(tab[i]);
		i += 1;
	}
	free(tab);
}


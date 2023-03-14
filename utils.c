/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:57:39 by migmarti          #+#    #+#             */
/*   Updated: 2023/03/04 12:47:48 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	word_count(char	**strs)
{
	int	count;

	count = 0;
	while(strs[count])
		count++;
	return (count);
}

void	free_split(char **list)
{
	int		i;

	if (list == NULL || *list == NULL)
		return ;
	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

// 0-1-2
// | |
// 1 2

// 0 0 0 0
// 0 0 0 0
// 0 0 0 0

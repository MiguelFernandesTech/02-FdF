/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:23:30 by migmarti          #+#    #+#             */
/*   Updated: 2023/03/14 15:12:15 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Function where im gonna acess the data from f(x), f(y)
void	height_file(t_data *img, char *file_name)
{
	char 	*str;
	char	**strs;
	int		line;
	int		fd;

	line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error on file.");
		exit(1);
	}
	str = get_next_line(fd);
	line++;
	strs = ft_split(str, ' ');
	img->width_map = word_count(strs);
	free(str);
	free_split(strs);
	while((str = get_next_line(fd)))
	{
		free(str);
		line++;
	}
	img->height_map = line;
	// free_split(strs);
	close(fd);
}

void	width_file(t_data *img, char *file_name)
{
	int		fd;
	//int		**map;
	int		i;
	int		j;
	char	*str;
	char	**strs;

	// j = 0;
	img->map = (int **)malloc(sizeof(int *) * img->height_map);
	fd = open (file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error on opening mapfile.");
		exit(1);
	}
	i = 0;
	while (i < img->height_map)
	{
		str = get_next_line(fd);
		strs = ft_split(str, ' ');
		img->map[i] = (int *) malloc(sizeof(int) * img->width_map);
		j = 0;
		while(j < img->width_map)
		{
			img->map[i][j] = ft_atoi(strs[j]);
			// free(map[i]);
			j++;
		}
		free_split(strs);
		free(str);
		i++;
	}
	close(fd);
}

void	read_map(t_data *img, char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error on file.");
		exit(1);
	}
	height_file(img, file_name);
	width_file(img, file_name);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:51:08 by migmarti          #+#    #+#             */
/*   Updated: 2023/03/14 15:00:24 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "./libft/libft.h"
#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <X11/X.h>

typedef struct s_iso
{
	int scale;
	int transl_x;
	int transl_y;
	float rot_z;
	float rot_y;
	float rot_x;
} t_iso;

typedef struct s_iso_res
{
	int x;
	int y;
	int z;
} t_iso_res;

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int width_map;
	int height_map;
	int **map;
	int color;
	int proj;
	t_iso iso;
} t_data;



void free_split(char **list);
int word_count(char **strs);
void height_file(t_data *img, char *file_name);
void width_file(t_data *img, char *file_name);
void read_map(t_data *img, char *file_name);
void print_map(t_data *img);
void bresenham(t_data *img, int x0, int y0, int x1, int y1);
t_iso_res ft_isometric(t_data *img, int x, int y, int z);
void draw(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	deal_key(int key, t_data *img);
#endif

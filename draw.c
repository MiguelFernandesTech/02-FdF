/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:22:02 by migmarti          #+#    #+#             */
/*   Updated: 2023/03/14 16:42:51 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	my_limits(t_data *data, int x, int y)
{

	if (x < data->width_map && x > 0 && y < data->height_map && y > 0)
		return (1);
	else
		return (0);
}

t_iso_res	ft_isometric(t_data *img, int x, int y, int z)
{
	float	x0;
	float	y0;
	float	z0;
	//scaling
	x0 = x * img->iso.scale;
	y0 = y * img->iso.scale;
	z0 = z * 2;

	//isometric matrix
	x = x0 * cos(0.80) - y0 * sin(0.80);
	y = y0 * cos(0.80) + x0 * sin(0.80);

	x0 = x;
	y0 = y;

	y = y0 * cos(0.61) - z0 * sin(0.61);
	z = y0 * sin(0.61) + z0 * cos(0.61);
	x = x0;

	x += img->iso.transl_x;
	y += img->iso.transl_y;

	return((t_iso_res){x,y,z});
}
//Function where i'm gonna get values to get the algorithm and draw a line.
void	bresenham(t_data *img, int x0, int y0, int x1, int y1) // [1:1] {3:12}
{
	float	x_step, y_step, x, y;
	int		max, pixels;
	t_iso_res	res, res1;
	int		z0, z1;

	z0 = img->map[y0][x0];
	z1 = img->map[y1][x1];

	//color
	if(z0)
		img->color = 0x00FF0000;
	else
		img->color = 0x0000FFFF;
	x_step = x1 - x0;
	y_step = y1 - y0;

	//3D
	res = ft_isometric(img, x0, y0, z0);
	res1 = ft_isometric(img, x1, y1, z1);
	x0 = res.x;
	y0 = res.y;
	z0 = res.z;
	x1 = res1.x;
	y1 = res1.y;
	z1 = res1.z;

	//Shift
	x_step = (float)x1 - (float)x0;
	y_step = (float)y1 - (float)y0;

	pixels = sqrt((x_step * x_step) + (y_step * y_step));
	max = pixels;
	x_step /= pixels;
	y_step /= pixels;
	x = x0;
	y = y0;
	while(pixels > 0)
	{
		//if(!my_limits(img, (int)x, (int)y))
		my_mlx_pixel_put(img, x, y, img->color);
		x += x_step;
		y += y_step;
		pixels = pixels - 1;
	}
	// free(img);
}
//function to draw multiple lines on a file!
void	draw(t_data *img )
{
	int x;
	int y;

	y = 0;
	while (y < img->height_map)
	{
		x = 0;
		while(x < img->width_map)
		{
			if (x != img->width_map - 1)
				bresenham(img, x, y, x + 1, y);
			if (y != img->height_map - 1)
				bresenham(img, x, y , x, y + 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

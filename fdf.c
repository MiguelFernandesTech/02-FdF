/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <migmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:51:28 by migmarti          #+#    #+#             */
/*   Updated: 2023/03/14 16:40:56 by migmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_data *img)
{
	if(key == 65307)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		for (int i=0; i<img->height_map; ++i)
			free(img->map[i]);
		free(img->map);
		free(img);
	}
	exit(1);
}

t_data	*init_data(void)
{
	t_data *data;

	if(!(data = (t_data * )malloc(sizeof(t_data))))
		return(NULL);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "fdf");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->iso.scale = 20;
	data->iso.transl_x = 900;
	data->iso.transl_y = 350;
	data->iso.rot_x = 0.61;
	data->iso.rot_y = 0.;
	data->iso.rot_z = 0.;
	data->endian = 0;
	data->width_map = 0;
	data->height_map = 0;
	data->map = NULL;
	data->proj = 1;
	data->color = 0xFFFFFF;
	return(data);
}

int	main(int argc, char **argv)
{
	t_data	*img;

	img = init_data();
	(void)argv;
	if (argc != 2)
	{
		printf("No input, Try to run a file!/n");
		return(0);
	}
	read_map(img, argv[1]);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	draw(img);
	mlx_hook(img->mlx_win, KeyPress, KeyPressMask, deal_key, img);
	mlx_loop(img->mlx);
}

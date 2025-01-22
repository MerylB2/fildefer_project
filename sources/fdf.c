/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:25:41 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 03:32:29 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/macros.h"

void	initialize_camera(t_camera *camera)
{
	if (!camera)
		return ;

	camera->zoom = ZOOM_DEFAULT;
	camera->angle_x = 0.0;
	camera->angle_y = 0.0;
	camera->angle_z = 0.0;
	camera->offset_x = WIN_WIDTH / 2;
	camera->offset_y = WIN_HEIGHT / 2;
}

void	initialize_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_exit(ERR_MLX_INIT);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!data->win)
		error_exit(ERR_WINDOW_INIT);
	data->img = safe_malloc(sizeof(t_img));
	data->img->img_ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img->img_ptr)
		error_exit(ERR_IMAGE_INIT);
	data->camera = safe_malloc(sizeof(t_camera));
	initialize_camera(data->camera);
}

void	load_map(t_data *data, const char *filename)
{
	char	**lines;

	lines = read_file(filename);
	data->map = parse_map(lines);
}

void	start_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, handle_keys, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_exit("Usage: ./fdf <map_file>");
	initialize_data(&data);
	load_map(&data, argv[1]);
	render_map(&data);
	start_hooks(&data);
	clean_exit(&data);
	return (0);
}

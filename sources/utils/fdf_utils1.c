/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:55:49 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 00:47:19 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/macros.h"

t_point	**allocate_points(size_t rows, size_t cols)
{
	t_point	**points;
	size_t	i;

	i = 0;
	points = safe_malloc(rows * sizeof(t_point *));
	while (i < rows)
	{
		points[i] = safe_malloc(cols * sizeof(t_point));
		i++;
	}
	return (points);
}

t_map	*allocate_map(size_t rows, size_t cols)
{
	t_map	*map;

	map = safe_malloc(sizeof(t_map));
	map->rows = rows;
	map->cols = cols;
	map->points = allocate_points(rows, cols);
	return (map);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (i < map->rows)
	{
		free(map->points[i]);
		i++;
	}
	free(map->points);
	free(map);
}

void	free_resources(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->img && data->img->img_ptr)
		mlx_destroy_image(data->mlx, data->img->img_ptr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	free(data->camera);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:28:48 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/20 22:46:07 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "macros.h"

void	render_horz_lines(t_data *data, size_t row)
{
	size_t	col;
	t_point	start;
	t_point	end;

	col = 0;
	while (col + 1 < data->map->cols)
	{
		start = data->map->points[row][col];
		end = data->map->points[row][col + 1];
		draw_line(data, start, end);
		col++;
	}
}

void	render_vert_lines(t_data *data, size_t row)
{
	size_t	col;
	t_point	start;
	t_point	end;

	col = 0;
	while (col < data->map->cols)
	{
		if (row + 1 < data->map->rows)
		{
			start = data->map->points[row][col];
			end = data->map->points[row + 1][col];
			draw_line(data, start, end);
		}
		col++;
	}
}

void	render_map(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map->rows)
	{
		render_horz_lines(data, i);
		render_vert_lines(data, i);
		i++;
	}
}

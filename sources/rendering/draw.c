/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:48:42 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 02:20:14 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/macros.h"

void	line_params_init(t_line_params *params, t_point start, t_point end)
{
	params->delta_x = abs(end.x - start.x);
	params->delta_y = abs(end.y - start.y);
	if (start.x < end.x)
		params->sig_x = 1;
	else
		params->sig_x = -1;
	if (start.y < end.y)
		params->sig_y = 1;
	else
		params->sig_y = -1;
	params->error = params->delta_x - params->delta_y;
}

void	update_pos_point(t_point *start, t_line_params *params)
{
	int	err2;

	err2 = params->error;
	if (err2 > -(params->delta_y))
	{
		params->error -= params->delta_y;
		start->x += params->sig_x;
	}
	if (err2 < params->delta_x)
	{
		params->error += params->delta_x;
		start->y += params->sig_y;
	}
}

void	trace_line(t_data *data, t_point *s, t_point *e, t_line_params *params)
{
	while (s->x != e->x || s->y != e->y)
	{
		mlx_pixel_put(data->mlx, data->win, s->x, s->y, s->color);
		update_pos_point(s, params);
	}
}

void	draw_line(t_data *data, t_point start, t_point end)
{
	t_line_params	params;

	line_params_init(&params, start, end);
	trace_line(data, &start, &end, &params);
}

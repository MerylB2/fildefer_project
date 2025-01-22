/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:39:56 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 00:47:19 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/macros.h"

int	handle_keys(int key, t_data *data)
{
	if (key == ESC_KEY)
		clean_exit(data);
	if (key == ZOOM_IN)
		data->camera->zoom *= 1.1;
	if (key == ZOOM_OUT)
		data->camera->zoom *= 0.9;
	if (key == ARROW_UP)
		data->camera->offset_y -= 10;
	if (key == ARROW_DOWN)
		data->camera->offset_y += 10;
	if (key == ARROW_LEFT)
		data->camera->offset_x -= 10;
	if (key == ARROW_RIGHT)
		data->camera->offset_x += 10;
	if (key == ROTATE_LEFT)
		data->camera->angle_z -= 0.1;
	if (key == ROTATE_RIGHT)
		data->camera->angle_z += 0.1;
	render_map(data);
	return (0);
}


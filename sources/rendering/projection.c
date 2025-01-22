/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:40:10 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 00:47:19 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/macros.h"

void	proj_isometric(t_point *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (prev_x - prev_x) * cos(ISO_ANGLE);
	point->y = (prev_x + prev_y) * sin(ISO_ANGLE) - point->z;
}

void	proj_parallel(t_point *point)
{
	point->x = point->x;
	point->y = point->y - point->z;
}

void	fdf_rotation(t_point *point, t_camera *camera)
{
	float	prev_x;
	float	prev_y;
	float	prev_z;

	prev_x = point->x;
	prev_y = point->y;
	prev_z = point->z;
	point->y = prev_y * cos(camera->angle_x) - prev_z * sin(camera->angle_x);
	point->z = prev_y * sin(camera->angle_x) + prev_z * cos(camera->angle_x);

	prev_x = point->x;
	point->x = prev_x * cos(camera->angle_y) + point->z * sin(camera->angle_y);
	point->z = -prev_x * sin(camera->angle_y) + point->z * cos(camera->angle_y);

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(camera->angle_z) - prev_y * sin(camera->angle_z);
	point->y = prev_x * sin(camera->angle_z) + prev_y * cos(camera->angle_z);
}


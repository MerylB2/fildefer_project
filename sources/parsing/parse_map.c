/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:00:42 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 03:04:50 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/macros.h"

size_t	count_columns(char *line)
{
	size_t	count;
	char	**split;

	count = 0;
	split = ft_split(line, ' ');
	while (split[count])
		count++;
	free_split(split);
	return (count);
}

size_t	count_lines(char **lines)
{
	size_t	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

t_map	*parse_map(char **lines)
{
	size_t	rows;
	size_t	cols;
	size_t	i;
	t_map	*map;

	i = 0;
	rows = count_lines(lines);
	cols = count_columns(lines[0]);
	map = allocate_map(rows, cols);
	while (lines[i])
	{
		parse_line(lines[i], map, i);
		i++;
	}
	free_split(lines);
	return (map);
}

void	parse_line(char *line, t_map *map, size_t row)
{
	size_t	col;
	char	**values;

	col = 0;
	values = ft_split(line, ' ');
	while (values[col])
	{
		map->points[row][col].x = col;
		map->points[row][col].y = row;
		map->points[row][col].z = ft_atoi(values[col]);
		map->points[row][col].color = COLOR_WHITE;
		col++;
	}
	free_split(values);
}

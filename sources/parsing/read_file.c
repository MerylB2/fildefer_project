/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:34:16 by asiatik           #+#    #+#             */
/*   Updated: 2025/01/21 03:02:44 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/macros.h"

char	**ft_realloc_tab(char **tab, char *new_line, size_t count)
{
	char	**new_tab;
	char	**old_tab_ptr;

	new_tab = malloc((count + 2) * sizeof(char *));
	if (!new_tab)
		error_exit(ERR_MEMORY_ALLOC);
	old_tab_ptr = tab;
	while (count--)
	{
		*new_tab = *old_tab_ptr;
		new_tab++;
		old_tab_ptr++;
	}
	*new_tab = ft_strdup(new_line);
	if (!new_tab)
		error_exit(ERR_MEMORY_ALLOC);
	new_tab++;
	*new_tab = NULL;
	free(tab);
	return (new_tab - (count + 2));
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**read_file(const char *file)
{
	char	*line;
	char	**lines;
	size_t	count;
	int		fd;

	count = 0;
	lines = NULL;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("ERR_FILE_OPEN");
	while ((line == get_next_line(fd)))
	{
		lines = ft_realloc_tab(lines, line, count);
		count++;
		free(line);
	}
	close(fd);
	return (lines);
}

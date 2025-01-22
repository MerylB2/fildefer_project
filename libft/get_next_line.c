/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:18:08 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/01/20 12:30:56 by asiatik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"
#include "stdio.h"

char	*read_file_from_fd(char *s, int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!find_chargnl(s, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(s);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		s = ft_strjoingnl(s, buffer);
	}
	return (free(buffer), s);
}

char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = malloc(i + 1);
	else
		line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_line(char *str)
{
	char	*nline_pos;
	int		i;
	int		j;

	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	nline_pos = malloc(sizeof(char) * (ft_strlengnl(str) - i + 1));
	if (!nline_pos)
	{
		free(nline_pos);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		nline_pos[j++] = str[i++];
	nline_pos[j] = '\0';
	free(str);
	return (nline_pos);
}

char	*get_next_line(int fd)
{
	static char	*r_line;
	char		*n_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!r_line)
	{
		r_line = malloc(1);
		r_line[0] = '\0';
	}
	r_line = read_file_from_fd(r_line, fd);
	if (!r_line)
		return (NULL);
	n_line = extract_line(r_line);
	r_line = clean_line(r_line);
	return (n_line);
}

// int main(void)
// {
// 	int 	fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%d\n", fd);
// 	if (fd < 0)
// 	{
// 		printf("Failed to open file.");
// 		return 0;
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// }
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("%s", line);
		free(line);
	}
	return (close(fd));
}*/
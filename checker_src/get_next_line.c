/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:15:41 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/17 15:16:37 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_bool	check_file(char *file)
{
	size_t	i;
	t_bool	res;

	i = 0;
	res = IS_EMPTY;
	if (file == NULL)
		return (FILE_NULL);
	while (i <= BUFFER_SIZE)
	{
		if (file[i] == '\n')
			return (NEW_LINE);
		if (file[i] != '\0')
			res = HAS_CONTENT;
		i++;
	}
	return (res);
}

void	add_content(char *line, char *file)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (line[len] != '\0')
		len++;
	while (file[i] && file[i] != '\n' && i < BUFFER_SIZE)
	{
		line[len + i] = file[i];
		file[i] = '\0';
		i++;
	}
	if (file[i] == '\n')
	{
		line[len + i] = '\n';
		line[len + i + 1] = '\0';
		return ;
	}
	line[len + i] = '\0';
}

char	*get_line_(char *line, char *file)
{
	size_t	file_size;

	if (file == NULL)
		return (NULL);
	file_size = strline(file);
	line = ft_realloc(file_size, line);
	if (line == NULL)
		return (NULL);
	add_content(line, file);
	return (line);
}

char	*process_gnl(char *file, char *line, int fd)
{
	int	read_res;

	while (check_file(file) != NEW_LINE)
	{
		read_res = read(fd, file, BUFFER_SIZE);
		if (read_res < 0)
			return (free_line(line));
		if (read_res <= 0)
			return (line);
		line = get_line_(line, file);
		if (line == NULL)
			return (free_line(line));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	file[BUFFER_SIZE];
	char		*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (check_file(file) == HAS_CONTENT
			|| check_file(file) == NEW_LINE)
		line = get_line_(line, file);
	line = process_gnl(file, line, fd);
	move_data(file);
	return (line);
}

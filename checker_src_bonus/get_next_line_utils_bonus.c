/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:34:37 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/12 16:53:18 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_realloc(size_t size, char *line)
{
	char	*new_buff;
	size_t	i;

	i = 0;
	new_buff = NULL;
	new_buff = malloc((size + strline(line) + 1) * sizeof(char));
	if (new_buff == NULL)
	{
		if (line != NULL)
			free(line);
		return (NULL);
	}
	if (line != NULL)
	{
		while (line[i])
		{
			new_buff[i] = line[i];
			i++;
		}
	}
	if (line != NULL)
		free(line);
	new_buff[i] = '\0';
	return (new_buff);
}

size_t	strline(char *file)
{
	size_t	i;

	i = 0;
	if (file == NULL)
		return (0);
	while (file[i] && file[i] != '\n')
		i++;
	return (i + 1);
}

void	move_data(char *file)
{
	size_t		i;
	size_t		j;
	t_file		first_new_line;

	i = 0;
	j = 0;
	first_new_line = 0;
	while (i < BUFFER_SIZE)
	{
		if (file[i] != '\0' && first_new_line == 1)
		{
			file[j] = file[i];
			file[i] = '\0';
			j++;
		}
		if (file[i] == '\n' && first_new_line == 0)
		{
			file[i] = '\0';
			first_new_line = 1;
		}
		i++;
	}
}

void	*free_line(char *line)
{
	if (line)
		free(line);
	return (NULL);
}

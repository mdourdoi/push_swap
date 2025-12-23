/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:54:26 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_mel.h"

static char	*get_str(const char *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	get_size(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (s[0] != c && s[0])
		size++;
	if (c == 0)
		return (size);
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			size++;
		i++;
	}
	return (size);
}

static void	free_grid(char **grid, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (grid[i] != NULL)
			free(grid[i]);
		i++;
	}
	free(grid);
}

static int	spliting(char **grid, char const *s, char c, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && (j < size))
	{
		if (s[i] != c)
		{
			grid[j] = get_str(&s[i], c);
			if (grid[j - 1] == NULL)
			{
				free_grid(grid, size);
				return (-1);
			}
			i += ft_strlen(grid[j]);
			j++;
		}
		i++;
	}
	grid[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**grid;
	size_t	size;

	grid = NULL;
	if (s == NULL)
		return (NULL);
	size = get_size(s, c);
	grid = malloc((size + 1) * sizeof(char *));
	if (grid == NULL)
		return (NULL);
	if (spliting(grid, s, c, size) == 1)
		return (grid);
	return (NULL);
}

/*
#include <stdio.h>

size_t	grid_size(char **grid)
{
	size_t	i;

	i = 0;
	while (grid[i])
		i++;
	return(i);
}

void	test_split(char	const *s, char c)
{
	printf("s: '%s'\n c: '%c'\n", s, c);
	char **grid = ft_split(s, c);
	size_t	i = 0;

	while (grid[i] != NULL)
	{
		printf("%s\n", grid[i]);
		i++;
	}
	printf("%s\n", grid[i]);
	printf("\n");
	free_grid(grid, grid_size(grid));
}

int	main()
{
	
	test_split(NULL, ' ');	
	test_split("  test  ", ' ');	
	test_split("test  ", ' ');	
	test_split("", ' ');	
	test_split("xxxxxxxxxxxqbhxxxhhh", 'x');	
	
	return (0);
}*/

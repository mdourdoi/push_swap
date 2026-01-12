/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:59:59 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/12 17:25:35 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	6
# endif

typedef enum e_file
{
	HAS_CONTENT,
	NEW_LINE,
	FILE_NULL,
	IS_EMPTY
}	t_file;

char	*get_next_line(int fd);
char	*ft_realloc(size_t size, char *line);
size_t	strline(char *file);
void	move_data(char *file);
void	*free_line(char *line);

#endif

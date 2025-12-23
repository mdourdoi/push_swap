/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:59:59 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/14 16:03:35 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	6
# endif

typedef enum e_bool
{
	HAS_CONTENT,
	NEW_LINE,
	FILE_NULL,
	IS_EMPTY
}	t_bool;

char	*get_next_line(int fd);
char	*ft_realloc(size_t size, char *line);
char	*init_buffer(void);
size_t	strline(char *file);
void	move_data(char *file);
void	*free_line(char *line);

#endif

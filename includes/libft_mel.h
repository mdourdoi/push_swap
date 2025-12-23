/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:25:36 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/17 11:27:14 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEL_H
# define LIBFT_MEL_H

#include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index; 
	struct s_list	*next;
}					t_list;

void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *src, int c, size_t n);
void	ft_bzero(void *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int	    ft_isdigit(int c);
int	    ft_isascii(int c);

#endif

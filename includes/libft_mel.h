/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:25:36 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/18 14:16:35 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index; 
	struct s_list	*next;
}					t_list;

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *src, size_t n);
void	*ft_memset(void *src, int c, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int	ft_isdigit(int c);
int	ft_isascii(int c);
int	ft_atoi(char *nptr);

#endif

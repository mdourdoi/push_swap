/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:57:33 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 11:32:56 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index; 
	struct s_list	*next;
}					t_list;

//Enum t_bool : 
//	for easier readeable function return 

typedef enum	e_bool
{
	FALSE,
	TRUE
}	t_bool;

t_bool	ft_atoi(char *nptr, int *value);
void	ft_bzero(void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int	    ft_isascii(int c);
int	    ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	*ft_memset(void *src, int c, size_t n);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *str1, char *str2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif

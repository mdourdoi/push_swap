/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:28:11 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/18 14:12:22 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

void	ft_swap(t_list **stack, char c, int flag);
void	ft_swap_both(t_list *a, t_list *b);
void	ft_push(t_list **stack1, char c1, t_list **stack2);
void	ft_rotate(t_list **stack, char c, int flag);
void	ft_rotate_both(t_list *a, t_list *b);
void	ft_reverse_rotate(t_list **stack, char c, int flag);
void	ft_reverse_rotate_both(t_list *a, t_list *b);
float	ft_get_disorder(t_list *stack);
void	ft_selectionsort(t_list **a, t_list **b);
int		ft_issorted(t_list *a);
void	set_index(t_list *a);

void	print_stack(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:28:11 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/18 15:19:41 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "rules.h"
# include "bench.h"

void	ft_swap(t_list **stack, char c, int flag, t_rule *rule);
void	ft_swap_both(t_list *a, t_list *b, t_rule *rule);
void	ft_push(t_list **stack1, char c1, t_list **stack2, t_rule *rule);
void	ft_rotate(t_list **stack, char c, int flag, t_rule *rule);
void	ft_rotate_both(t_list *a, t_list *b, t_rule *rule);
void	ft_reverse_rotate(t_list **stack, char c, int flag, t_rule *rule);
void	ft_reverse_rotate_both(t_list *a, t_list *b, t_rule *rule);
float	ft_get_disorder(t_list *stack);
void	ft_selectionsort(t_list **a, t_list **b, t_rule *rule);
int		ft_issorted(t_list *a);
void	set_index(t_list *a);
void	gateway(t_rule *rule, t_list **a, t_list **b);
int		ft_minpos(t_list *a);
int		ft_maxpos(t_list *a);
int		ft_get_first_index(t_list *a, int low, int high);
int		ft_get_last_index(t_list *a, int low, int high);
int		ft_sqrt_round(int n);
void	ft_select_rot(t_list **stack, char str_stack, int rot, int rev_rot, t_rule *rules);
void	ft_bucketsort(t_list **a, t_list **b, t_rule *rules);

#endif

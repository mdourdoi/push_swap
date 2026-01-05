/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gateway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:31:50 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/05 11:26:18 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include "push_swap.h"

/*
	Check_disorder : 

 		This function will set the mode by checking the disorder
 			of the stack a
*/

void	check_disorder(t_rule *rule)
{
	if (rule->disorder < 0.2)
		rule->mode = SIMPLE;
	if (rule->disorder >= 0.2 && rule->disorder < 0.5)
		rule->mode = MEDIUM;
	if (rule->disorder >= 0.5)
		rule->mode = COMPLEX;
}

/*
 Gateway : 

 		This function will choose the correct sort algorithm 
 			by checking the rules struct
*/

void	gateway(t_rule *rule, t_list **a, t_list **b)
{
	if (rule->mode == ADAPTIVE)
		check_disorder(rule);
	if (rule->mode == SIMPLE)
		ft_selectionsort(a, b, rule);
	if (rule->mode == MEDIUM)
		ft_bucketsort(a, b, rule);
	if (rule->mode == COMPLEX)
		ft_radix_sort(a, b, rule);
}

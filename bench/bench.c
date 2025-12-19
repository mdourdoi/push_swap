/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:30:37 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/19 15:37:53 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include "ft_printf.h"

void	display_benchmark(t_rule *rule)
{
	ft_printf("[bench] disorder: float");
	ft_printf("[bench] strategy: %s", get_strategy(rule->mode));
	ft_printf("[bench] total_ops: %s", get_total_op(rule->operation));
	print_op(rule->operation);
}

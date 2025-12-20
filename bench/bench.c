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

// Print_op : 
//      
//      This function will display every operations that has been 
//          used to sort the stack

void    print_op(int *op)
{
    ft_printf("[bench] sa:  %d  sb:  %d", op[SA], op[SB]);
    ft_printf("  ss:  %d  pa:  %d  pb:  %d\n", op[SS], op[PA], op[PB]);
    ft_printf("[bench] ra:  %d  rb:  %d", op[RA], op[RB]);
    ft_printf("  rr:  %d  rra:  %d   rrb:  %d\n", op[RR], op[RRA], op[RRB]);
}

// Get_total_op : 
//
//      This function will return the number of operations procceed
//          for sorting the stack

int get_total_op(int *op)
{
    size_t  total;
    size_t  i;

    i = 0;
    total = 0;
    while (i < 11)
    {
        total += op[i];
        i++;
    }
    return (total);
}

void    print_strategy(t_mode mode)
{
    if (mode == ADAPTIVE)
	    ft_printf("[bench] strategy: ADAPTIVE\n");
    if (mode == SIMPLE)
	    ft_printf("[bench] strategy: SIMPLE\n");
    if (mode == MEDIUM)
	    ft_printf("[bench] strategy: MEDIUM\n");
    if (mode == COMPLEX)
	    ft_printf("[bench] strategy: COMPLEX\n");
        
}

// Display_benchmark : 
//
//      This function will display the benchmarks of the program 
//          if the bench mode has been enabled

void	display_benchmark(t_rule *rule)
{
	ft_printf("[bench] disorder: float%%\n");
    print_strategy(rule->mode);
	ft_printf("[bench] total_ops: %d\n", get_total_op(rule->operation));
	print_op(rule->operation);
}

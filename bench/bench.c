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
#include "print_errf.h"

/* Print_op : 
      
      This function will display every operations that has been 
          used to sort the stack
*/

static void	print_op(int *op)
{
	print_errf("[bench] sa:  %d  sb:  %d", op[SA], op[SB]);
	print_errf("  ss:  %d  pa:  %d  pb:  %d\n", op[SS], op[PA], op[PB]);
	print_errf("[bench] ra:  %d  rb:  %d", op[RA], op[RB]);
	print_errf("  rr:  %d  rra:  %d   rrb:  %d\n", op[RR], op[RRA], op[RRB]);
}

/* Get_total_op : 

      This function will return the number of operations procceed
          for sorting the stack
*/

static int	get_total_op(int *op)
{
	size_t	total;
	size_t	i;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += op[i];
		i++;
	}
	return (total);
}

static void	check_adaptive(t_rule *rule)
{
	print_errf("Adaptive / ");
	if (rule->mode == SIMPLE)
		print_errf("O(n * n)\n");
	if (rule->mode == MEDIUM)
		print_errf("O(n * sqrt(n))\n");
	if (rule->mode == COMPLEX)
		print_errf("O(nlog(n))\n");
	if (rule->mode == ADAPTIVE)
		print_errf("\n");
}

static void	print_strategy(t_rule *rule)
{
	print_errf("[bench] strategy: ");
	if (rule->adaptive == TRUE)
	{
		check_adaptive(rule);
		return ;
	}
	if (rule->mode == SIMPLE)
		print_errf("SIMPLE\n");
	if (rule->mode == MEDIUM)
		print_errf("MEDIUM\n");
	if (rule->mode == COMPLEX)
		print_errf("COMPLEX\n");
}

/* Display_benchmark : 

      This function will display the benchmarks of the program 
          if the bench mode has been enabled
*/

void	display_benchmark(t_rule *rule)
{
	print_errf("[bench] disorder: %f%%\n", rule->disorder);
	print_strategy(rule);
	print_errf("[bench] total_ops: %d\n", get_total_op(rule->operation));
	print_op(rule->operation);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:20:33 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/16 18:37:12 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "rules.h"
#include "push_swap.h"

// Parsing section :
// 		Must parse and verify the entry from the user : 
//
// 		There are 2 types of entry that must be parsed : 
// 			- The numbers given as a string and must be integer values
// 			- The Mode that specify the strategy choosed for the sorting 
//
// 		Mode : 
// 			--simple for O(n^2) algorithm
// 			--medium for O(nVn) algorithm
// 			--complex for O(nlog(n)) algorithm
// 			--adaptive the algorithm is based on the state of disorder of the stack



// Parse_args : 
//
// 		This function will verify, parse and return a pointer to the stack list of element
// 			
// 		return value : 
// 			t_list **stack if everything is fine
// 			NULL if the stack is empty or an error occur

t_list	**parse_args(int ac, char **av, t_rule *rule)
{
	t_list	**stack;
	
	stack = NULL;
	if (check_for_rules(ac, av, rule) == TRUE)
	{
		// Start parsing	
	}
	else 
		return (stack);
}

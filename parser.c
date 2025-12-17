/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:20:33 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/17 11:39:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft_mel/libft.h"
#include "rules.h"

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


void	*clear_stack()

//	Check_stack_creation : 
//
//		This function will check if the stack created from the user input is correct
//		A correct stack :
//			Has no double element number
//			Has the correct number of element 
//
//		return the stack if everything is fine 
//		return NULL if the stack is false
//

t_list	*check_stack_creation(t_list *stack, int ac, char **av)
{
	size_t	len;
	t_bool	dict[UINT_MAX];

	len = 0;
	if (is_valid_digit(av[ac - 1]) == FALSE)
		ac--;
	while (stack->next != NULL)
	{
		if (dict[(stack->content) + INT_MAX] != TRUE)
			dict[(stack->content) + INT_MAX] = TRUE;
		else
		 	return (clear_stack(stack));
		stack = stack->next;
		len++;
	}
	if (len != ac - 1)
		return (clear_stack(stack));
	return (stack);
}

//	Get_stack : 
//
//		This function create the stack using the args given by the user
//
//		return a pointer to the first node of the stack if everything is fine
//		return NULL if an error occur 

t_list	*get_stack(char **av, int ac)
{
	size_t	i;
	t_list	*stack;

	i = 0;
	while (is_valid_digit(av[i]) == TRUE)
	{
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (check_stack_creation(stack, ac));
}

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
		*stack = get_stack(av, ac);
	return (stack);
}

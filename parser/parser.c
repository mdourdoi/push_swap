/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:20:33 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/18 17:03:48 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mel.h"
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


// Clear_stack : 
//
// 		This function will clear the stack && return NULL

void	*clear_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
	return (NULL);
}

// Check_double : 
//
// 		This function will if there's double value in the stack 
// 			by checking a dictionary using hash set algorithm
//
// 		return (TRUE) if double exist 
// 		return (FALSE) if everything is fine

t_bool	check_double(t_list *stack)
{
	int	value;

	value = stack->content;
	stack = stack->next;
	while (stack != NULL)
	{
		if ((stack->content) == value)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

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

t_list	*check_stack_creation(t_list *stack, int nb_elem, t_rule *rule)
{
	int	len;
	t_list	*test;

	len = 1;
	test = stack;
	while (test != NULL)
	{
		if (check_double(test) == TRUE)
		 	return (clear_stack(stack));
		len++;
		test = test->next;
	}
	if (len != nb_elem)
		return (clear_stack(stack));
	rule->nb_element = len;
	return (stack);
}

//	Get_stack : 
//
//		This function create the stack using the args given by the user
//
//		return a pointer to the first node of the stack if everything is fine
//		return NULL if an error occur 

t_list	*get_stack(char **av, int ac, t_list *stack, t_rule *rule)
{
	int	i;
    int content;

	i = 0;
	stack = NULL;
	while (av[i])
	{
		if (is_valid_digit(av[i]) == TRUE && ft_atoi(av[i], &content) == TRUE)
		ft_lstadd_back(&stack, ft_lstnew(content));
		i++;
	}
	return (check_stack_creation(stack, number_of_elem(rule, ac), rule));
}

// Parse_args : 
//
// 		This function will verify, parse and return a pointer to the stack list of element
// 			
// 		return value : 
// 			t_list **stack if everything is fine
// 			NULL if the stack is empty or an error occur

t_list	*parse_args(int ac, char **av, t_rule *rule)
{
	t_list	*stack;
	
	stack = NULL;
	if (ac == 0 || av == NULL || av[0] == NULL)
		return (NULL);
	if (check_for_rules(av, rule) == TRUE)
		stack = get_stack(av, ac, stack, rule);
	return (stack);
}

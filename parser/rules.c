/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:36:37 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/12 20:04:50 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

/*
 Init_rule : 

 This function will initialize the rule struct correctly
*/

void	init_rule(t_rule *rule)
{
	size_t	i;

	i = 0;
	rule->mode = ADAPTIVE;
	rule->bench = FALSE;
	rule->checker = FALSE;
	rule->flags = FALSE;
	rule->adaptive = FALSE;
	rule->disorder = 0;
	rule->nb_element = 0;
	rule->is_valid = 1;
	while (i < 11)
	{
		rule->operation[i] = 0;
		i++;
	}
}

/*
 Is_valid_digit : 
 		check if the current string is a valid digit for the programm
 			a valid digit is a string representing a int (32bit)

 		return TRUE if yes
 		return FALSE if no
*/

t_bool	is_valid_digit(char *nb)
{
	size_t		i;
	short int	count;

	i = 0;
	count = 0;
	while (nb[i])
	{
		if (nb[i] == '-')
		{
			count++;
			i++;
		}
		if (count > 1)
			return (FALSE);
		if (ft_isdigit(nb[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
 determine_mode : 
 		This function will determine the mode given 
 			by the user and set it into rules

 		return TRUE if everything is fine 
 		return FALSE if an error occur
*/

t_bool	determine_mode(char *av, t_rule *rule, t_bool *mode, t_bool *bench)
{
	if (ft_strcmp(av, "--simple") == 0 && *mode == FALSE)
		return (set_simple(mode, rule));
	if (ft_strcmp(av, "--medium") == 0 && *mode == FALSE)
		return (set_medium(mode, rule));
	if (ft_strcmp(av, "--complex") == 0 && *mode == FALSE)
		return (set_complex(mode, rule));
	if (ft_strcmp(av, "--adaptive") == 0 && *mode == FALSE)
		return (set_adaptive(mode, rule));
	if (ft_strcmp(av, "--bench") == 0 && *bench == FALSE)
		return (set_bench(bench, rule));
	return (FALSE);
}

/*
 Check_for_rules : 

 		this function will verify if the last argument is a 
 			mode given by the user

 		return (TRUE) if everything is fine 
 		return (FALSE) if an error occur
*/

int	check_for_rules(char **av, t_rule *rule)
{
	size_t	i;
	t_bool	mode;
	t_bool	bench;
	int		j;

	i = 0;
	j = 0;
	mode = FALSE;
	bench = FALSE;
	while (av[i] && i < 2)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (determine_mode(av[i], rule, &mode, &bench) == FALSE)
			{
				rule->is_valid = 0;
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (j);
}

/*
 Number_of_elem : 

 	This function will set the theorical number of elem in the stack
 		by looking at the rule and the argument count variable
*/

int	number_of_elem(t_rule *rule, int ac)
{
	if (rule->bench == TRUE)
		ac--;
	if (rule->flags == TRUE)
		ac--;
	return (ac);
}

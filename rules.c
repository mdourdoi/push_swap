/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:36:37 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/17 11:32:24 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rules.h"

// Is_valid_digit : 
// 		check if the current string is a valid digit for the programm
// 			a valid digit is a string representing a int (32bit)
//
// 		return TRUE if yes
// 		return FALSE if no

t_bool	is_valid_digit(char *nb)
{
	size_t	i;
	short int count;

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

// determine_mode : 
// 		This function will determine the mode given 
// 			by the user and set it into rules
//
// 		return TRUE if everything is fine 
// 		return FALSE if an error occur

t_bool	determine_mode(char *av, t_rule *rule)
{
	if (ft_strcmp(av, "--simple") == 0)
	{
		rule->mode = SIMPLE;
		return (TRUE);
	}
	if (ft_strcmp(av, "--medium") == 0)
	{
		rule->mode = MEDIUM;
		return (TRUE);
	}
	if (ft_strcmp(av, "--complex") == 0)
	{
		rule->mode = COMPLEX;
		return (TRUE);
	}
	if (ft_strcmp(av, "--adaptive") == 0 || is_valid_digit(av) == TRUE)
		return (TRUE);
	return (FALSE);
}

// Check_for_rules : 
//
// 		this function will verify if the last argument is a 
// 			mode given by the user
//
// 		return (TRUE) if everything is fine 
// 		return (FALSE) if an error occur

t_bool	check_for_rules(int ac, char **av, t_rule *rule)
{
	if (av[ac - 1][0] == '-')
	{
		return (determine_mode(av[ac - 1], rule));
	}
	return (FALSE);
}

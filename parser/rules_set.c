/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:39:00 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/18 16:56:11 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

/*
	Set_function : 

 		These following function will set the rule variable 
 			corresponding to their respectives mode 
*/

t_bool	set_simple(t_bool *mode, t_rule *rule)
{
	rule->mode = SIMPLE;
	rule->flags = TRUE;
	*mode = TRUE;
	return (TRUE);
}

t_bool	set_medium(t_bool *mode, t_rule *rule)
{
	rule->mode = MEDIUM;
	rule->flags = TRUE;
	*mode = TRUE;
	return (TRUE);
}

t_bool	set_complex(t_bool *mode, t_rule *rule)
{
	rule->mode = COMPLEX;
	rule->flags = TRUE;
	*mode = TRUE;
	return (TRUE);
}

t_bool	set_adaptive(t_bool *mode, t_rule *rule)
{
	rule->mode = ADAPTIVE;
	rule->flags = TRUE;
	*mode = TRUE;
	return (TRUE);
}

t_bool	set_bench(t_bool *bench, t_rule *rule)
{
	rule->bench = TRUE;
	*bench = TRUE;
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:34:40 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/18 17:03:10 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include <stdlib.h>
# include <limits.h>
# include "libft_mel.h"

// Enum t_mode : For having different mode link with a value,
// 		so readability of the code is OK for our tiny little eyes

typedef enum	e_mode
{
	ADAPTIVE = 1,
	SIMPLE = 2,
	MEDIUM = 3,
	COMPLEX = 4 

}	t_mode;

//Enum t_bool : 
//	for easier readeable function return 

typedef enum	e_bool
{
	FALSE,
	TRUE
}	t_bool;

// Struct t_rule : 
//
// 		For saving state, program mode, the entropy level 
// 		and the number of element in the initial stack

typedef struct	s_rule
{
	t_mode	mode;
	t_bool	bench;
	t_bool	flags;
	float	disorder;
	size_t	nb_element;
}	t_rule;



t_bool	set_simple(t_bool *mode, t_rule *rule);
t_bool	set_medium(t_bool *mode, t_rule *rule);
t_bool	set_complex(t_bool *mode, t_rule *rule);
t_bool	set_adaptive(t_bool *mode, t_rule *rule);
t_bool	set_bench(t_bool *bench, t_rule *rule);
t_bool	determine_mode(char *av, t_rule *rule, t_bool *mode, t_bool *bench);
t_bool	check_for_rules(char **av, t_rule *rule);
t_bool	check_double(t_list *stack);
t_bool	is_valid_digit(char *nb);
t_list	*parse_args(int ac, char **av, t_rule *rule);
void	*clear_stack(t_list *stack);
int		ft_strcmp(char *str1, char *str2);
int		number_of_elem(t_rule *rule, int ac);

#endif

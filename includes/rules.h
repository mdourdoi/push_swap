/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:34:40 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/05 16:35:21 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "libft.h"
# include <limits.h>

// Enum t_oper : 
// 		to enumerate the index of the operation list in 
// 			rule->operation[]

typedef enum e_oper
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10
}	t_oper;

// Enum t_mode : For having different mode link with a value,
// 		so readability of the code is OK for our tiny little eyes

typedef enum e_mode
{
	ADAPTIVE = 1,
	SIMPLE = 2,
	MEDIUM = 3,
	COMPLEX = 4
}	t_mode;

// Struct t_rule : 
//
// 		For saving state, program mode, the entropy level 
// 		and the number of element in the initial stack
//
// 		operation[] will store each operation, by increasing
// 			the number stored in his corresponding key

typedef struct s_rule
{
	t_mode	mode;
	t_bool	bench;
	t_bool	checker;
	t_bool	flags;
	t_bool	adaptive;
	float	disorder;
	size_t	nb_element;
	int		operation[11];
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
char	**harmonize_args(char **argv);
int		args_len(char **args);
void	*clear_stack(t_list *stack);
void	init_rule(t_rule *rule);
int		ft_strcmp(char *str1, char *str2);
int		number_of_elem(t_rule *rule, int ac);

#endif

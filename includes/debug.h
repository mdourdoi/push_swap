/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:09:51 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 16:31:39 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "print_errf.h"
# include "libft.h"
# include "rules.h"

# define CHECKER "Checker"
# define PUSH_SWP "Push_swap"

void	print_stack(t_list *lst, char *mode);
void	print_args(char **args, char *mode);
void	print_op_dbg(char *op, char *mode);
void	print_rules(t_rule *rule, char *mode);

#endif

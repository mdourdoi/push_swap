/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:03:57 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 16:30:46 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "libft.h"
# include "rules.h"
# include "push_swap.h"
# include "ft_printf.h"

# define PRINT_ERROR 1
# define NO_ERROR 0

void	check_op(char *op, t_list **a, t_list **b);
void	panic_exit(t_list **a, t_list **b, char *op, int flag);
void	execute(char *op, t_list **a, t_list **b, t_rule *rules);

#endif

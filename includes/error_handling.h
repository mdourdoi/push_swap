/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:31:22 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/08 13:35:18 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "libft.h"

void	free_args(char **args);
void	panic_exit(t_list **a, t_list **b, char *op);
void	print_error(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:06:19 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 11:06:27 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Print error : 
//
//      This function print a string into stderror

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

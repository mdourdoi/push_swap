/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:54 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/28 16:20:17 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_errf.h"

int	ft_put_err_char(char arg)
{
	return (write(1, &arg, 1));
}

int	ft_put_err_str(char *arg)
{
	if (!arg)
		return (write(2, "(null)", 6));
	return (write(2, arg, ft_strlen(arg)));
}

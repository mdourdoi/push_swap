/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrs_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/11/28 16:08:07 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_errf.h"

int	ft_puterr_nb_u(unsigned int n, char *str_base, unsigned int base)
{
	unsigned int	div;
	unsigned int	mod;
	unsigned int	ret;

	div = n / base;
	mod = n % base;
	if (div == 0)
		return (write(2, &str_base[mod], 1));
	ret = ft_puterr_nb_u(div, str_base, base);
	write(2, &str_base[mod], 1);
	return (ret + 1);
}

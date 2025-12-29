/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_voidp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:36:37 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/01 13:03:52 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_errf.h"

static int	ft_putvoidp_err(uintptr_t vp, char *str_base, size_t base)
{
	uintptr_t	div;
	uintptr_t	mod;
	int			ret;

	div = (uintptr_t)vp / base;
	mod = (uintptr_t)vp % base;
	if (div == 0)
		return (write(2, &str_base[mod], 1));
	ret = ft_putvoidp_err(div, str_base, base);
	write(2, &str_base[mod], 1);
	return (ret + 1);
}

int	ft_voidperr_writer(void *vp)
{
	if (!vp)
		return (write(2, "(nil)", 5));
	write(2, "0x", 2);
	return (ft_putvoidp_err((uintptr_t)vp, "0123456789abcdef", 16) + 2);
}

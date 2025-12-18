
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:51:36 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_mel.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (c > 8 && c <= 13))
		return (1);
	return (0);
}

static int	check_sign(const char *nptr, int *sign, size_t *i)
{
	size_t	count;

	count = 0;
	while (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			*sign *= -1;
		if (count >= 1)
			return (0);
		count++;
	}
	*i += count;
	return (1);
}

int	ft_atoi(char *nptr)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]) == 1)
	{
		if (ft_isascii(nptr[i]) == 0)
			return (0);
		i++;
	}
	if (check_sign(&nptr[i], &sign, &i) == 0)
		return (0);
	while (ft_isdigit(nptr[i]) == 1)
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

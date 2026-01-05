/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:51:36 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/05 16:35:59 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rules.h"

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

t_bool	ft_atoi(char *nptr, int *value)
{
	size_t		i;
	long int	res;
	int			sign;

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
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			return (FALSE);
		i++;
	}
	*value = res * sign;
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:29:04 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/16 11:32:16 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_errf.h"

static int	ft_write_upto(const char *s, char endchar)
{
	int	ret;

	ret = ft_strlen_upto(s, endchar);
	write(2, s, ret);
	return (ret);
}

static int	ft_handler(char type, va_list args)
{
	if (type == 'c')
		return (ft_put_err_char(va_arg(args, int)));
	if (type == 's')
		return (ft_put_err_str(va_arg(args, char *)));
	if (type == 'p')
		return (ft_voidperr_writer(va_arg(args, void *)));
	if (type == '%')
		return (write(2, "%", 1));
	if (type == 'i' || type == 'd')
		return (ft_puterr_nb(va_arg(args, int), "0123456789", 10));
	if (type == 'u')
		return (ft_puterr_nb_u(va_arg(args, unsigned int), "0123456789", 10));
	if (type == 'x')
		return (ft_puterr_nb_u(va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (type == 'X')
		return (ft_puterr_nb_u(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	if (type == 'f')
		return (printerr_float(va_arg(args, double)));
	return (0);
}

int	print_errf(const char *s, ...)
{
	va_list	args;
	int		res;
	int		index;
	int		readed;

	if (!s)
		return (-1);
	va_start(args, s);
	index = 0;
	res = 0;
	readed = 0;
	while (s[index])
	{
		readed = ft_write_upto(&s[index], '%');
		res += readed;
		index += readed;
		if (!s[index] || !s[index + 1])
			break ;
		if (s[index + 1])
			res += ft_handler(s[index + 1], args);
		index += 2;
	}
	va_end(args);
	return (res);
}

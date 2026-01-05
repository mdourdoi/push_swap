/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:30:59 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 16:33:16 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERRF_H
# define PRINT_ERRF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define HEX_DICT "0123456789abcdef"
# define UHEX_DICT "0123456789abcdef"

size_t	ft_strlen_upto(char const *s, char end);
size_t	ft_strlen(const char *c);
int		ft_puterr_nb(int n, char *str_base, int base);
int		ft_puterr_nb_u(unsigned int n, char *str_base, unsigned int base);
int		ft_voidperr_writer(void *vp);
int		ft_put_err_char(char arg);
int		ft_put_err_str(char *arg);
int		printerr_float(float nbr);
int		print_errf(const char *s, ...);

#endif

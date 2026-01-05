/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harmonizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:26:27 by mdourdoi          #+#    #+#             */
/*   Updated: 2026/01/05 11:26:31 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Get_args_len : 

      This function will count the total of char + space needed for 
          the concatenation
*/

static size_t	get_args_len(char **argv)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = 0;
	while (argv[i])
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	return (i + len - 1);
}

/*
 ft_strcat : 

      because strlcat is shitty function
*/

static size_t	ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	len_dst;

	len_dst = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len_dst + i] = src[i];
		i++;
	}
	dest[len_dst + i] = '\0';
	return (len_dst + i);
}

/*
 Concatenate : 

      This will concatenate multiple strings into one string,
          each string will be separated by a space
*/

static void	concatenate(char **argv, char *str)
{
	size_t	total;
	size_t	i;

	i = 1;
	while (argv[i])
	{
		total = ft_strcat(str, argv[i]);
		str[total] = ' ';
		i++;
	}
}

/* Args_len : 
      return the number of args
*/

int	args_len(char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		return (0);
	while (args[i])
		i++;
	return (i + 1);
}

/* Harmonize_args : 

      The purpose of this function is to harmonize 
          the args given by the user so they can follow the same
          standard in every case during the parsing
*/

char	**harmonize_args(char **argv)
{
	size_t	len;
	char	*str;
	char	**res;

	len = get_args_len(argv);
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	concatenate(argv, str);
	res = ft_split(str, ' ');
	if (str != NULL)
		free(str);
	return (res);
}

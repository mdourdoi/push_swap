/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdourdoi <mdourdoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:59:55 by mdourdoi          #+#    #+#             */
/*   Updated: 2025/12/16 14:09:24 by mdourdoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mel.h"

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = ft_calloc(1, sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->index = -1;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:50:49 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/18 11:56:31 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "rules.h"
#include "libft_mel.h"
#include <stdio.h>

/*void	print_stack(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}*/

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	**b;
	t_rule	rule;

	a = parse_args(ac, av, &rule);
	printf("Init \n");
	print_stack(a);
	b = ft_calloc(1, sizeof(t_list *));
	ft_selectionsort(&a, b);
	printf("final: \n");
	print_stack(a);
	print_stack(*b);
}

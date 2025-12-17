/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:59:21 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/17 16:39:07 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rules.h"

void	test_parser(char **str, int ac)
{
	t_list	*lst;
	t_list	*tmp;
	t_rule	rule;
	size_t	i = 0;

	lst = parse_args(ac, str, &rule);	
	printf("\t\t--- argv --- \n");
	while (i < ac)
	{
		printf("%s\n", str[i]);
		i++;
	}
	printf("\t\t--- lst --- \n");
	tmp = lst;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("clearing stack...");
	lst = clear_stack(lst);
}

int	main()
{
	char *str[] = {"./a.out","1", "5", "2", "--adaptive"};
	test_parser(str, 5);
	return (0);
}

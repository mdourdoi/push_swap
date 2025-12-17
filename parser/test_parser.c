/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:59:21 by melschmi          #+#    #+#             */
/*   Updated: 2025/12/17 17:17:34 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rules.h"

void	test_parser(char **str, int ac, int test_nb)
{
	t_list	*lst;
	t_list	*tmp;
	t_rule	rule;
	size_t	i = 0;

	printf("\t\t --- Test %d ---\n", test_nb);
	lst = parse_args(ac, str, &rule);	
	if (lst == NULL)
	{
		printf("Error : \n");
		return ;
	}
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
	printf("mode = %d\n", rule.mode);
	printf("size = %lu\n", rule.nb_element);
	printf("clearing stack...\n");
	lst = clear_stack(lst);
}

int	main()
{
	char *str[] = {"./a.out","1", "5", "2", "--adaptive"};
	char *str2[] = {"./a.out","1", "5", "2"};
	char *str3[] = {"./a.out"};
	char *str4[] = {"./a.out", "a"};
	char *str5[] = {"./a.out","1", "5", "2" "2"};
	char *str6[] = {"./a.out","1", "5", "2a" "2"};
	char *str7[] = {"./a.out","1", "5", "2", "--simple"};
	char *str8[] = {"./a.out","1", "5", "2", "--complex"};
	char *str9[] = {"./a.out","1", "5", "2", "--medium"};
	char *str10[] = {"./a.out","1", "5", "2", "--error"};

	test_parser(str, 5, 1);
	test_parser(str2, 4, 2);
	test_parser(str3, 4, 3);
	test_parser(str4, 2, 4);
	test_parser(str5, 5, 5);
	test_parser(str6, 5, 6);
	test_parser(str7, 5, 7);
	test_parser(str8, 5, 8);
	test_parser(str9, 5, 9);
	test_parser(str10, 5, 10);

	return (0);
}

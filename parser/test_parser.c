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

void	print_stack(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}

void	test_parser(char **str, int ac, int test_nb)
{
	t_list	*lst;
	t_rule	rule;
	int		i = 0;

	printf("\t\t --- Test %d ---\n", test_nb);
	lst = parse_args(ac, str, &rule);			// This is the main function that will parse all the args and setup rules	
	if (lst == NULL)
	{
		printf("Error : \n");
		lst = clear_stack(lst);
		return ;
	}
	printf("\t\t--- argv --- \n");
	while (i < ac)
	{
		printf("%s\n", str[i]);
		i++;
	}
	printf("\t\t--- lst --- \n");
	print_stack(lst);

	printf("mode = %d\n", rule.mode);
	printf("size = %lu\n", rule.nb_element);
	printf("clearing stack...\n");
	lst = clear_stack(lst);
}

int	main()
{
	char *str[] = {"./a.out","1", "5", "2", "--adaptive"};
	char *str2[] = {"./a.out","1", "5", "2", "--simple"};
	char *str3[] = {"./a.out","1", "5", "2", "--complex"};
	char *str4[] = {"./a.out","1", "5", "2", "--medium"};
	char *str5[] = {"./a.out","1", "5", "2", "--error"};
	char *str6[] = {"./a.out","1", "5", "2"};
	char *str7[] = {"./a.out"};
	char *str8[] = {"./a.out", "a"};
	char *str9[] = {"./a.out","1", "5", "2", "2"};
	char *str10[] = {"./a.out","1", "5", "2a", "2"};
	char *str11[] = {NULL};

	test_parser(str, 5, 1);
	test_parser(str2, 5, 2);
	test_parser(str3, 5, 3);
	test_parser(str4, 5, 4);
	test_parser(str5, 5, 5);
	test_parser(str6, 4, 6);
	test_parser(str7, 1, 7);
	test_parser(str8, 2, 8);
	test_parser(str9, 5, 9);
	test_parser(str10, 5, 10);
	test_parser(str11, 0, 11);
	test_parser(str11, 1, 12);

	return (0);
}

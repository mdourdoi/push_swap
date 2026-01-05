#ifndef	ERROR_HANDLING
# define ERROR_HANDLING

void	free_args(char **args);
void	panic_exit(t_list **a, t_list **b, char *op);
void	print_error(char *str);

#endif

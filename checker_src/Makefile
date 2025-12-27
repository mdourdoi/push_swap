EXEC=../Test/checker
CC=cc
FLAGS=-Wall -Werror -Wextra
INCLUDES= ../includes

SRCS=	../libft_mel/ft_bzero.c \
		../libft_mel/ft_calloc.c \
		../libft_mel/ft_isascii.c \
		../libft_mel/ft_isdigit.c \
		../libft_mel/ft_lstadd_back.c \
		../libft_mel/ft_lstadd_front.c \
		../libft_mel/ft_lstlast.c \
		../libft_mel/ft_lstnew.c \
		../libft_mel/ft_memset.c \
		../libft_mel/ft_strlen.c \
		../libft_mel/ft_split.c \
		../parser/ft_atoi.c \
		../parser/ft_strcmp.c \
		../parser/parser.c \
		../parser/rules.c \
		../parser/rules_set.c \
		../parser/harmonizer.c \
		../primitives/push.c \
		../primitives/reverse_rotate.c \
		../primitives/rotate.c \
		../primitives/swap.c \
		../ft_printf/ft_printf.c \
		../ft_printf/ft_printf_chars.c \
		../ft_printf/ft_printf_nbrs.c \
		../ft_printf/ft_printf_nbrs_unsigned.c \
		../ft_printf/ft_printf_utils.c \
		../ft_printf/ft_printf_voidp.c \
		../ft_printf/float.c \
		../print_errf/print_errf.c \
		../print_errf/print_errf_chars.c \
		../print_errf/print_errf_nbrs.c \
		../print_errf/print_errf_nbrs_unsigned.c \
		../print_errf/print_errf_voidp.c \
		../print_errf/print_errfloat.c \
		../sorts/is_sorted.c \
		error.c \
		execution.c \
		execution_2.c \
		get_next_line.c \
	  	get_next_line_utils.c \
	  	checker.c 

OBJS=$(SRCS:.c=.o)
INCLUDES=../includes
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -g $(FLAGS) -I$(INCLUDES) -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(EXEC)

re: fclean
	make all

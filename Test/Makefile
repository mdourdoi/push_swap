EXEC=push_swap
TEST=test

INCLUDES=../includes/
FLAGS=-Wall -Wextra -Werror 

SRC_TEST=../parser/ft_strcmp.c \
	../parser/parser.c \
	../parser/rules.c \
	../parser/rules_set.c \
	../parser/ft_atoi.c \
	../parser/gateway.c \
	../parser/harmonizer.c \
	../primitives/push.c \
	../primitives/reverse_rotate.c \
	../primitives/rotate.c \
	../primitives/swap.c \
	../libft_mel/ft_bzero.c \
	../libft_mel/ft_calloc.c \
	../libft_mel/ft_isascii.c \
	../libft_mel/ft_isdigit.c \
	../libft_mel/ft_lstadd_back.c \
	../libft_mel/ft_lstnew.c \
	../libft_mel/ft_memset.c \
	../libft_mel/ft_strlen.c \
	../libft_mel/ft_split.c \
	../libft/ft_lstadd_front.c \
	../libft/ft_lstlast.c \
	../libft/ft_lstsize.c \
	../ft_printf/ft_printf_chars.c \
	../ft_printf/ft_printf_nbrs.c \
	../ft_printf/ft_printf_nbrs_unsigned.c \
	../ft_printf/ft_printf_voidp.c \
	../ft_printf/ft_printf_utils.c \
	../ft_printf/float.c \
	../ft_printf/ft_printf.c \
	../print_errf/print_errf_chars.c \
	../print_errf/print_errf_nbrs.c \
	../print_errf/print_errf_nbrs_unsigned.c \
	../print_errf/print_errf_voidp.c \
	../print_errf/print_errfloat.c \
	../print_errf/print_errf.c \
	../bench/bench.c \
	../sorts/scans.c \
	../sorts/utils.c \
	../sorts/set_index.c \
	../sorts/bucket_sort.c \
	../sorts/is_sorted.c \
	../sorts/selectionsort.c \
	../disorder.c \
		test.c

OBJ=$(SRC_TEST:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ) 
	$(CC) $(FLAGS) -I$(INCLUDES) $^ -o $@

$(TEST): $(OBJ)
	$(CC) -g $(FLAGS) -I$(INCLUDES) $^ -o $@

%.o: %.c
	$(CC) -g $(FLAGS) -I$(INCLUDES) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC) $(TEST)

re: fclean
	make all

retest: fclean
	make test

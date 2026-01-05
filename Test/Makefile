EXEC=push_swap
EXEC_TEST=push_swap_test
CHECKER=checker
CHECKER_TEST=checker_test

INCLUDES=../includes/
FLAGS=-Wall -Wextra -Werror -o3
FLAGS_TEST=-g -Wall -Wextra -Werror -D DEBUG_MODE_=1

DEBUG_SRC=../test_src/debug.c

SRCS_CHKR=../libft_mel/ft_bzero.c \
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
		../checker_src/error.c \
		../checker_src/execution.c \
		../checker_src/get_next_line.c \
	  	../checker_src/get_next_line_utils.c \
	  	../checker_src/checker.c

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
	../sorts/radix_sort.c \
	../sorts/is_sorted.c \
	../sorts/selectionsort.c \
	../disorder.c \
	test.c

OBJ=$(SRC_TEST:.c=.o)
OBJ_CHKR=$(SRCS_CHKR:.c=.o)
OBJ_DEBUG=$(DEBUG_SRC:.c=.o)

$(EXEC_TEST): FLAGS := $(FLAGS_TEST)
$(CHECKER_TEST): FLAGS := $(FLAGS_TEST)

all: $(EXEC) $(CHECKER)

test: $(EXEC_TEST) $(CHECKER_TEST)

$(CHECKER): $(OBJ_CHKR)
	$(CC) $(FLAGS) -I$(INCLUDES) $^ -o $@

$(CHECKER_TEST): $(OBJ_CHKR) $(OBJ_DEBUG)
	$(CC) $(FLAGS) -I$(INCLUDES) $^ -o $@

$(EXEC): $(OBJ) 
	$(CC) $(FLAGS) -I$(INCLUDES) $^ -o $@

$(EXEC_TEST): $(OBJ) $(OBJ_DEBUG)
	$(CC) $(FLAGS) -I$(INCLUDES) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

clean: 
	rm -rf $(OBJ) $(OBJ_CHKR) $(OBJ_DEBUG)

fclean: clean
	rm -rf $(EXEC) $(EXEC_TEST) $(CHECKER) $(CHECKER_TEST)

re: fclean
	make all

retest: fclean
	make test

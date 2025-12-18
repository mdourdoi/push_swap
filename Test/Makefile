EXEC=push_swap
TEST=test

INCLUDES=../includes/
FLAGS=-Wall -Wextra -Werror 

SRC_TEST=../parser/ft_strcmp.c \
	../parser/parser.c \
	../parser/rules.c \
	../primitives/push.c \
	../primitives/reverse_rotate.c \
	../primitives/rotate.c \
	../primitives/swap.c \
	../libft_mel/ft_atoi.c \
	../libft_mel/ft_bzero.c \
	../libft_mel/ft_calloc.c \
	../libft_mel/ft_isascii.c \
	../libft_mel/ft_isdigit.c \
	../libft_mel/ft_lstadd_back.c \
	../libft_mel/ft_lstnew.c \
	../libft_mel/ft_memset.c \
	../libft/ft_lstadd_front.c \
	../libft/ft_lstlast.c \
	../libft/ft_lstsize.c \
	../ft_printf/ft_printf_chars.c \
	../ft_printf/ft_printf_nbrs.c \
	../ft_printf/ft_printf_nbrs_unsigned.c \
	../ft_printf/ft_printf_voidp.c \
	../ft_printf/ft_printf_utils.c \
	../ft_printf/ft_printf.c \
	../sorts/is_sorted.c \
	../sorts/selectionsort.c \
	../gateway/gateway.c \
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

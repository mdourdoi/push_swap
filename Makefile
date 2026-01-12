EXEC=push_swap
CHECKER=checker

INCLUDES=includes/
FLAGS=-Wall -Wextra -Werror

LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a
LIBS=-L$(LIBFT_DIR) -lft
HEADER_LIBFT = includes/libft.h

SRCS_LIBFT = libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstlast.c \
	libft/ft_lstnew.c \
	libft/ft_lstsize.c\
	libft/ft_memset.c \
	libft/ft_split.c \
	libft/ft_strcmp.c \
	libft/ft_strlen.c \
	libft/ft_substr.c

SRCS_BONUS=parser/parser.c \
	parser/rules.c \
	parser/rules_set.c \
	parser/harmonizer.c \
	primitives/push.c \
	primitives/reverse_rotate.c \
	primitives/rotate.c \
	primitives/swap.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_chars.c \
	ft_printf/ft_printf_nbrs.c \
	ft_printf/ft_printf_nbrs_unsigned.c \
	ft_printf/ft_printf_utils.c \
	ft_printf/ft_printf_voidp.c \
	ft_printf/float.c \
	print_errf/print_errf.c \
	print_errf/print_errf_chars.c \
	print_errf/print_errf_nbrs.c \
	print_errf/print_errf_nbrs_unsigned.c \
	print_errf/print_errf_voidp.c \
	print_errf/print_errfloat.c \
	sorts/is_sorted.c \
	checker_src_bonus/error_bonus.c \
	checker_src_bonus/execution_bonus.c \
	checker_src_bonus/get_next_line_bonus.c \
	checker_src_bonus/get_next_line_utils_bonus.c \
	checker_src_bonus/checker_bonus.c

SRCS=parser/parser.c \
	parser/rules.c \
	parser/rules_set.c \
	parser/gateway.c \
	parser/harmonizer.c \
	primitives/push.c \
	primitives/reverse_rotate.c \
	primitives/rotate.c \
	primitives/swap.c \
	ft_printf/ft_printf_chars.c \
	ft_printf/ft_printf_nbrs.c \
	ft_printf/ft_printf_nbrs_unsigned.c \
	ft_printf/ft_printf_voidp.c \
	ft_printf/ft_printf_utils.c \
	ft_printf/float.c \
	ft_printf/ft_printf.c \
	print_errf/print_errf_chars.c \
	print_errf/print_errf_nbrs.c \
	print_errf/print_errf_nbrs_unsigned.c \
	print_errf/print_errf_voidp.c \
	print_errf/print_errfloat.c \
	print_errf/print_errf.c \
	bench/bench.c \
	sorts/scans.c \
	sorts/utils.c \
	sorts/set_index.c \
	sorts/bucket_sort.c \
	sorts/radix_sort.c \
	sorts/is_sorted.c \
	sorts/selectionsort.c \
	error_handling/error.c \
	main.c

OBJ_DIR=.obj
OBJ=$(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS=$(SRCS_BONUS:%.c=$(OBJ_DIR)/%.o)

all: $(EXEC)

bonus: $(CHECKER)

$(LIBFT): $(HEADER_LIBFT) $(SRCS_LIBFT)
	$(MAKE) -C $(LIBFT_DIR)

$(EXEC): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) -I$(INCLUDES) $(OBJ) $(LIBS) -o $@

$(CHECKER): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(FLAGS) -I$(INCLUDES) $(OBJ_BONUS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

clean: 
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(EXEC) $(CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	make all
recheck: fclean
	make all
	make checker

.PHONY : all bonus clean fclean re recheck

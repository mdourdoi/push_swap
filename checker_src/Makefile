EXEC=../Test/checker
CC=cc
FLAGS=-Wall -Werror -Wextra
INCLUDES= ../includes

SRCS=	ft_bzero.c \
		ft_calloc.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_lstadd_back.c \
		ft_lstnew.c \
		ft_memset.c \
		../parser/ft_atoi.c \
		../parser/ft_strcmp.c \
		../parser/parser.c \
		../parser/rules.c \
		../parser/rules_set.c \
		../primitives/push.c \
		../primitives/reverse_rotate.c \
		../primitives/rotate.c \
		../primitives/swap.c \
		get_next_line.c \
	  	get_next_line_utils.c \
	  	checker.c 

OBJS=$(SRCS:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -g $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(EXEC)

re: fclean
	make all

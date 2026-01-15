CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes
AR = ar rcs
RM = rm -f

NAME = libft.a
HEADERS = ../includes/libft.h

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c\
	ft_memset.c \
	ft_split.c \
	ft_strcmp.c \
	ft_strlen.c \
	ft_substr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

EXEC=../Test/checker
CC=cc
FLAGS=-Wall -Werror -Wextra

SRCS= get_next_line.c \
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

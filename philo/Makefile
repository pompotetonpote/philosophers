CC			= gcc -g -pthread
CFLAGS		= -Werror -Wall -Wextra -fsanitize=thread #-fsanitize=address -fsanitize=thread 
NAME		= philo

SRC_PATH 	= src/
OBJ_PATH 	= obj/

SRC			= main.c \
			  check_args_errors.c \
			  init_philos_table.c \
			  linked_list_utils.c \
			  threads.c \
			  routine.c \
			  errors.c \
			  utils.c \

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS)  -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
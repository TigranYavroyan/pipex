NAME = pipex
SRCSPATH = ./srcs/
LIBFTPATH = ./libft/
INCPATH = ./includes/ ./libft/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(SRCSPATH)%.o,$(SRCS))
LIBFT = $(LIBFTPATH)*.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -c $(foreach H,$(INCPATH),-I$(H))
#
all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) -fsanitize=address -g $(LIBFT) $(OBJS) -o $(NAME)
#
$(LIBFT) :
	make -C $(LIBFTPATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) $< -o $@
#
clean :
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

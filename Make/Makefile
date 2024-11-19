SRCS= get_next_line.c get_next_line_utils.c 
OBJS = $(SRCS:.c=.o)

BONUS= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS_BONUS = $(BONUS:.c=.o)

CC= clang
RM= rm -f
CFLAGS= -Wall -Wextra -Werror -I.



clean : 
		$(RM) $(OBJS)$(BONUS_OBJS)

fclean : clean

re :fclean

bonus : $(OBJS) $(OBJS_BONUS)

.PHONY:	all clean fclean re

NAME    = libftprintf.a
CC = gcc
INC = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
RM = rm -rf

SRCS    = ft_printf.c	\
		  srcs/ft_printf_utils.c	\
		  srcs/ft_put_nbr_Xbase.c	\
		  srcs/ft_put_pointr.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar $(ARFLAGS) $(NAME) $(OBJS)
	@echo "and ... Magic :D"

%.o: %.c $(INC)
	@echo "Complining: $<"
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

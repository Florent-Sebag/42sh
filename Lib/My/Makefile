##
## Makefile for  in /home/victor/rendu/Première année/Sys_Unix/PSU_2015_my_printf_bootstrap
##
## Made by Victor
## Login   <marito_v@epitech.net>
##
## Started on  Tue Nov  3 15:23:17 2015 Victor
## Last update Tue Apr 12 19:01:51 2016 Victor
##

SRCS	=	isnum.c \
		nb_lines.c \
		my_strcmp.c \
		my_putstr.c \
		my_puterr.c \
		my_strlen.c \
		my_getnbr.c \
		my_printf.c \
		my_strdup.c \
		my_strcpy.c \
		my_memset.c \
		my_put_nbr.c \
		my_putchar.c \
		my_strncmp.c \
		my_putstr_s.c \
		my_putstr_S.c \
		my_putchar_v.c \
		my_put_nbr_o.c \
		my_put_nbr_b.c \
		my_put_nbr_u.c \
		my_put_nbr_x.c \
		my_put_nbr_p.c \
		my_put_nbr_X.c \
		my_putnbr_base.c \
		my_putnbr_base_o.c \
		my_putnbr_base_p.c \
		my_str_to_wordtab.c

CC	=	gcc

NAME	=	libmy.a

CFLAGS	=	-W -Wall -Wextra -Werror -I./

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

AR	=	ar rc

RANLIB	=	ranlib

CP	=	cp

RED	=       \033[1;31m

WHITE	=       \033[0m

GREEN	=       \033[1;32m

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	@echo "\t\t$(GREEN)Compilation de la lib terminée$(WHITE)\n"
	$(CP) libmy.a ../
clean:
	$(RM) $(OBJS)
	@echo "\t\t$(GREEN)Clean de la lib terminé$(WHITE)\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\t\t$(RED)Attention .a effacé$(WHITE)\n"

re: fclean all

.PHONY: all clean fclean re

##
## Makefile for  in
##
## Made by Victor Mariton
## Login   <marito_v@epitech.net>
##
## Started on  Wed Nov 18 10:23:20 2015 Victor Mariton
## Last update Sun Jun  5 18:53:21 2016 Victor
##

SRCS	=	main.c \
			./Sources/main_loop.c \
			./Sources/Misc/epur.c \
			./Sources/main_func.c \
			./Sources/Listes/elem.c \
			./Sources/Misc/cpy_tab.c \
			./Sources/Alias/replace.c \
			./Sources/Builtins/echo.c \
			./Sources/Misc/my_malloc.c \
			./Sources/Misc/list_func.c \
			./Sources/Execution/path.c \
			./Sources/Misc/my_wordtab.c \
			./Sources/Alias/del_alias.c \
			./Sources/Misc/my_getchar.c \
			./Sources/Listes/list_func.c \
			./Sources/Builtins/cd_func.c \
			./Sources/Listes/list_init.c \
			./Sources/Alias/make_alias.c \
			./Sources/Misc/my_reallcpy.c \
			./Sources/Listes/list_fault.c \
			./Sources/Globbing/globbing.c \
			./Sources/Execution/my_pipe.c \
			./Sources/Builtins/exit_func.c \
			./Sources/Builtins/print_env.c \
			./Sources/Listes/list_delete.c \
			./Sources/Listes/list_insert.c \
			./Sources/Alias/load_file_rc.c \
			./Sources/Builtins/variables.c \
			./Sources/Misc/get_next_line.c \
			./Sources/Misc/get_first_word.c \
			./Sources/Misc/my_concat_path.c \
			./Sources/BinaryTree/ope_func.c \
			./Sources/Alias/type_of_alias.c \
			./Sources/Misc/call_gnl_to_end.c \
			./Sources/BinaryTree/error_ope.c \
			./Sources/Builtins/setenv_func.c \
			./Sources/Builtins/all_flag_echo.c \
			./Sources/EnvManagement/list_tab.c \
			./Sources/Builtins/unsetenv_func.c \
			./Sources/Builtins/check_builtin.c \
			./Sources/BinaryTree/binary_tree.c \
			./Sources/Execution/my_minishell.c \
			./Sources/EnvManagement/get_path.c \
			./Sources/Misc/my_str_to_wordtab.c \
			./Sources/Execution/binary_execution.c \
			./Sources/EnvManagement/create_my_env.c \
			./Sources/Builtins/all_flag_echo_part.c \
			./Sources/Execution/binary_execution_extend.c \

NAME	=	42sh

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -I./Include

FLAGS	= -L./Lib -lmy

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

WHITE	= 	\033[0m

RED	= 	\033[1;31m

GREEN	= 	\033[1;32m

CYAN	= 	\033[1;36m

YELLOW	= 	\033[33;01m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)
	make -C ./Lib/My
	@echo "\t\t\t$(GREEN)\"Compilation finie\"\n$(WHITE)"

clean:
	make clean -C ./Lib/My
	$(RM) $(OBJS)
	@echo "\t\t\t$(GREEN)\"Clean fini\"\n$(WHITE)"

fclean: clean
	make fclean -C ./Lib/My
	$(RM) $(NAME)
	@echo "\t\t\t$(GREEN)\"Fclean fini\"\n$(WHITE)"

re: fclean all

.PHONY: all clean fclean re

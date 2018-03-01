/*
** my.h for PSU_2015_42sh in /home/victor/Rendu/Sys_Unix/PSU_2015_42sh/Include
**
** Made by Victor
** Login   <victor@epitech.net>
**
** Started on  Fri Jun 03 17:05:50 2016 Victor
** Last update Sun Jun 05 18:52:24 2016 Victor
*/

#ifndef MY_H_
# define MY_H_

/* ---------------------------------------------------------------------- *\
**                                INCLUDES                                **
\* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "list.h"
#include "my_lib.h"
#include "get_next_line.h"

/* ---------------------------------------------------------------------- *\
**                                DEFINES                                 **
\* ---------------------------------------------------------------------- */

	/* ---------- | MACROS VALUES | ----------*/

# define	EXIT_ON_FAILURE		-1
# define	ALIAS			42
# define	BUFF_SIZE		4096
# define 	UNUSED(x)		(void)(x)
# define	NORME			(str = strdup(((t_alias *)tmp->_data)->new))

	/* ---------- | MACROS MSG ERR | ----------*/

# define	USAGE		("Usage : ./42sh")
# define	ERR		("Something went wrong...")

	/* ---------- | MACROS FUNC | ----------*/

# define	LEN		strlen
# define	CMP		strcmp
# define	NCMP		strncmp
# define	USER		(&g_env.env[get_user_var(g_env.env)][5])

/* ---------------------------------------------------------------------- *\
**                               STRUCTURES                               **
\* ---------------------------------------------------------------------- */

	/* ---------- | STRUCTURE LISTE CHAINEE | ----------*/

typedef struct		s_list_env
{
  char			*str;
  struct s_list_env	*next;
}			t_list_env;

	/* ---------- | STRUCTURE ARBRE BIN  | ----------*/

typedef struct		s_bin
{
  bool			type;
  char			*instruc;
  struct s_bin		*right;
  struct s_bin		*left;
}			t_bin;

	/* ---------- | STRUCTURE CTRL C  | ----------*/

typedef struct		s_sig
{
  char			**env;
  int			compt;
}			t_sig;

	/* ---------- | STRUCTURE VAR TO KEEP | ----------*/

typedef struct		s_var
{
  char			**tab_path;
  char			*home;
  char			*oldpwd;
}			t_var;

	/* ---------- | STRUCTURE TAB OPE | ----------*/

typedef struct		s_op
{
  char			*str;
  int			nb_car;
  int			prior;
}			t_op;

	/* ---------- | STRUCTURE TAB OPE | ----------*/

typedef struct		s_alias
{
  char			*old;
  char			*new;
}			t_alias;

	/* ----------  | STRUCTURE HISTORIQUE | ----------*/

typedef	struct		s_histo
{
  struct s_histo	*prev;
  char			*str;
  int			indic;
  char			*hour;
  struct s_histo	*next;
}			t_histo;

typedef	struct		s_index
{
  t_histo		*first;
  t_histo		*last;
  int			size;
}			t_index;

	/* ---------- | STRUCTURE PRINCIPALE | ----------*/

typedef struct		s_data
{
  int			fork;
  int			exec_return;
  pid_t			process_pid;
  char			**env;
  t_list_env		*list_env;
  t_list		*list_alias;
  t_index		*list_histo;
  t_list		*alias;
  char			**cmd;
  t_bin			*tree;
  t_var			reserve;
}			t_data;

	/* ---------- | PTR (*FUNC) BUILTINS | ----------*/

typedef struct		s_builtin
{
  char			*str;
  int			(*func)(t_data *, char **);
}			t_builtin;

	/* ---------- | PTR (*FUNC) TOKENS | ----------*/

typedef	struct		s_token
{
  void			(*ptr)(t_bin *, t_data *);
  char			*flags;
}			t_token;

	/* ---------- | PTR (*FUNC) ECHO | ----------*/

typedef	struct		s_flags
{
  char			flag;
  void			(*func)();
}			t_flags;


/* ---------------------------------------------------------------------- * \
**                           VARIABLES GOBALES                            **
\* ---------------------------------------------------------------------- */

	/* ---------- | CTRL C | ----------*/

t_sig			g_env;

	/* ---------- | PTR (*FUNC) | ----------*/

extern t_sig		g_env;
extern int		g_ret;
extern t_builtin	tab_builtin[];


/* ---------------------------------------------------------------------- *\
**                               PROTOTYPES                               **
\* ---------------------------------------------------------------------- */

size_t		size_list(t_list_env *);

int		words(char *);
int		my_power(int);
int		my_intlen(int);
int		get_type(char *);
int		my_isnegative(int);
int		check_path(char **);
int		get_user_var(char **);
int		cd_func(t_data *, char **);
int		echo_cmd(t_data *, char **);
int		exit_func(t_data *, char **);
int		del_alias(t_data *, char **);
int		make_alias(t_data *, char **);
int		setenv_func(t_data *, char **);
int		check_builtin(t_data *, char *);
int		check_error_ope(t_bin *, int *);
int		load_our_file(t_data *, char **);
int		pos_prio_operator(char *, int *);
int		unsetenv_func(t_data *, char **);
int		regroup_function(t_data *dt, char *str);
int		compare_variables(char *str, char *tmp);
int		set_list_from_tab(t_list_env **, char **);
int		execute_execve(t_data *dt, char *path, char **cmd);
int		my_minishell(t_data *dt, char *path, char **cmd, int status);

void		main_loop(char **);
void		print_env(char **);
void		print_list(t_list_env *);
void		add_export_to_env(t_data *);
void		main_func(t_data *, char *);
void		action_tree(t_data *, t_bin *);
void		my_pipe(t_bin *tree, t_data *dt);
void		my_redirect(t_bin *tree, t_data *dt);
void		my_double_indirect_extend(int nopen);
void		my_indirect(t_bin *tree, t_data *dt);
void		my_double_or(t_bin *tree, t_data *dt);
void		my_semicolon(t_bin *tree, t_data *dt);
void		execute_token(t_bin *tree, t_data *dt);
void		my_double_and(t_bin *tree, t_data *dt);
void		my_double_indirect(t_bin *tree, t_data *dt);
void		my_double_redirect(t_bin *tree, t_data *dt);
void		my_pipe_extend(t_bin *tree, t_data *dt, int fd[2]);
void		my_minishell_extend(char *path, char **env, char **cmd);
void		between_pipe(t_bin *tree, t_data *dt, int fd[2], int status);

void		*my_malloc(size_t);
void		*delete_type_alias(void *);
void		*delete_type_export(void *);

char		*my_getchar(int);
char    	*epur_str(char *);
char		*get_next_line(int);
char		*first_word(char *);
char		*my_charcat(char *, char);
char		*get_ope(char *, int, int);
char		*my_reallcpy(char *, char *);
char		*replace_string(t_data *, char *);
char		*my_concat_path(char *tmp, char *cat);
char		*get_full_cmd(char *env, char *str, int i);
char		*change_variables(char *str, char **env, int i);
char		*my_process_pid(char *str, int s, int e, pid_t pid);

char		**create_my_env();
char		**get_path(char **);
char		**globbing(char **);
char		**copy_env(char **);
char		**add_line(char **, char *);
char		**cpy_tab(char **, char **);
char		**set_tab_from_list(t_data *);
char		**have_good_tab(char *, char **);
char		**my_wordtab(char *, char, bool);
char		**my_str_to_wordtab(char *, char);
char		**get_path_cmd(char **path, char *str);
char		**variables_env(t_data *dt, char **tab);

t_list_env	*add_elem_list(t_list_env *,char *);

t_bin		*create_tree(char *, int *);

void		t_flag();
void		v_flag();
void		a_flag();
void		b_flag();
void		f_flag();
void		n_flag();
void		r_flag();
void		print_letter(char);

int		check_excla(char *);
int		len_w_excla(char *);
int		check_excla(char *);
int		check_nb_or_str(char *);
int		find_letter(char *, int);
int		check_backslash(int, char *);
int		test_str_hist(char *, char *);
int		test_str_hist(char *, char *);
int		history_cmd(t_data *, char **);
int		add_case_end(t_index *, char *);
int		create_list_str(t_index *, char *);
int		check_if_excla(int, char **, t_index *, int);

char		*get_time();
char		*tab_to_str(char **);
char		*double_excla(t_index *);
char		*compact(char *, char *);
char		*find_and_rm_excla(char *);
char		*use_excla(t_index *, char);
char		*excla(char *, t_index *, int);
char		*my_historic(char *, t_index *, int);
char		*find_str_in_histo(char *, t_index *);

void		rm_to_tab(char **, int);

t_index		*init_list_str();

#endif /* !MY_H_ */

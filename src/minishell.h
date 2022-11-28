/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:59:34 by kcetin            #+#    #+#             */
/*   Updated: 2022/11/28 13:59:35 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/inc/libft.h"
# include "../inc/colors.h"
# include "../inc/get_next_line.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_prompt
{
	t_list	*cmds;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_mini;

enum	e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13,
	RED_NOT = 14,
	EXP_FAI = 15,
	NEW_ERR = 16
};

char	*mini_readline(t_prompt *prompt, char *str);

void	*mini_here_fd(int fd[2]);

int		builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n);

int		is_builtin(t_mini *n);

int		mini_cd(t_prompt *prompt);

void	cd_error(char **str[2]);

int		mini_pwd(void);

int		mini_echo(t_list *cmd);

int		mini_export(t_prompt *prompt);

int		mini_unset(t_prompt *prompt);

char	*ft_process(char *arg);

int		mini_exit(t_list *cmd, int *is_exit);

void	*check_args(char *out, t_prompt *p);

char	**ft_cmdtrim(char const *s, char *set);

char	**ft_cmdsubsplit(char const *s, char *set);

char	*ft_strtrim_all(char const *s1, int squote, int dquote);
void	single_control(char **a[2]);
t_list	*fill_nodes(char **args, int i);

int		get_fd(int oldfd, char *path, int flags[2]);

t_mini	*get_outfile1(t_mini *node, char **args, int *i);

t_mini	*get_outfile2(t_mini *node, char **args, int *i);
void	get_params_control(char **a[2], int *i);

t_mini	*get_infile1(t_mini *node, char **args, int *i);

t_mini	*get_infile2(t_mini *node, char **args, int *i);

void	*exec_cmd(t_prompt *prompt, t_list *cmd);

void	*check_to_fork(t_prompt *prompt, t_list *cmd, int fd[2]);

void	child_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd);

void	exec_custom(char ***out, char *full, char *args, char **envp);

int		exec_builtin(t_prompt *prompt, int (*func)(t_prompt *));

void	get_cmd(t_prompt *prompt, t_list *start, char **split_path, char *path);

char	*expand_vars(char *str, int i, int quotes[2], t_prompt *prompt);

char	*expand_path(char *str, int i, int quotes[2], char *var);

int		get_here_doc(char *str[2], char *aux[2]);

void	*mini_perror(int err_type, char *param, int err);

char	*mini_getenv(char	*var, char **envp, int n);

char	**mini_setenv(char *var, char *value, char **envp, int n);

char	*mini_getprompt(t_prompt prompt);

void	free_content(void *content);
void	*ft_free_matrix2(char ***m);

void	handle_sigint(int sig);

void	handle_sigint_child(int sig);
int		var_in_envp(char *argv, char **envp, int i[2]);
int		w_export(t_prompt *e);
void	help_export(int j, t_prompt *prompt);
int		check_args2(char **lst);
void	fill_nodehelp(char ***hello, char ***hello2);

#endif

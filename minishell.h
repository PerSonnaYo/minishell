#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include "./libft/libft.h"
# include <string.h>
# include <dirent.h>
# include "error_m.h"
# include "termi.h"

# define BUFFER_SIZE 2
# define NUM__BUIL_PIP 4
# define NUM__BUIL 4
# define PIP__BUIL 7
# define REAL 1024

typedef struct s_line
{
	char	*line;
	int		i;
	int		y;
}				t_line;

typedef struct s_fd
{
	int			nbr;
	struct s_fd	*next;
}					t_fd;

typedef struct s_build
{
	char			**str;
	char			**env;
	int				nbr;
	t_fd			*fdl;
	char			*doubl_red;
	struct s_build	*next;
	int				fd[2];
}					t_buld;

typedef struct s_wil
{
	char	*ju;
	char	*tmp;
	char	**buf;
	char	*pap;
	int		num;
	int		index;
	int		str;
	int		loop;
}			t_wil;

typedef struct s_ij
{
	int	i;
	int	j;
}					t_ij;

typedef int (* t_func)(t_buld *);

char	*ft_strjoin1(char const *s1, char const *s2);
int		init(char **rt, int fd);
int		get_next_line(int fd, char **line);
int		gotto(char *bufi);
int		troko(char **line, char **rt, long count, int fd);
char	*ft_substr1(char *s, unsigned long start, size_t len);
void	ft_freetab(char **array);
char	*dollar(char *str, char **env);
t_line	first_word(char *str, char **env);
int		lun_cdd(t_buld *gen);
int		lun_ech(t_buld *gen);
int		lun_env(t_buld *gen);
int		lun_exi(t_buld *gen);
int		lun_pwd(t_buld *gen);
int		lun_uns(t_buld *gen);
int		env_size(char **env);
char	**ft_realloc_pars(char **str);
void	mister_way(t_buld *gen);
t_line	gnl2(char **str);
char	*get_key(char *arg);
char	*set_value(char *arg, char *value, char **env);
void	sort(t_buld *arg);
void	newadd(t_buld *gen, char *str);
int		is_spec(char c);
void	pars_dollar(char *str, char **env, t_ij *ij, char **res);
int		is_space(char c);
char	*get_value(char *arg);
int		mister_popen(t_buld *gen);
int		lun_prexp(t_buld *gen);
int		lun_adexp(t_buld *gen);
int		parser_kov2(char **gen, char *str, int i, char **env);
int		parser_kov(char **gen, char *str, int i);
int		parser_alpha(char **gen, char *str, int i, char **env);
int		parser_redic(char *str, char **envy, t_fd **fdl);
int		parser_redicre(char *str, char **envy, int *pp);
int		freemas1(char **res, int j);
t_line	gnl3(char **str);
void	signalq1(int signum);
void	signalc(int signal);
void	mister_popen_pipes(t_buld *gen);
void	redicor(t_fd *fdl);
void	close_fd(t_fd *fdl);
int		mister_exit(t_buld *gen);
int		mister_exit1(t_line io, t_buld *gen);
int		ret_int(t_line *io, t_buld *gen);
int		mister_command_pip(t_buld *gen);
int		lun_exp(t_buld *gen);
void	free_fd(t_fd **elem);
void	siga_handle(void);
int		parser_widcard(char **gen, char *str, int i, char **env);
int		parcer_doll(char **tmp, char *str, int i, char **envy);
int		parser_simple(char **tmp, char *str, int i);
int		getKeys_fold(char *gen, int u, char *pap);
int		getKeys(char *gen, int u);
int		getKeys_post(char *gen, int u, char *pap);
void	maro(int qq, char *tmp);
int		getKeys_mid(char *gen, int u, char *pap, char *tmp);
int		getKeys_last(char *gen, int u, char *pap);
void	maro1(int qq, char *tmp);
int		getKeys_start(char *gen, int u, char *pap);
int		getKeys_norm(char *gen, int u, char *pap);
int		getKeys_cmp(char *gen, int u, char *pap);
int		getKeys_post1(char *gen, int u, char *pap, char *tmp);
void	maro2(int qq, char *tmp);
int		getKeys_sw(char *gen, int u, char *pap, char *tmp);
int		getKeys_fold1(char *gen, int u, char *pap);
void	ft_freetab1(char **array);
int		mister_loop(char *line, char **env);
int		ft_fopenre(char *s, int l);
char	*ret_word(char *str, char **env);
int		num_space(char *str);
int		fun_realloc(int malo, char ***gen);
char	**ft_realloc_ok(char **str, int *malo);
void	sighnd(int signum);
void	init_mas(void);
int		papka(char *gen);
void	last_wilcard(t_wil *wil);
void	last_wil0(t_wil *wil);
void	last_wil1(t_wil *wil);
void	last_wil2(t_wil *wil);
void	last_wil4(t_wil *wil, char *str, int i);
void	last_wil8(t_wil *wil);
void	last_wil9(t_wil *wil);
void	wil_buf(t_wil *wil, char *str, int i);
int		final_wilcard(int i, int il, int *g, char **gen);
char	*getccc(void);
int		keys_handler(int u, int *malo, char *gett);
int		first_wilcard(char *gen, t_wil *wil);
int		*init_num(int (*t)[2]);
int		keys_handler1(int u, int *malo, char *gett, char *buf);
void	keys_handler2(char *gett, int u);
char	*catch_value(t_buld *gen, char *str);
void	ch_pwd(t_buld *gen, char *new_pwd);
void	ch_old(t_buld *gen, char *old_pwd);
int		is_key(t_buld *gen);
int		change_null(int i, t_buld *gen);
int		ft_lstsize2(t_fd *lst);
int		ft_lstsize1(t_buld *lst);
void	redic_pip(t_fd *fdl);
void	redicor_pip(t_fd *fdl, int fd);
int		ft_re_output(t_fd *fds);
void	redic_pip_double(t_buld *gen);
void	redicor(t_fd *fdl);
void	free_fd(t_fd **elem);
void	close_fd(t_fd *fdl);
void	ft_lstadd_front4(t_fd **lst, t_fd *new);
t_fd	*ft_lstlast2(t_fd *lst);
void	link_fd(t_fd **obj, int fd);
int		slash(char *str, int i, char **gen);
int		parser_alpha1(char **gen, char *str, int i, char **env);
void	redic_bul(t_buld *gen);
void	free_elem(t_buld **elem);
t_buld	*ft_lstlast1(t_buld *lst);
void	ft_lstadd_front3(t_buld **lst, t_buld *new);
void	mister_link(t_buld **obj, char **env, char **str, t_fd **fdl);
void	add_envd(char *str, char **env);
void	parser_help(char **gen, t_wil *wil);
void	parser_help1(char **gen, t_wil *wil, char *str, char **envy);
void	doll_slas(t_wil *wil, char **gen, char **envy);
int		gnl4(char *str);
int		check_err(t_line *res, char **str);
int		check_err2(char **str, int i, t_line *res);
int		change_str(char **str, int i, t_line *res);
void	gnl_slush(char **str, t_line *res, int *i, int *j);
void	gnl_dol(char **str, t_line *res, int *i, int *j);
int		mister_parser(t_buld **obj, char **envy, char *str, t_fd **fdl);
void	loop_continue1(t_line *str, char **envn, t_buld *gen, t_fd *fdl);
void	ret_i(char *str, int *i);
void	vopros(char **res, t_ij *ij);
int		ft_realloc_ok1(int malo);
void	ft_freetab2(char **array);
void	*ft_realloc_pars1(char **buf, char **str);
void	signalq(int signum);
void	close_pipe_fd(t_buld *gen);
void	handle_pipe_result(t_buld *gen);
void	fork_pipe(t_buld *gen);
void	pipe_fd(t_buld *gen);
int		inc_wil(char *str);
int		dop_wil1(t_wil *wil);
void	past_wil1(t_wil *wil, char *gen, int last, int num);
void	dop_wil2(t_wil *wil, char *gen, int last);
int		gen_init(char **gen, char **envy, char *str, t_fd **fdl);
int		star(char *str);
void	in_star(char **s1, char **gen, char *str, char **envy);
void	redic_pars1(char **gen, char **envy, char *str, t_wil *wil);
void	loci_wil(t_wil *wil);
void	loci_wil1(t_wil *wil);
void	init_fdl_gen(t_buld **gen, t_fd **fdl);
int		perro(char *str);
int		cyc(char *str, int *i);
int		bolshe(char *str, int *i);
int		menshe(char *str, int *i);
int		token(char *str, int *i);
void	free_s1(char **gen);
void	free_all(char **temp, char **temp3, char **temp4);
int		ret_met(t_wil *wil, char *str, char **envy, t_fd **fdl);
int		ret_y(char **s1);
int		gmini_slash(int i, char *str, char **gen);
int		gmini_dol(int i, char *str, char **gen, char **env);
int		gmini_kov2(int i, char *str, char **gen, char **env);
int		gmini_kov(int i, char *str, char **gen);

#endif
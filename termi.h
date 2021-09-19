#ifndef TERMI_H
# define TERMI_H

# include <term.h>
# include <termios.h>
# include <curses.h>

# define PROMT "morti$ "

typedef struct s_term
{
	int		len;
	int		col;
	int		end;
	int		tmp;
	char	*temp;
}				t_term;

typedef struct s_glo {
	int				qua;
	int				fdu;
	pid_t			pid;
	int				sl;
	int				p;
	char			*doub_red;
	char			**wid;
	char			**post;
	int				i;
	struct termios	BACKUP_TTY;
	t_term			ter;
	int				pars_wil[3];
	char			*cvd;
	int				pipe;
	int				index;
	int				fd;
}			t_glo;

extern t_glo	g_mini;

int		new_tty (int fd);
int		ft_putint(int c);
void	get_cursor_position(int *col, int *rows);
int		restore_tty (int fd);
char	*dell(char *str, int col);
char	*beg(char *str, int col);
void	k_left(t_term *tter);
void	k_right(t_term *tter);
void	k_up(char **history, int *j);
void	k_down(char **history, int *j);
void	del(void);
void	del_hist(char **history, int j);
void	home(void);
void	end(void);
void	p_down(void);
void	p_up(void);
void	escape(char **history, int *j, int index);
void	ctrl_d(void);
void	ctrl_dh(char **history, int j);
void	backspace(void);
void	backspace_hist(char **history, int j);
void	insert(char *ost);
void	printchar(char c);
void	insert_hist(char *host, char **history, int j);
void	printchar_hist(char c, char **history, int j);
void	fill_hist(int file, char **history);
void	init_gmini(void);
void	check_terminal(void);
void	close_file(char **history, int j, int file, char **line);
void	fin_ctrl(char **history, int j);
void	fin_backspace(char **history, int j);
int		err_read(void);
int		cycle_main(char **history, int *j);
void	fin_del(char **history, int j);
int		mister_terminate(char **line, int fork);
void	check_lines(void);
void	last_l(int *ppp, char *ost);

#endif
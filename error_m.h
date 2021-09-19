#ifndef ERROR_M_H
# define ERROR_M_H

# define OP_CR "morti$: cannot create "
# define OP_RE "morti$: cannot read "
# define EX_NU ": numeric argument required\n"
# define EX_TO "exit: too many arguments\n"
# define CO_DF "': No such file or directory\n"
# define SY_CO "syntax error near unexpected token `;;'\n"
# define SY_PI "syntax error near unexpected token `|'\n"
# define SY_TO "syntax error near unexpected token `"
# define CO_DI ": is a directory\n"
# define PE_DI ": Permission denied\n"
# define CO_NF ": command not found\n"
# define EX_NV "': not a valid identifier\n"
# define SI_CC "Could not set SIGINT handler\n"
# define SI_LL "Could not set SIGQUIT handler\n"
# define HO_SE ": HOME not set\n"

void	print_error(char *er, char *s, char *t);

#endif
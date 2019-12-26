#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "asm_op.h"
# include "../ft_printf/ft_printf.h"

# define NAME 1
# define print_error ft_putendl("----------------HEWSTON, A PROBLEM UP HERE!!!----------------");
# define print_program_start ft_putendl("----------------PROGRAM STARTS HERE!!!----------------");
void	error(char *error, int line);

typedef struct			s_command
{
	int					type;
	char				*arg[3];
	struct s_command	*next;
	char				*label;
}						t_command;

/* typedef struct			s_matrice
{
	
};
 */
typedef struct			s_labels
{
	char				*label;
	struct s_labels		*next;
}						t_labels;


typedef struct			s_parse
{
	int					line_num;
	char				*name;
	char				*comment;
	t_command			*list_cmd;
	t_labels			*labels;
	int					error;
}						t_parse;

void	parse(char *file, t_parse *champ);
void	command_search(char *line, t_parse *champ, char *label);
void	label_search(char *line, t_parse *champ, int fd);
char	*skip_whitespace(char *line);
void	label_processing(char *line, int fd, t_parse *champ);
int		is_label(char *line);
char	*cut_label(char *str);

#endif

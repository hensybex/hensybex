#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "asm_op.h"
# include "../ft_printf/ft_printf.h"

# define NAME 1
# define print_error ft_putendl("----------------HEWSTON, A PROBLEM UP HERE!!!----------------");
# define print_program_start ft_putendl("------------------------------------------------------Program starts here------------------------------------------------------");
# define print_program_end ft_putendl("------------------------------------------------------Program ends here------------------------------------------------------");
void	error(char *error, int line);

typedef struct			s_labels
{
	char				*label;
	struct s_labels		*next;
}						t_labels;

typedef struct			s_command
{
	int					type;
	char				*arg[3];
	struct s_command	*next;
	struct s_labels		*labels;
	int					arg_num;
	size_t				label_size;
}						t_command;

typedef struct			s_parse
{
	int					line_num;
	char				*name;
	char				*comment;
	t_command			*list_cmd;
	t_labels			*labels;
	int					error;
	int					last_symbol;
	int32_t				size;
	uint8_t				*exec_code;
}						t_parse;

void	parse(char *file, t_parse *champ);
void	command_search(char *line, t_parse *champ, t_labels *labels);
void	label_search(char *line, t_parse *champ, int fd);
char	*skip_whitespace(char *line);
void	label_processing(char *line, int fd, t_parse *champ);
int		is_label(char *line);
char	*cut_label(char *str);
size_t	sizing(t_command *buff);
void	label_conversion(t_parse *champ);
void	to_asm_code(t_parse *champ);
void	write_bytecode_file(int fd, t_parse *champ);
void	mem_cpy(void *dst, void *src, int n);
char	*cut_comment(char *line);

#endif

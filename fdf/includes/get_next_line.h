/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:37:20 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 14:37:22 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# include <libc.h>
# include "libft.h"

typedef struct		s_file
{
	int				fd;
	char			*line;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
